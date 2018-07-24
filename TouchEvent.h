/*
 * TouchEvent.h
 *
 *  Created on: 22 Jul 2018
 *      Author: andrewcapon
 */

#ifndef TOUCHEVENT_H_
#define TOUCHEVENT_H_

#include "CAD.h"

class TouchEvent
{
public:
	TouchEvent(uint8_t	uTouchId);
	TouchEvent(uint8_t	uTouchId, int32_t nX, int32_t	nY, int32_t m_nInitialArea);
	virtual ~TouchEvent();

	void SetActive(bool bActive)
	{
		m_bActive = bActive;
	}

	bool GetActive(void)
	{
		return m_bActive;
	}

	uint8_t GetTouchId(void)
	{
		return m_uTouchId;
	}

	void SetX(int32_t nX)
	{
		m_nX = nX;
	}

	int32_t GetX(void)
	{
		return m_nX;
	}

	void SetY(int32_t nY)
	{
		m_nY = nY;
	}

	int32_t GetY(void)
	{
		return m_nY;
	}

	void SetInitialArea(int32_t nInitialArea)
	{
		m_nInitialArea = nInitialArea;
	}

	int32_t GetInitialArea(void)
	{
		return m_nInitialArea;
	}


private:
	uint8_t	m_uTouchId;
	bool		m_bActive;
	int32_t	m_nX;
	int32_t	m_nY;
	int32_t	m_nInitialArea;
};

#endif /* TOUCHEVENT_H_ */
