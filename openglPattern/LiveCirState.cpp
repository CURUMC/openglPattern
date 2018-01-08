#include "LiveCirState.h"
#include "OffCirState.h"
CirEffState * LiveCirState::changeState(CirEff & cir, ENUM_CIR_STATE state)
{
	if (state == ENUM_CIR_STATE::OFF)
	{
		return new OffCirState;

	}
	return nullptr;
};