#include "TitleScene.h"

#include <cassert>

TitleScene::TitleScene()
{
	welcome = EntityBase::Create()
		.AddGraphic("Assets/title.png", 100)
		.AddPosition(sf::Vector2f(400, 200))
		.AddControl({ sf::Keyboard::Space }, ToGameplayCallback, this)
		.AddText("Assets/NotoSans-Thin.ttf", "Hello World!", 200);
}


TitleScene::~TitleScene()
{
}

void TitleScene::Update(sf::Time delta_time)
{

}

void TitleScene::HandleCollision(EntityPtr collide, EntityPtr touched)
{

}

void TitleScene::ToGameplayCallback(EngineObject* object, const sf::Event& event)
{
	TitleScene* scene = dynamic_cast<TitleScene*>(object);
	assert(scene);
	if (!scene)
		return;

	scene->ToGameplay(event);
}

void TitleScene::ToGameplay(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
		current_operation = to_gameplay;
}
