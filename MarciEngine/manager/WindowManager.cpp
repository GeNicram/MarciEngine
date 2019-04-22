#include "WindowManager.h"

#include <SFML/Graphics.hpp>


WindowManager::WindowManager()
{
}


WindowManager::~WindowManager()
{
}

void WindowManager::ShowWindow(int width, int height, const std::string& title)
{
	window.create(sf::VideoMode(width, height), title.c_str());
}

sf::RenderWindow& WindowManager::GetWindow()
{
	return window;
}