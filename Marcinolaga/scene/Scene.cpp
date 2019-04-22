#include "Scene.h"

#include <EngineObject.h>
#include <entity/PositionComponent.h>
#include <entity/ScriptComponent.h>

#include <cassert>

Scene::Scene()
	: current_operation(working)
{
}


Scene::~Scene()
{
}

void Scene::UpdateCallback(EngineObject* object, sf::Time delta_time)
{
	Scene* scene = dynamic_cast<Scene*>(object);
	assert(scene);
	if (!scene)
		return;

	scene->Update(delta_time);
}

Scene::operation Scene::GetOperation()
{
	return current_operation;
}
