#pragma once
#include "GameObject.h"
class Spawner {
	CGameObject* prototype_;
public:
	Spawner(CGameObject* prototype):prototype_(prototype){}
	virtual ~Spawner() {
	}
	virtual CGameObject* spawnObject() { return prototype_->clone(); };
};