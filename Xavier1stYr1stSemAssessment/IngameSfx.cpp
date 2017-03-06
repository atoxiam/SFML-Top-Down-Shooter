

#include "IngameSfx.h"

//Sound
void IngameSound::LoadSoundBuffer(){

	bossDeathBuffer.loadFromFile("audio//bossDeath.ogg");
	bulletShotBuffer.loadFromFile("audio//bulletShot.ogg");
	enemyCollisionBuffer.loadFromFile("audio//enemyCollision.ogg");
	healthDropBuffer.loadFromFile("audio//healthDrop.ogg");
	playerCollisionBuffer.loadFromFile("audio//playerCollision.ogg");
	playerDeathBuffer.loadFromFile("audio//playerDeath.ogg");
	monkeyFartBuffer.loadFromFile("audio//fart.ogg");
	boomyBuffer.loadFromFile("audio//boomy.wav");
	bossy1HitBuffer.loadFromFile("audio//bossy1hit.ogg");
	camelBuffer.loadFromFile("audio//camel.wav");
	bossy3spawn.loadFromFile("audio//bossy3spawn.ogg");
	bossy3death.loadFromFile("audio//bossy3death.wav");
}

void IngameSound::setBuffer(int &volume){
	bossDeathSound.setBuffer(bossDeathBuffer);
		bossDeathSound.setVolume(volume);
	bulletShotSound.setBuffer(bulletShotBuffer);
		bulletShotSound.setVolume(volume);
	enemyCollisionSound.setBuffer(enemyCollisionBuffer);
		enemyCollisionSound.setVolume(volume);
	healthDropSound.setBuffer(healthDropBuffer);
		healthDropSound.setVolume(volume);
	playerCollisionSound.setBuffer(playerCollisionBuffer);
		playerCollisionSound.setVolume(volume);
	playerDeathSound.setBuffer(playerDeathBuffer);
		playerDeathSound.setVolume(volume);
	monkeyFartSound.setBuffer(monkeyFartBuffer);
		monkeyFartSound.setVolume(volume);
	pewSound.setBuffer(boomyBuffer);
		pewSound.setVolume(volume);
	bossy1HitSound.setBuffer(bossy1HitBuffer);
		bossy1HitSound.setVolume(volume);
	camelSound.setBuffer(camelBuffer);
		camelSound.setVolume(volume);
	bossy3spawnSound.setBuffer(bossy3spawn);
		bossy3spawnSound.setVolume(volume);
	bossy3deathSound.setBuffer(bossy3death);
		bossy3deathSound.setVolume(volume);
}

void IngameSound::PlaySound(std::string sound){
	if (sound == "bulletShot")
		bulletShotSound.play();
	
	else if (sound == "fart")
		monkeyFartSound.play();
	
	else if (sound == "enemyCollision")
		enemyCollisionSound.play();
	
	else if (sound == "playerCollision")
		playerCollisionSound.play();
	
	else if (sound == "bossDeath")
		bossDeathSound.play();
	
	else if (sound == "healthDrop")
		healthDropSound.play();
	
	else if (sound == "playerDeath")
		playerDeathSound.play();
	
	else if (sound == "pew")
		pewSound.play();
	
	else if (sound == "bossy1Hit")
		bossy1HitSound.play();
	
	else if (sound == "camel")
		camelSound.play();
	
	else if (sound == "bossy3spawn")
		bossy3spawnSound.play();
	
	else
		bossy3deathSound.play();
}
