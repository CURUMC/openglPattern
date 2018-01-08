#include "CirEff.h"
#include "PointEff.h"

CirEff::CirEff()
{
}


CirEff::~CirEff()
{
}

void CirEff::Init(const Point & pos)
{
	SetPos(pos);
	m_cirs.clear();

	m_off = false;
	m_ubColorS[0] = rand() % 50 + 70;
	m_ubColorS[1] = rand() % 170 + 70;
	m_ubColorS[2] = rand() % 170 + 70;
	m_ubColorE[0] = rand() % 90 + 10;
	m_ubColorE[1] = rand() % 80 + 10;
	m_ubColorE[2] = rand() % 80 + 10;

	m_maxtime = 75 + rand() % 40;
	m_fdet = 0;
	F_DET = 0.08f + (rand() % 5 + 1) / 20.f;
	m_time = 0;
	m_live = true;
}

void CirEff::Release()
{
	while (popback_PointEff());

}

void CirEff::Update()
{
	for ( auto&q : m_cirs) {
		q->Update();
	}

	if (m_off)
	{
		popback_PointEff();
		return;
	}

	Point tmp = m_ptPos;
	if (m_time < m_maxtime)
	{
		tmp += Point{ 0,int(rSIZE_DET*m_time) };
		m_fdet += F_DET;
		tmp.rotation(m_ptPos, m_fdet);

		pushback_PointEff(tmp);

	}
	else if (m_time == m_maxtime) {

		Point tmp2{ 0,int(rSIZE_DET*m_time) };
		tmp2.rotation(Point{ 0,0 }, m_fdet);
		tmp2 += tmp2;
		m_ptPos = (tmp + tmp2);
		m_fdet += PI;
	}
	else if (m_time < 2 * m_maxtime)
	{
		tmp += Point{ 0,int(rSIZE_DET*(m_maxtime - m_time%m_maxtime)) };
		m_fdet -= F_DET;
		tmp.rotation(m_ptPos, m_fdet);
		pushback_PointEff(tmp);

	}

	m_time++;



}

void CirEff::Draw() const
{
	for (const auto&q : m_cirs) {
		q->Draw();
	}

}

void CirEff::OffEff()
{
	m_off = true;
}

bool CirEff::isDie() const
{
	return !m_live;
}

void CirEff::pushback_PointEff(const Point & pos)
{
	auto pObj = new PointEff;
	pObj->SetColor(m_ubColorS, m_ubColorE);
	pObj->SetPos(pos);
	m_cirs.push_back(pObj);
}

bool CirEff::popback_PointEff()
{
	if (m_cirs.size())
	{
		delete m_cirs.back();
		m_cirs.pop_back();
		return true;

	}
	else
		return false;
}
