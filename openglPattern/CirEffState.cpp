#include "CirEffState.h"

CirEffState * OnCirState::changeState(CirEff & cir, ENUM_CIR_STATE state)
{
	if (state == ENUM_CIR_STATE::OFF)
	{
		return new OffCirState;

	}
	else if (state == ENUM_CIR_STATE::LIVE||out)
	{
		return new LiveCirState;

	};
	return nullptr;
};

CirEffState * OffCirState::changeState(CirEff & cir, ENUM_CIR_STATE state)
{

	if (state == ENUM_CIR_STATE::DIE || stateout) {
		return new DieCirState;
	}

	return nullptr;

};