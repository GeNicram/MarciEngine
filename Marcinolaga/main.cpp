#include "scene/CurrentScene.h"
#include "scene/GameplayScene.h"
#include "scene/TitleScene.h"
#include "scene/SummaryScene.h"

#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

#include <iostream>

void Scenes(EngineObject* object, sf::Time delta_time)
{
	if (CurrentScene::Get() == nullptr)
	{
		TitleScene* ts = new TitleScene();

		CurrentScene::Get().reset(ts);
		return;
	}

	switch (CurrentScene::Get()->GetOperation())
	{
		case Scene::working:
			break;
		case Scene::to_title:
		{
			TitleScene* ts = new TitleScene();
			CurrentScene::Get().reset(ts);

			return;
		}
		case Scene::to_gameplay:
		{
			GameplayScene* gs = new GameplayScene();
			gs->SetGameArea(sf::IntRect(10, 10, 790, 1270));

			CurrentScene::Get().reset(gs);
			return;
		}
		case Scene::to_summary:
		{
			SummaryScene* ss = new SummaryScene();
			CurrentScene::Get().reset(ss);

			return;
		}
	}
}

int main(int argc, char* argv[])
{
	me::Init();

	Entity scene_squencer = EntityBase::Create().AddScript(Scenes, nullptr);

	me::ShowWindow(1280, 800, "Marcinolaga");
	me::StartLoop();
}
