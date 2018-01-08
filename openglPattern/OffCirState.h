#pragma once
#include "CirEffState.h"
class OffCirState :public CirEffState {
public:
	virtual ~OffCirState() {};
	virtual void enter(CirEff& cir) override { };
	virtual CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state)override;
	virtual void update(CirEff& cir)override {

		if (!cir.popbackPointeff()) {
			cir.ChangeState(ENUM_CIR_STATE::DIE);
		}
	}
};
