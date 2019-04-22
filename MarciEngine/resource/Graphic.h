#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics.hpp>

class Graphic
{
public:
	Graphic();
	virtual ~Graphic();
	enum status { unknown, created, loading, cant_load, ready, remove };

	status GetStatus();
	virtual const sf::Drawable& GetDrawing(const sf::Transformable& transform) = 0;
	void Remove();
protected:
	status current_status;
};

