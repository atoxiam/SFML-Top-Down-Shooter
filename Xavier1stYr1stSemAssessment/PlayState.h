

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "Game.h"
#include "GameState.h"
#include "IngameSfx.h"
#include "IOstuff.h"
#include "BasicStuffIncludes.h"

#include "UpdateManager.h"
#include "RenderManager.h"
#include "SpawnManager.h"
#include "CollisionManager.h"
#include "MessageHandler.h"


class PlayState : public GameState{
public:
	PlayState();
	~PlayState();
	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);
	void ClearStuff();

private:
	void StartPause();
	void EndPause();
	void IncrementCounters();

	void HandleSpawns(Game &game);
	void HandleUpdates(Game &game);
	void HandleCollisions(Game &Game);
	void HandleDraws(Game &game);

	void CountersToNull();
	void UpdateHUD(sf::RenderWindow &window);

	//
	Player				player1;
	SpawnManager		spawnManager;
	WeaponManager		weapon;
	MessageHandler		messageHandler;
	MovableBackground	bg;
	Background			hud;
	IOsound				iosound;
	IngameSound			sound;
	Healthbar			hudHealth;
	GUIcircleShape		pewCD;
	Health				health;

	//SFML Stuff
	sf::Event pEvent;
	sf::Clock pClock;
	sf::Vector2i mousePos;

	//stringstream
	std::stringstream healthStream;
	std::stringstream pointStream;

	//vectors
	std::vector<Bullet>						bulletv;
	std::vector<DoubleShot>					dShotv;
	std::vector<Enemy>						enemyv;
	std::vector<EnemyFormation>				enemyFormationv;
	std::vector<doggo>				monkeyv;
	std::vector<bossy1>						bossy1v;
	std::vector<camel>						camelv;
	std::vector<bullets>				yesv;
	std::vector<bossy1Weapon>				b1Weaponv;
	std::vector<HealthDrop>					healthv;
	std::vector<UnlockBoomy>					UnlockBoomyv;
	std::vector<Boomy>						pewv;
	std::vector<Boomy>::iterator				pewIt;
	std::vector<bossy2>						bossy2v;
	std::vector<bossy2Weapon>				bossy2Weaponv;
	std::vector<bossy3>						bossy3v;
	std::vector<bossy3firstWeapon>			bossy3FWeaponv;
	std::vector<bossy3SecWeapon>				bossy3SWeaponv;

	//integer
	int volume;
	int playerHealth;
	int points = 0;
	int bulletTimeCount;
	int enemyTimeCount;
	int enemyFormationCount;
	int yesCount;
	int bossy1WeaponCount;
	int bossy2WeaponCount;
	int bossy3FirstWeaponCount1;
	int bossy3FirstWeaponCount2;
	int bossy3SecWeaponCount;
	int camelTimeCount;
	int healthDropCount;
	int randomX;
	int showLvUp;
	int damageChill;

	//float
	float bgSpeed = 0.3f;
	float elapsedTime;

	//bool
	bool paused			= false;
	bool bossy1Dead		= false;
	bool gotPew			= false;
	bool pewOnCooldown  = false;
	bool bossy3dead		= false;
};

#endif