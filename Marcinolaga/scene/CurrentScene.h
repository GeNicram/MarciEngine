#pragma once

#include <memory>

class Scene;

class CurrentScene
{
	CurrentScene();
public:
	CurrentScene(CurrentScene const&) = delete;
	void operator=(CurrentScene const&) = delete;
	~CurrentScene();
	static std::unique_ptr<Scene>& Get();
};

