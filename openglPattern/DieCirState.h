#pragma once
#include "CirEffState.h"
class DieCirState :public CirEffState {

public:
	virtual ~DieCirState() {};
	virtual void enter(CirEff& cir) override {
		cir.m_live = false;
	};
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override { return nullptr; };
	virtual void update(CirEff& cir)override {};
};