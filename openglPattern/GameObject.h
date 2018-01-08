#pragma once
#include "Point.h"

class CGameObject
{
public:
	Point m_ptPos;
	CGameObject();
	virtual ~CGameObject();
	void SetPos(const Point&pos) {
		m_ptPos = pos;
	}
	virtual void Draw() const = 0;
	virtual void Update() = 0;
	virtual CGameObject * clone() = 0;
};

