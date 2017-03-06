

#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H

#include <vector>

//own header
#include "EntityIncludes.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"
#include "WeaponManager.h"
#include <SFML\Graphics.hpp>

class SpawnManager{
public:
	void HealthDropSpawn(int &counter, std::vector<HealthDrop> &vector, int &randomX);

	//standard enemy spawns
	void EnemySpawn(int &counter, std::vector<Enemy> &vector, std::vector<EnemyFormation> &enemyFormationv, int &randomX);
	void EnemyFormationSpawn(int &counter, std::vector<EnemyFormation> &vector, std::vector<bossy2> &bossy2v);
	void camelSpawn(int &counter, std::vector<camel> &vector, int &randomX, IngameSound &sound);
	void doggoSpawn(int &points, std::vector<doggo> &vector, std::vector<bossy2> &bossV);
	void yesSpawn(int &counter, std::vector<doggo> &smVector, std::vector<bullets> &sVector, IngameSound &sound);

	//boss related spawns
	void bossy1Spawn(int &points, std::vector<bossy1> &vector);
	void bossy1WeaponSpawn(int &counter, std::vector<bossy1Weapon> &bwVector, std::vector<bossy1> &bVector, IngameSound &sound);
	void UnlockBoomySpawn(bool &bossy1Dead, std::vector<UnlockBoomy> &vector);

	void bossy2Spawn(std::vector<bossy2> &vector, int &points);
	void bossy2WeaponSpawn(int &counter, std::vector<bossy2Weapon> &bwvector, std::vector<bossy2> &bvector);

	void bossy3Spawn(std::vector<bossy3> &vector, int &points, IngameSound &sound);
	void bossy3FirstWeaponSpawn(int &counter1, int &counter2, std::vector<bossy3firstWeapon> &vector, std::vector<bossy3> &bVector, IngameSound &sound);
	void bossy3SecWeaponSpawn(int &counter, std::vector<bossy3SecWeapon> &vector, std::vector<bossy3> &bVector, IngameSound &sound);

	//weapon spawns
	void BulletSpawn(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window);
	void BulletSpawn2(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window);
	
	void DoubleShotSpawn(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window);
	void DoubleShotSpawn2(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window);
	
	void PewSpawn(std::vector<Boomy> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window);
	void PewSpawn2(std::vector<Boomy> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window);
};
#endif