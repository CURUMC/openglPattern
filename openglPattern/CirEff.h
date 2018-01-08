#pragma once
#include "GameObject.h"
#include "Çì´õ.h"
#include <list>
#define PI (3.14f)
#define rSIZE_DET (1)
class CirEffState;

class CirEff :
	public CGameObject
{
	CirEffState* m_state;

	std::list<CGameObject*> m_cirs;

public:
	virtual CGameObject * clone() override { return nullptr;};
	bool m_live{true};

	CirEff();
	virtual ~CirEff();

	void Release();
	void Init(const Point& pos);
	void Update();

	void Off();

	bool GetisDie() const;

	void ChangeState(ENUM_CIR_STATE dtateid);

	virtual void Draw() const;

	void addPointeff(CGameObject * pobj) {
		m_cirs.push_back(pobj);

	}
	bool popbackPointeff() {
		if (m_cirs.size())
		{
			delete m_cirs.back();
			m_cirs.pop_back();
			return true;

		}
		else
			return false;
	}
};

