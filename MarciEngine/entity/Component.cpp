#include "Component.h"

#include "Entity.h"

Component::Component(std::weak_ptr<Entity> owner)
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

std::weak_ptr<Entity> Component::GetOwner()
{
	return owner;
}
