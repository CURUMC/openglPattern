#include "PointEff.h"
#include "GL\glut.h"


PointEff::PointEff()
{
	m_fColordel = 0;
}

PointEff::~PointEff()
{
}

void PointEff::SetColor(GLubyte * ubCS, GLubyte * ubCE)
{
	if (ubCS)
		for (auto & q : m_ubColorS) {
			q = *(ubCS++);
		}

	if (ubCE)
		for (auto & q : m_ubColorE) {
			q = *(ubCE++);
		}
}

void PointEff::SetColorS(const GLubyte & r, const GLubyte & g, const GLubyte & b)
{
	m_ubColorS[0] = r;
	m_ubColorS[1] = g;
	m_ubColorS[2] = b;
}

void PointEff::SetColorE(const GLubyte & r, const GLubyte & g, const GLubyte & b)
{
	m_ubColorE[0] = r;
	m_ubColorE[1] = g;
	m_ubColorE[2] = b;
}

void PointEff::Update()
{
	m_fColordel += 0.01f;
	if (m_fColordel >= 1) {
		m_fColordel = 0;
		GLubyte tmp1=m_ubColorS[0];
		GLubyte tmp2=m_ubColorS[1];
		GLubyte tmp3=m_ubColorS[2];
		SetColor(m_ubColorE, nullptr);
		SetColorE(tmp1, tmp2, tmp3);
	}
}

void PointEff::Draw() const
{
	glBegin(GL_POLYGON);

	glColor3ub(

		m_ubColorS[0] * (1 - m_fColordel) + (m_ubColorE[0])*m_fColordel,
		m_ubColorS[1] * (1 - m_fColordel) + (m_ubColorE[1])*m_fColordel,
		m_ubColorS[2] * (1 - m_fColordel) + (m_ubColorE[2])*m_fColordel
	);

	int size = 2;
	glVertex2f(m_ptPos.x- size, m_ptPos.y- size);
	glVertex2f(m_ptPos.x + size, m_ptPos.y- size);
	glVertex2f(m_ptPos.x+ size, m_ptPos.y+ size);
	glVertex2f(m_ptPos.x- size, m_ptPos.y+ size);


	glEnd();

}

CGameObject * PointEff::clone()
{
	auto ptr = new PointEff();
	ptr->SetColor(m_ubColorE,m_ubColorS);
	return ptr;
}
