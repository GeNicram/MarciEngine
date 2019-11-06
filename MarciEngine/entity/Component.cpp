#include "Component.h"

#include "Entity.h"

Component::Component(Entity& owner)
	: owner(owner)
{
}

Component::~Component()
{
}

// void Component::UpdateOwner(Entity* new_owner)
// {
// 	owner = new_owner;
// }

bool Component::HasOwner()
{
	return !owner.expired();
}

Entity Component::GetOwner()
{
	return owner.lock();
}
