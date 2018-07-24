/*
 * TestHyperPixelTouchScreen.h
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */

#ifndef TESTHYPERPIXELTOUCHSCREEN_H_
#define TESTHYPERPIXELTOUCHSCREEN_H_

#include "ITouchEventHandler.h"

class TestHyperPixelTouchScreen : public ITouchEventHandler
{
public:
	TestHyperPixelTouchScreen();
	virtual ~TestHyperPixelTouchScreen();

	virtual void TouchBegin(TouchEvent &touchEvent);
	virtual void TouchEnd(TouchEvent &touchEvent);
	virtual void TouchMove(TouchEvent &touchEvent);

	void StartTest(void);

private:
	int32_t m_uMaxX = 0;
	int32_t m_uMaxY = 0;

};

#endif /* TESTHYPERPIXELTOUCHSCREEN_H_ */
