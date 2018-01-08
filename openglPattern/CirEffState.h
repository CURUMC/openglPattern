#pragma once 
#include "CirEff.h"
#include "PointEff.h"

class CirEffState
{
public:

	virtual ~CirEffState() {};
	virtual void enter(CirEff& cir) {};
	virtual void exit(CirEff& cir) {};
	virtual  CirEffState* changeState(CirEff& cir, ENUM_CIR_STATE state) { return nullptr; };
	virtual void update(CirEff& cir) {};
};