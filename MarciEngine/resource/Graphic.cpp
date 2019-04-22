#include "Graphic.h"

#include <SFML/Graphics.hpp>

Graphic::Graphic()
	: current_status(unknown)
{
}

Graphic::~Graphic()
{
}

Graphic::status Graphic::GetStatus()
{
	return current_status;
}

void Graphic::Remove()
{
	current_status = remove;
}
