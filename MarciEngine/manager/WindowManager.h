#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class WindowManager
{
public:
	WindowManager();
	~WindowManager();
	void ShowWindow(int width, int height, const std::string& title);
	sf::RenderWindow& GetWindow();
private:
	sf::RenderWindow window;
	unsigned int width;
	unsigned int height;
	std::string title;
};

