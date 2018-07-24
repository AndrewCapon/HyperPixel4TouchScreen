/*
 * HyperPixelTouchScreen.cpp
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/input.h>
#include <unistd.h>

#include "HyperPixelTouchScreen.h"

HyperPixelTouchScreen::HyperPixelTouchScreen(uint8_t uDeviceNum, bool bBlocking)
: m_uDeviceNum(uDeviceNum),
	m_bConnected(false),
	m_bBlocking(bBlocking),
	m_uCurrentSlot(0)
{
	// filename
	char *pszFilename;
	if(asprintf(&pszFilename, "/dev/input/event%d", uDeviceNum))
	{
		m_hFile = open(pszFilename, O_RDONLY);
		if(m_hFile >= 0)
		{
			int rc = ioctl(m_hFile, EVIOCGRAB, (void*)1);

			if (rc == 0)
			{
				ioctl(m_hFile, EVIOCGRAB, (void*)0);
				m_bConnected = true;
			}
			else
			{
				// failed to grab the file
				fprintf(stderr, "Device is grabbed by another process. Use \"fuser -v %s\" to find the process.\n", pszFilename);
			}
		}
		else
		{
			// failed to Open the file
			fprintf(stderr, "Failed to open %s\n", pszFilename);
		}

		free(pszFilename);
	}
	else
	{
		// failed to grab the file
		fprintf(stderr, "Internal Error: asprintf() failed, probably out of memory.\n");
	}
}

HyperPixelTouchScreen::~HyperPixelTouchScreen()
{
	if(m_hFile >= 0)
		close(m_hFile);
}


void HyperPixelTouchScreen::Process(ITouchEventHandler *pEventHandler)
{
	if(m_bConnected)
	{
		struct timeval timeout = {0,0};

		fd_set rdfs;
		FD_ZERO(&rdfs);
		FD_SET(m_hFile, &rdfs);

		struct timeval *pTimeout;
		if(m_bBlocking)
			pTimeout = NULL;
		else
			pTimeout = &timeout;

		if(select(m_hFile + 1, &rdfs, NULL, NULL, pTimeout) != 0)
		{
			size_t uBytesRead = read(m_hFile, m_events, sizeof(m_events));

			if(uBytesRead > sizeof(struct input_event))
			{
				uint8_t uEvents = uBytesRead / sizeof(struct input_event);
				for (uint8_t uEvent = 0; uEvent < uEvents; uEvent++)
				{
					struct input_event *pEvent = &(m_events[uEvent]);
					//printf("[%u] = (%u, %u) = %d\n", uEvent, m_events[uEvent].type, m_events[uEvent].code, m_events[uEvent].value);
					switch(pEvent->type)
					{
						case EV_SYN:
						{
							if(m_touchEvents[m_uCurrentSlot].GetActive())
								m_touchEventQueue.push(TouchQueueElement(tetTouchMove, m_touchEvents[m_uCurrentSlot]));

							// send all events
							while(!m_touchEventQueue.empty())
							{
								TouchQueueElement &tqElement = m_touchEventQueue.front();
								switch(tqElement.first)
								{
									case tetTouchBegin:
										pEventHandler->TouchBegin(tqElement.second);
									break;

									case tetTouchEnd:
										pEventHandler->TouchEnd(tqElement.second);
									break;

									case tetTouchMove:
										pEventHandler->TouchMove(tqElement.second);
									break;
								}
								m_touchEventQueue.pop();
							}
						}
						break;

						case EV_ABS:
						{
							switch(pEvent->code)
							{
								case ABS_MT_SLOT:
								{
									m_uCurrentSlot = pEvent->value;
									m_touchEventQueue.push(TouchQueueElement(tetTouchMove, m_touchEvents[m_uCurrentSlot]));
								}
								break;

								case ABS_MT_POSITION_X:
								{
									m_touchEvents[m_uCurrentSlot].SetX(pEvent->value);
								}
								break;

								case ABS_MT_POSITION_Y:
								{
									m_touchEvents[m_uCurrentSlot].SetY(pEvent->value);
								}
								break;

								case ABS_MT_TOUCH_MAJOR:
								{
									m_touchEvents[m_uCurrentSlot].SetInitialArea(pEvent->value);
								}
								break;

								case ABS_MT_TRACKING_ID:
								{
									if(pEvent->value == -1)
									{
										// end touch
										m_touchEvents[m_uCurrentSlot].SetActive(false);
										m_touchEventQueue.push(TouchQueueElement(tetTouchEnd, m_touchEvents[m_uCurrentSlot]));
									}
									else
									{
										// begin touch
										m_touchEvents[m_uCurrentSlot].SetActive(true);
										m_touchEventQueue.push(TouchQueueElement(tetTouchBegin, m_touchEvents[m_uCurrentSlot]));
									}
								}
								break;
							}
						}
					}

					//printf("Slot = %u\n", m_uCurrentSlot);
				}
			}
		}
	}
}

