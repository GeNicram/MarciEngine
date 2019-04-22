#include "MarciEngine.h"

#include "entity/Entity.h"
#include "entity/GraphicComponent.h"

#include "manager/Managers.h"
#include "manager/ControlManager.h"
#include "manager/CollideManager.h"
#include "manager/GraphicManager.h"
#include "manager/WindowManager.h"
#include "manager/PositionManager.h"
#include "manager/ScriptManager.h"

#include <SFML/Graphics.hpp>

WindowManager* window_manager;
ControlManager* control_manager;
CollideManager* collide_manager;
GraphicManager* graphic_manager;
PositionManager* position_manager;
ScriptManager* script_manager;

void me::Init()
{
	window_manager = &Managers::Get().window_manager;
	control_manager = &Managers::Get().control_manager;
	collide_manager = &Managers::Get().collide_manager;
	graphic_manager = &Managers::Get().graphic_manager;
	position_manager = &Managers::Get().position_manager;
	script_manager = &Managers::Get().script_manager;

}

void me::ShowWindow(int width, int height, const std::string& title)
{
	window_manager->ShowWindow(width, height, title);
	graphic_manager->SetTargetWindow(&window_manager->GetWindow());
}

void me::StartLoop()
{
	sf::Clock clock;

	while (window_manager->GetWindow().isOpen())
	{
		control_manager->HandleEvents(window_manager->GetWindow());

		window_manager->GetWindow().clear();
		script_manager->Execute(clock.restart());
		collide_manager->HandleCollisions();
		graphic_manager->Render();
		window_manager->GetWindow().display();

		// TODO: below operations can be a part of GC
		position_manager->Update();
		graphic_manager->ReleaseResources();
		control_manager->ReleaseBindings();
	}
}
