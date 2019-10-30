#include "Entity.h"

#include "ComponentTypes.h"
#include "EntityBuilder.h"

EntityBase::EntityBase()
	: abandon_components_after_delete(true)
{
}

EntityBase::EntityBase(EntityBase& other)
	: active(other.active)
	, components(other.components)
	, abandon_components_after_delete(true)
{
	UpdateComponentsOwner();
	other.abandon_components_after_delete = false;
}

EntityBase::EntityBase(EntityBase&& other)
	: active(other.active)
	, components(other.components)
	, abandon_components_after_delete(true)
{
	UpdateComponentsOwner();
	other.abandon_components_after_delete = false;
}

EntityBase& EntityBase::operator=(EntityBase&& other)
{
	active = other.active;
	components = other.components;
	abandon_components_after_delete = true;
	UpdateComponentsOwner();

	other.abandon_components_after_delete = false;

	return *this;
}

EntityBase& EntityBase::operator=(const EntityBase& other)
{
	active = other.active;
	components = other.components;
	abandon_components_after_delete = other.abandon_components_after_delete;
	UpdateComponentsOwner();


	return *this;
}

EntityBase::~EntityBase()
{
	if (abandon_components_after_delete)
		AbandonComponents();
}

EntityBuilder EntityBase::Create()
{
	return EntityBuilder{};
}

void EntityBase::Activate()
{
	active = true;
}

void EntityBase::Deactivate()
{
	active = false;
}

bool EntityBase::IsActive()
{
	return active;
}

void EntityBase::AddComponent(std::shared_ptr<Component> component)
{
	components.push_back(component);
}

std::vector<std::shared_ptr<Component>> EntityBase::GetComponents(component_type type)
{
	std::vector<std::shared_ptr<Component>> needed_components;

	for (auto& component : components)
	{
		if (component->GetType() == type)
			needed_components.push_back(component);
	}

	return needed_components;
}

std::shared_ptr<PositionComponent> EntityBase::GetPositionComponent()
{
	auto position = GetComponents(component_type::position);

	return std::dynamic_pointer_cast<PositionComponent>(position[0]);
}

void EntityBase::UpdateComponentsOwner()
{
	for (auto& component : components)
	{
		component->UpdateOwner(this);
	}
}

void EntityBase::AbandonComponents()
{
	for (auto& component : components)
	{
		component->UpdateOwner(nullptr);
	}
}
