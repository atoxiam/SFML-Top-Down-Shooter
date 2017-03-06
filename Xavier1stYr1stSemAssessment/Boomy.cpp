

#include "Boomy.h"

sf::Texture Boomy::pewShotTex;

Boomy::Boomy(float playerPosX, float playerPosY, sf::RenderWindow& window){
	speed = 0.9f;
	m_active = true;
	m_isPew = true;

	//set direction up
	dirX = sf::Mouse::getPosition(window).x - playerPosX;
	dirY = sf::Mouse::getPosition(window).y - playerPosY;
	dir = sqrt((dirX*dirX) + (dirY*dirY));

	//get direction vector and normalize it
	_direction.x = sf::Mouse::getPosition(window).x - playerPosX;
	_direction.y = sf::Mouse::getPosition(window).y - playerPosY;
	_direction = normalize(_direction);

	pewShotTex.loadFromFile("graphics/weapons/pew.png");

	pewShotTex.setSmooth(false);
	sprite.setTexture(pewShotTex);
}

void Boomy::Update(float elapsedTime){
	if (m_active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		sprite.move(_direction * elapsedTime);
		if (y < 0 || y > 900 || x < 0 || x > 900){
			m_active = false;
		}
	}

}

void Boomy::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(sprite);
}

void Boomy::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

int Boomy::getDamage(){
	return 20;
}

sf::Vector2f Boomy::normalize(sf::Vector2f& source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0.0f){
		return sf::Vector2f(source.x / length, source.y / length);
	}
	else
		return source;
}
//sets the entity active or inactive
void Boomy::setActiveBool(bool active){
	m_active = active;
}
