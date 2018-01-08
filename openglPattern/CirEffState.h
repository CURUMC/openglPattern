#pragma once 
#include "CirEff.h"
class OnCirState;
class OffCirState;
class LiveCirState;
class DieCirState;

class CirEffState
{
public:

	virtual ~CirEffState() {};
	virtual void enter(CirEff& cir) {};
	virtual  CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state) { return nullptr; };
	virtual void update(CirEff& cir) {};
};

class OnCirState :public CirEffState {
	float F_DET;
	float m_fdet;
	time_t m_time{ 0 };
	time_t m_maxtime;
	Point m_ptPos;
	bool out{ false };
public:
	virtual ~OnCirState() {};
	virtual void enter(CirEff& cir) override {
		m_maxtime = 75 + rand() % 40;
		m_fdet = 0;
		F_DET = 0.08f + (rand() % 5 + 1) / 20.f;
		m_time = 0;
		m_ptPos = cir.m_ptPos;
		out = false;
		cir.m_live = true;
	}; 
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state) override;
	virtual void update(CirEff& cir)override {
		Point tmp = m_ptPos;
		if (m_time < m_maxtime)
		{
			tmp += Point{ 0,int(rSIZE_DET*m_time) };
			m_fdet += F_DET;
			tmp.rotation(m_ptPos, m_fdet);
			cir.addPointeff(tmp);

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
			cir.addPointeff(tmp);

		}
		else
			out = true;
		m_time++;
	};

};

class OffCirState :public CirEffState {
	bool stateout{ false };
public:
	virtual ~OffCirState() {};
	virtual void enter(CirEff& cir) override { stateout = false; };
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override;
	virtual void update(CirEff& cir)override {

		if (!cir.popbackPointeff()) {
			//cir.ChangeState(Cir8State::die);
			stateout = true;
		}
	}
};

class LiveCirState :public CirEffState {

public:
	virtual ~LiveCirState() {};
	virtual void enter(CirEff& cir) override {};
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override { return nullptr; };
	virtual void update(CirEff& cir)override {};
};

class DieCirState :public CirEffState {

public:
	virtual ~DieCirState() {};
	virtual void enter(CirEff& cir) override {
	
		cir.m_live = false;
	};
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override { return nullptr; };
	virtual void update(CirEff& cir)override {};
};