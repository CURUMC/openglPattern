#include "OffCirState.h"
#include "DieCirState.h"
CirEffState * OffCirState::changeState(CirEff & cir, ENUM_CIR_STATE state)
{

	if (state == ENUM_CIR_STATE::DIE) {
		return new DieCirState;
	}

	return nullptr;

};