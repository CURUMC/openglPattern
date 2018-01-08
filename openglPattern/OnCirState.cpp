#include "OnCirState.h"
#include "Spawner.h"
#include "OffCirState.h"
#include "LiveCirState.h"

void OnCirState::enter(CirEff & cir)
{
	cspoint_prototype.SetColorS(rand() % 50 + 70, rand() % 170 + 70, rand() % 170 + 70);
	cspoint_prototype.SetColorE(rand() % 90 + 10, rand() % 80 + 10, rand() % 80 + 10);
	cspointSpawner = new Spawner(&cspoint_prototype);
	m_maxtime = 75 + rand() % 40;
	m_fdet = 0;
	F_DET = 0.08f + (rand() % 5 + 1) / 20.f;
	m_time = 0;
	m_ptPos = cir.m_ptPos;
	cir.m_live = true;
}
void OnCirState::exit(CirEff & cir)
{
	delete cspointSpawner;
};

CirEffState * OnCirState::changeState(CirEff & cir, ENUM_CIR_STATE state)
{
	if (state == ENUM_CIR_STATE::OFF)
	{
		return new OffCirState;

	}
	else if (state == ENUM_CIR_STATE::LIVE)
	{
		return new LiveCirState;

	};
	return nullptr;
}
void OnCirState::update(CirEff & cir)
{
	Point tmp = m_ptPos;
	if (m_time < m_maxtime)
	{
		tmp += Point{ 0,int(rSIZE_DET*m_time) };
		m_fdet += F_DET;
		tmp.rotation(m_ptPos, m_fdet);

		auto copyObj = cspointSpawner->spawnObject();
		copyObj->SetPos(tmp);
		cir.addPointeff(copyObj);

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
		auto copyObj = cspointSpawner->spawnObject();
		copyObj->SetPos(tmp);
		cir.addPointeff(copyObj);

	}
	else
	{
		cir.ChangeState(ENUM_CIR_STATE::LIVE);
		return;
	}
	m_time++;
};
