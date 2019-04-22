#pragma once
#include "Component.h"

#include "Entity.h"

class SpawnComponent :
	public Component
{
public:
	SpawnComponent(Entity& owner);
	~SpawnComponent();
};

