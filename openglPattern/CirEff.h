#pragma once
#include "GameObject.h"
#include "SPoint.h"
#include "Çì´õ.h"
#include "Spawner.h"
#include <list>
#define PI (3.14f)
#define rSIZE_DET (1)
class CirEffState;

class CirEff :
	public CGameObject
{
	CirEffState* m_state;

	std::list<CGameObject*> m_cirs;
	CSPoint cspoint_prototype;

	Spawner* cspointSpawner = new Spawner(&cspoint_prototype);

public:
	virtual CGameObject * clone() override { return nullptr;};
	bool m_live{true};

	CirEff();
	virtual ~CirEff();

	void Init(const Point& pos);
	void Update();

	void Off();

	bool GetisDie() const;

	void ChangeState(ENUM_CIR_STATE dtateid);

	virtual void Draw() const;

	void addPointeff(Point pos) {
		m_cirs.push_back(cspointSpawner->spawnObject());
	//	m_cirs.emplace_back();
		m_cirs.back()->SetPos(pos);
	//	m_cirs.back().SetColor(ubCS, ubCE);

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

