/*
 * ITouchEventHandler.h
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */

#ifndef ITOUCHEVENTHANDLER_H_
#define ITOUCHEVENTHANDLER_H_

#include "TouchEvent.h"

class ITouchEventHandler
{
public:
	ITouchEventHandler();
	virtual ~ITouchEventHandler();

	virtual void TouchBegin(TouchEvent &touchEvent) = 0;
	virtual void TouchEnd(TouchEvent &touchEvent) = 0;
	virtual void TouchMove(TouchEvent &touchEvent) = 0;
};

#endif /* ITOUCHEVENTHANDLER_H_ */
