/*
 * TouchEvent.cpp
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */

#include "TouchEvent.h"

TouchEvent::TouchEvent(uint8_t	uTouchId)
: m_uTouchId(uTouchId), m_bActive(false), m_nX(0), m_nY(0), m_nInitialArea(0)
{
}

TouchEvent::TouchEvent(uint8_t	uTouchId, int32_t nX, int32_t	nY, int32_t nInitialArea)
: m_uTouchId(uTouchId), m_bActive(false), m_nX(nX), m_nY(nY), m_nInitialArea(nInitialArea)
{
}

TouchEvent::~TouchEvent()
{
}

