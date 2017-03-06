

#ifndef INGAMESFX_H
#define INGAMESFX_H

#include <SFML/Audio.hpp>
#include <string>

class IngameSound{
public:

	void LoadSoundBuffer();
	void setBuffer(int &volume);
	void PlaySound(std::string sound);

private:

	sf::SoundBuffer bossDeathBuffer;
	sf::SoundBuffer bulletShotBuffer;
	sf::SoundBuffer enemyCollisionBuffer;
	sf::SoundBuffer healthDropBuffer;
	sf::SoundBuffer playerCollisionBuffer;
	sf::SoundBuffer playerDeathBuffer;
	sf::SoundBuffer doggobarkBuffer;
	sf::SoundBuffer boomyBuffer;
	sf::SoundBuffer bossy1HitBuffer;
	sf::SoundBuffer camelBuffer;
	sf::SoundBuffer bossy3spawn;
	sf::SoundBuffer bossy3death;

	sf::Sound bossDeathSound;
	sf::Sound bulletShotSound;
	sf::Sound enemyCollisionSound;
	sf::Sound healthDropSound;
	sf::Sound playerCollisionSound;
	sf::Sound playerDeathSound;
	sf::Sound doggobarkSound;
	sf::Sound pewSound;
	sf::Sound bossy1HitSound;
	sf::Sound camelSound;
	sf::Sound bossy3spawnSound;
	sf::Sound bossy3deathSound;
};

#endif