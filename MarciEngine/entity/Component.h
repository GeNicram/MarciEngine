#pragma once

#include "../EngineObject.h"
#include "ComponentTypes.h"

#include <memory>

class Entity;

class Component : public EngineObject
{
public:
	typedef unsigned int uid;
	Component(std::weak_ptr<Entity> owner);
	~Component();
	// possible no more needed
	//void UpdateOwner(Entity new_owner);
	bool HasOwner();
	std::weak_ptr<Entity> GetOwner();

	virtual component_type GetType() = 0;
protected:
	std::weak_ptr<Entity> owner;
};

