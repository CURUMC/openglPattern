#pragma once
#include "CirEffState.h"

class LiveCirState :public CirEffState {

public:
	virtual ~LiveCirState() {};
	virtual void enter(CirEff& cir) override {};
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override;
	virtual void update(CirEff& cir)override {
	};
};