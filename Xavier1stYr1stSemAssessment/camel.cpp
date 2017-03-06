

#include "camel.h"

sf::Texture camel::camelTex;

camel::camel(){
	IOdiff diff;
	IOsmooth smooth;
	hasTargetTexture = false;
	speed = 0.5 *diff.ReadDiffSettings();
	m_active = true;
	damage = 25;

	camelTex.loadFromFile("graphics/enemies/camel.png");
	camelTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(camelTex);
	sprite.setOrigin(0, 300);
}

void camel::Update(sf::RenderWindow &window, float elapsedTime){
	if (m_active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y * 1.5){
			if (y <= window.getSize().y / 4)
				y += (speed / 4) * elapsedTime;
			
			else
				y += speed * elapsedTime;
		}
		else if (y >= window.getSize().y * 1.5)
			m_active = false;
		
		sprite.setPosition(x, y);
	}
}

void camel::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(sprite);
}

void camel::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

int camel::getDamage(){
	return damage;
}

//sets the entity active or inactive
void camel::setActiveBool(bool active){
	m_active = active;
}