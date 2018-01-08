#pragma once
#include "CirEffState.h"
class Spawner;
class OnCirState :public CirEffState {
	float F_DET;
	float m_fdet;
	time_t m_time{ 0 };
	time_t m_maxtime;
	Point m_ptPos;

	PointEff cspoint_prototype;

	Spawner* cspointSpawner;
public:
	virtual ~OnCirState() {};
	virtual void enter(CirEff& cir) override;
	virtual void exit(CirEff& cir) override;
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state) override;
	virtual void update(CirEff& cir)override;

};
