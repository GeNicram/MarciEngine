#include "Managers.h"



Managers::Managers()
{
}


Managers::~Managers()
{
}

Managers& Managers::Get()
{
	static Managers manager;
	return manager;
}
