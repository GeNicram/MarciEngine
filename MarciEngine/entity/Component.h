#pragma once

#include "../EngineObject.h"
#include "ComponentTypes.h"

class Entity;

class Component : public EngineObject
{
public:
	typedef unsigned int uid;
	Component(Entity& owner);
	~Component();
	void UpdateOwner(Entity* new_owner);
	bool HasOwner();
	Entity* GetOwner();

	virtual component_type GetType() = 0;
protected:
	Entity* owner;
};

