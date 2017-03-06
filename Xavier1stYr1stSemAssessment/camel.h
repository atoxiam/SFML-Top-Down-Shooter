//camel.h

#ifndef camel_H
#define camel_H

#include <SFML/Graphics.hpp>
#include "IOstuff.h"

class camel{
public:
	camel();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void setPosition(float x, float y);
	void setActiveBool(bool active);

	//getter
	int getDamage();
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	float speed;
	static sf::Texture camelTex;
	int damage;
	bool hasTargetTexture;
	bool m_active;			///< if this is true-> it is active
};

#endif