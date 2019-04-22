#pragma once

#include "WindowManager.h"
#include "ControlManager.h"
#include "CollideManager.h"
#include "GraphicManager.h"
#include "PositionManager.h"
#include "ScriptManager.h"

class Managers
{
public:
	~Managers();

	WindowManager window_manager;
	ControlManager control_manager;
	CollideManager collide_manager;
	GraphicManager graphic_manager;
	PositionManager position_manager;
	ScriptManager script_manager;

	static Managers& Get();
private:
	Managers();
    Managers(Managers const&);
	void operator=(Managers const&);
};

