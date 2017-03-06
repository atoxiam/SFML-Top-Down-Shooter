
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>
#include "EntityIncludes.h"
#include "HighscoreManager.h"
#include "IngameSfx.h"
#include "Collision.h"

namespace CollisionManager{
	template <class C>
	
	void WeaponToEnemy(std::vector<C> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<doggo> &monkeyv, std::vector<bullets> &yesv, std::vector<bossy1> &bossy1v, bool &bossy1Dead, std::vector<bossy2Weapon> &bossy2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<bossy3> &bossy3v, std::vector<bossy3firstWeapon> &b3FWeapon, std::vector<bossy3SecWeapon> &b3SWeapon, bool &bossy3dead, sf::RenderWindow &window){
		for (auto it = vector.begin(); it != vector.end();){
			if (!it->getActiveBool())
				it = vector.erase(it);

			else{
				coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
				coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
				coll::ProjectileToListNoHealth(it, yesv, points, sound, highscore);//Boulder
				coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
				coll::BossCollision(it, bossy1v, points, sound, highscore, bossy1Dead);//bossy1
				coll::ProjectileToListNoHealth(it, bossy2weaponv, points, sound, highscore);//bossy2Weapon
				coll::bossy3Collision(bossy3v, it, sound, highscore, points, bossy3dead);//bossy3
				coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//bossy3FirstWeapon
				coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//bossy3SecWeapon

				++it;
			}
		}
	}

	template <class C>
	/**
	For Pew 
	**/
	void PewToEnemy(std::vector<C> &vector, int &points, IngameSound &sound, HighscoreManager &highscore, std::vector<Enemy> &enemyv, std::vector<doggo> &monkeyv, std::vector<bullets> &yesv, std::vector<bossy1> &bossy1v, std::vector<bossy2> &bossy2v, std::vector<bossy2Weapon> &bossy2weaponv, std::vector<EnemyFormation> &enemyFormationv, std::vector<bossy3> &bossy3v, std::vector<bossy3firstWeapon> &b3FWeapon, std::vector<bossy3SecWeapon> &b3SWeapon, bool &bossy3dead, sf::RenderWindow &window){
		for (auto it = vector.begin(); it != vector.end();){
			if (!it->getActiveBool())
				it = vector.erase(it);

			else{
				coll::ProjectileToList(it, enemyv, points, sound, highscore);//enemy
				coll::ProjectileToMonkey(it, monkeyv, points, sound, highscore);//monkey
				coll::ProjectileToListNoHealth(it, yesv, points, sound, highscore);//yes
				coll::ProjectileToList(it, enemyFormationv, points, sound, highscore);//enemyFormation
				coll::bossy2Collision(it, bossy2v, points, sound, highscore);//bossy2
				coll::ProjectileToListNoHealth(it, bossy2weaponv, points, sound, highscore);//bossy2Weapon
				coll::bossy3Collision(bossy3v, it, sound, highscore, points, bossy3dead);//bossy3
				coll::ProjectileToListNoHealth(it, b3FWeapon, points, sound, highscore);//bossy3FirstWeapon
				coll::ProjectileToList(it, b3SWeapon, points, sound, highscore);//bossy3SecWeapon

				++it;
			}
		}
	}
}
#endif