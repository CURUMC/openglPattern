#pragma once
#include "GameObject.h"
#include "GL\glut.h"
class PointEff :
	public CGameObject
{
protected:
	GLubyte m_ubColorS[3];
	GLubyte m_ubColorE[3];
	float m_fColordel;


public:
	PointEff();
	virtual ~PointEff();

	void Init(const Point& pos) {
		SetPos(pos);
	}

	void SetColor(GLubyte* ubCS, GLubyte* ubCE);
	void SetColorS(const GLubyte& r, const GLubyte& g, const GLubyte& b);
	void SetColorE(const GLubyte& r, const GLubyte& g, const GLubyte& b);

	virtual void Update() override;


	virtual void Draw() const;

	virtual CGameObject * clone() override;
};

