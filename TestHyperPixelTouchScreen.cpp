/*
 * TestHyperPixelTouchScreen.cpp
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */
#include <unistd.h>

#include "TestHyperPixelTouchScreen.h"
#include "HyperPixelTouchScreen.h"

TestHyperPixelTouchScreen::TestHyperPixelTouchScreen()
{
}

TestHyperPixelTouchScreen::~TestHyperPixelTouchScreen()
{
}

void TestHyperPixelTouchScreen::TouchBegin(TouchEvent &touchEvent)
{
	printf("TouchBegin(%u)(%d) = (%d, %d)\n", touchEvent.GetTouchId(), touchEvent.GetInitialArea(), touchEvent.GetX(), touchEvent.GetY());
}

void TestHyperPixelTouchScreen::TouchEnd(TouchEvent &touchEvent)
{
	printf("TouchEnd(%u)(%d) = (%d, %d)\n", touchEvent.GetTouchId(), touchEvent.GetInitialArea(), touchEvent.GetX(), touchEvent.GetY());
}

void TestHyperPixelTouchScreen::TouchMove(TouchEvent &touchEvent)
{
	printf("TouchMove(%u)(%d) = (%d, %d)\n", touchEvent.GetTouchId(), touchEvent.GetInitialArea(), touchEvent.GetX(), touchEvent.GetY());
}

void TestHyperPixelTouchScreen::StartTest(void)
{
	HyperPixelTouchScreen touchScreen(0, true);

	if(touchScreen.IsConnected())
		for(;;)
		{
			touchScreen.Process(this);
			usleep(1000);
		}
}
