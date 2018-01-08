#include "SPoint.h"
#include <GL\glut.h>
#include <random>


CSPoint::CSPoint()
{
	m_fColordel = 0;
}

CSPoint::~CSPoint()
{
}

void CSPoint::SetColor(GLubyte * ubCS, GLubyte * ubCE)
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

void CSPoint::SetColorS(const GLubyte & r, const GLubyte & g, const GLubyte & b)
{
	m_ubColorS[0] = r;
	m_ubColorS[1] = g;
	m_ubColorS[2] = b;
}

void CSPoint::SetColorE(const GLubyte & r, const GLubyte & g, const GLubyte & b)
{
	m_ubColorE[0] = r;
	m_ubColorE[1] = g;
	m_ubColorE[2] = b;
}

void CSPoint::Update()
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

void CSPoint::Draw() const
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

CGameObject * CSPoint::clone()
{
	auto ptr = new CSPoint();
	ptr->SetColor(m_ubColorS, m_ubColorE);
	return ptr;
}
