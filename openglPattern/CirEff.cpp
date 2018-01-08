#include "CirEff.h"
#include"CirEffState.h"


CirEff::CirEff()
{
}


CirEff::~CirEff()
{
	delete cspointSpawner;
}

void CirEff::Init(const Point & pos)
{
	SetPos(pos);
	m_cirs.clear();
	m_state = new OnCirState; m_state->enter(*this);
	cspoint_prototype.SetColorS(rand() % 50 + 70, rand() % 170 + 70, rand() % 170 + 70);
	cspoint_prototype.SetColorE(rand() % 90 + 10, rand() % 80 + 10, rand() % 80 + 10);

}

void CirEff::Update()
{

	if (m_state)
		m_state->update(*this);

	for ( auto&q : m_cirs) {
		q->Update();
	}


}

void CirEff::Off()
{
	ChangeState(ENUM_CIR_STATE::OFF);
}

bool CirEff::GetisDie() const
{
	return !m_live;
}

void CirEff::ChangeState(ENUM_CIR_STATE dtateid)
{
	auto state = m_state->changeState(*this, dtateid);

	if (state) {
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}
void CirEff::Draw() const
{
	for (const auto&q : m_cirs) {
		q->Draw();
	}

}
