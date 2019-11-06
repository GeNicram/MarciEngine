#pragma once

#include "../EngineObject.h"
#include "../EngineTypes.h"
#include "ComponentTypes.h"

#include <memory>

class EntityBase;

class Component : public EngineObject
{
public:
	typedef unsigned int uid;
	Component(Entity& owner);
	~Component();
	// possible no more needed
	//void UpdateOwner(Entity new_owner);
	bool HasOwner();
	Entity GetOwner();

	virtual component_type GetType() = 0;
protected:
	EntityPtr owner;
};

