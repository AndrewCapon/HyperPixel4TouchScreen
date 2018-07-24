/*
 * HyperPixelTouchScreen.h
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */

#ifndef HYPERPIXELTOUCHSCREEN_H_
#define HYPERPIXELTOUCHSCREEN_H_

#include <linux/input.h>
#include <queue>

#include "CAD.h"
#include "ITouchEventHandler.h"

class HyperPixelTouchScreen
{
public:
	typedef enum _TouchEventType
	{
		tetTouchBegin,
		tetTouchMove,
		tetTouchEnd
	} TouchEventType;

	typedef std::pair<TouchEventType, TouchEvent &> TouchQueueElement;
	typedef std::queue<TouchQueueElement>						TouchQueue;

	HyperPixelTouchScreen(uint8_t uDeviceNum, bool bBlocking);
	virtual ~HyperPixelTouchScreen();


	bool IsConnected(void)
	{
		return m_bConnected;
	}

	void Process(ITouchEventHandler *pEventHandler);

private:
	uint8_t 								m_uDeviceNum;
	bool										m_bConnected;
	int											m_hFile;
	bool										m_bBlocking;
	struct input_event 			m_events[64];
	int32_t									m_uCurrentSlot;

	static const uint8_t 	  c_uMaxTouches = 5;
	TouchEvent 							m_touchEvents[c_uMaxTouches] = { TouchEvent(1), TouchEvent(2), TouchEvent(3), TouchEvent(4), TouchEvent(5)};

	TouchQueue							m_touchEventQueue;
};

#endif /* HYPERPIXELTOUCHSCREEN_H_ */
