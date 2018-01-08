#pragma once
#include <list>
#include "GL\glut.h"
#include "GameObject.h"
#define PI (3.14f)
#define rSIZE_DET (1)

class CirEff :
	public CGameObject
{

	float F_DET;
	float m_fdet;
	time_t m_time{ 0 };
	time_t m_maxtime;

	GLubyte m_ubColorS[3];
	GLubyte m_ubColorE[3];

	std::list<CGameObject*> m_cirs;

	bool m_off{ false };
	bool m_live{ true };

public:

	CirEff();
	virtual ~CirEff();

	void Init(const Point& pos);
	void Release();
	virtual void Update() override;
	virtual void Draw() const override;

	void OffEff();
	bool isDie() const;

private:
	void pushback_PointEff(const Point& pos);

	bool popback_PointEff();
};

