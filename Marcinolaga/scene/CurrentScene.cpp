#include "CurrentScene.h"

#include "Scene.h"

CurrentScene::CurrentScene()
{
}


CurrentScene::~CurrentScene()
{
}

std::unique_ptr<Scene>& CurrentScene::Get()
{
	static std::unique_ptr<Scene> scene;
	return scene;
}
