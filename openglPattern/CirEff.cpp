#include "CirEff.h"
#include"CirEffState.h"
#include "OnCirState.h"

CirEff::CirEff()
{
}


CirEff::~CirEff()
{
}

void CirEff::Release()
{
	while (popbackPointeff());
	if (m_state)
	{
		m_state->exit(*this);  delete m_state;
	}
}

void CirEff::Init(const Point & pos)
{
	SetPos(pos);
	m_cirs.clear();
	m_state = new OnCirState; m_state->enter(*this);

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
		if (m_state)
		{
			m_state->exit(*this);  delete m_state;
		}
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
