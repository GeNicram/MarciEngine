#include "Entity.h"

#include "ComponentTypes.h"
#include "EntityBuilder.h"

Entity::Entity()
	: abandon_components_after_delete(true)
{
}

Entity::Entity(Entity& other)
	: active(other.active)
	, components(other.components)
	, abandon_components_after_delete(true)
{
	UpdateComponentsOwner();
	other.abandon_components_after_delete = false;
}

Entity::Entity(Entity&& other)
	: active(other.active)
	, components(other.components)
	, abandon_components_after_delete(true)
{
	UpdateComponentsOwner();
	other.abandon_components_after_delete = false;
}

Entity& Entity::operator=(Entity&& other)
{
	active = other.active;
	components = other.components;
	abandon_components_after_delete = true;
	UpdateComponentsOwner();

	other.abandon_components_after_delete = false;

	return *this;
}

Entity& Entity::operator=(const Entity& other)
{
	active = other.active;
	components = other.components;
	abandon_components_after_delete = other.abandon_components_after_delete;
	UpdateComponentsOwner();


	return *this;
}

Entity::~Entity()
{
	if (abandon_components_after_delete)
		AbandonComponents();
}

EntityBuilder Entity::Create()
{
	return EntityBuilder{};
}

void Entity::Activate()
{
	active = true;
}

void Entity::Deactivate()
{
	active = false;
}

bool Entity::IsActive()
{
	return active;
}

void Entity::AddComponent(std::shared_ptr<Component> component)
{
	components.push_back(component);
}

std::vector<std::shared_ptr<Component>> Entity::GetComponents(component_type type)
{
	std::vector<std::shared_ptr<Component>> needed_components;

	for (auto& component : components)
	{
		if (component->GetType() == type)
			needed_components.push_back(component);
	}

	return needed_components;
}

std::shared_ptr<PositionComponent> Entity::GetPositionComponent()
{
	auto position = GetComponents(component_type::position);

	return std::dynamic_pointer_cast<PositionComponent>(position[0]);
}

void Entity::UpdateComponentsOwner()
{
	for (auto& component : components)
	{
		component->UpdateOwner(this);
	}
}

void Entity::AbandonComponents()
{
	for (auto& component : components)
	{
		component->UpdateOwner(nullptr);
	}
}
