

#include "PlayState.h"

PlayState::PlayState(){
	CountersToNull();
	mousePos.x = 0;
	mousePos.y = 0;

	//sound & music
	iosound.ReadSoundSettings(volume);
	sound.LoadSoundBuffer();
	sound.setBuffer(volume);

	//background and HUD
	bg.setStuff("graphics/core//background.jpg", sf::Vector2f(800, 600));
	hud.setFilePath("graphics/core//hud.png");
	bgSpeed = 0.3f;
	health.setPosition(0, 12.5);

	playerHealth = player1.getHealth();

	//unlock pew
	bossy1Dead = false;
	gotPew = false;
	pewOnCooldown = false;
}

PlayState::~PlayState(){
}

void PlayState::HandleEvents(Game &game){
	sf::Event pEvent;
	while (game.window.pollEvent(pEvent))	{
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);

		if (pEvent.type == sf::Event::KeyPressed){
			if (pEvent.key.code == sf::Keyboard::Escape){
				if (!paused)
					StartPause();
				else 
					game.ChangeState(Game::gameStates::MAINMENU);
			}
	
			if (pEvent.key.code == sf::Keyboard::Return && paused)
				EndPause();
		}
	}
}

void PlayState::Update(Game &game){

	//always set the mouse position
	mousePos = sf::Mouse::getPosition(game.window);

	if (paused)
		pClock.restart();

	if (!paused){
		//Handle everything
		HandleSpawns(game);
		HandleUpdates(game);
		HandleCollisions(game);

		//health & points into string
		playerHealth = player1.getHealth();
		messageHandler.UpdateStream(healthStream, playerHealth, "pHealthS");
		messageHandler.UpdateStream(pointStream, points, "");
	}
}

void PlayState::Render(Game &game){
	bg.Render(game.window);

	if (player1.getActiveBool())
		if (!paused)
			HandleDraws(game);

		if (paused){
			messageHandler.Render(game.window, "pauseText");
			messageHandler.Render(game.window, "pausedInfo");
		}

	//draw HUD
	hudHealth.Render(game.window);
	hud.Render(game.window);
	messageHandler.Render(game.window, "pHealthS");
	health.Render(game.window);
	messageHandler.Render(game.window, "");
	weapon.Render(game.window);

	//new Weapon draw
	messageHandler.UpdatelvUp(points, showLvUp, game.window, elapsedTime);

	//draw Pew cooldown
	if (gotPew && player1.getActiveBool()){
		pewCD.Render(game.window);
	}

	//Game over 
	if (!player1.getActiveBool()){
		game.highscore.setPoints(points);
		messageHandler.Render(game.window, "gameOver");

		game.window.display();
		ClearStuff();
		sf::sleep(sf::seconds(1));
		game.ChangeState(Game::gameStates::HIGHSCORE);
	}
}

void PlayState::ClearStuff(){
	points = 0;

	//restart counters
	enemyTimeCount = 0;
	bulletTimeCount = 0;
	yesCount = 0;
	bossy1WeaponCount = 0;
	bossy2WeaponCount = 0;
	healthDropCount = 0;
	camelTimeCount = 0;
	damageChill = 0;
	enemyFormationCount = 0;
	bossy3FirstWeaponCount1 = 0;
	bossy3FirstWeaponCount2 = 0;
	bossy3SecWeaponCount = 0;

	//clear vectors
	healthv.clear();
	enemyv.clear();
	doggov.clear();
	yesv.clear();
	bossy1v.clear();
	camelv.clear();
	bossy2v.clear();
	bossy2Weaponv.clear();
	enemyFormationv.clear();
	bossy3v.clear();
	bossy3FWeaponv.clear();
	bossy3SWeaponv.clear();
}
void PlayState::StartPause(){
	paused = true;
}
void PlayState::EndPause(){
	paused = false;
}
void PlayState::IncrementCounters(){
	elapsedTime = (float)pClock.restart().asMilliseconds();
	enemyTimeCount += (int)elapsedTime;
	bulletTimeCount += (int)elapsedTime;
	yesCount += (int)elapsedTime;
	bossy1WeaponCount += (int)elapsedTime;
	bossy2WeaponCount += (int)elapsedTime;
	healthDropCount += (int)elapsedTime;
	camelTimeCount += (int)elapsedTime;
	damageChill += (int)elapsedTime;
	enemyFormationCount += (int)elapsedTime;
	bossy3FirstWeaponCount1 += (int)elapsedTime;
	bossy3FirstWeaponCount2 += (int)elapsedTime;
	bossy3SecWeaponCount += (int)elapsedTime;
}
void PlayState::HandleSpawns(Game &game){
	//initialize counts & background movement
	IncrementCounters();
	bg.Update(game.window, elapsedTime, bgSpeed);

	//spawns
	if (bossy3v.size() == 0){
		spawnManager.EnemySpawn(enemyTimeCount, enemyv, enemyFormationv, randomX);		//enemy
		spawnManager.EnemyFormationSpawn(enemyFormationCount, enemyFormationv, bossy2v);//enemyFormation
		spawnManager.doggoSpawn(points, doggov, bossy2v);							//doggo
		spawnManager.yesSpawn(yesCount, doggov, yesv, sound);						//yes
		spawnManager.bossy1Spawn(points, bossy1v);										//bossy1
		spawnManager.UnlockBoomySpawn(bossy1Dead, UnlockBoomyv);								//UnlockBoomy
		spawnManager.bossy1WeaponSpawn(bossy1WeaponCount, b1Weaponv, bossy1v, sound);		//b1Weapon
		spawnManager.bossy2Spawn(bossy2v, points);										//bossy2
		spawnManager.bossy2WeaponSpawn(bossy2WeaponCount, bossy2Weaponv, bossy2v);			//b2Weapon
		spawnManager.bossy3Spawn(bossy3v, points, sound);									//bossy3

		if (!bossy3dead)
			spawnManager.camelSpawn(camelTimeCount, camelv, randomX, sound);//camel
	}
	spawnManager.HealthDropSpawn(healthDropCount, healthv, randomX);//health
	spawnManager.bossy3FirstWeaponSpawn(bossy3FirstWeaponCount1, bossy3FirstWeaponCount2, bossy3FWeaponv, bossy3v, sound);
	spawnManager.bossy3SecWeaponSpawn(bossy3SecWeaponCount, bossy3SWeaponv, bossy3v, sound);

	pewCD.Update(pewOnCooldown, elapsedTime);//pewCooldown

	//player weapon spawn
	if (player1.getActiveBool()){
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
			spawnManager.BulletSpawn(bulletTimeCount, bulletv, game.highscore, weapon, player1, sound, game.window);//bullet
			spawnManager.DoubleShotSpawn(bulletTimeCount, dShotv, game.highscore, weapon, player1, sound, game.window);//Doubleshot
			spawnManager.PewSpawn(pewv, game.highscore, weapon, player1, sound, pewOnCooldown, game.window);//Pew
		}
	}
}

void PlayState::HandleUpdates(Game &game){
	UpdateManager::EnemyUpdate(enemyv, game.window, elapsedTime, game.highscore);				//enemy
	UpdateManager::StdUpdate(enemyFormationv, game.window, elapsedTime);						//enemyFormation
	UpdateManager::StdUpdate(doggov, game.window, elapsedTime);								//doggo
	UpdateManager::StdUpdate(yesv, game.window, elapsedTime);									//yes
	UpdateManager::StdUpdate(bossy1v, game.window, elapsedTime);									//bossy1
	UpdateManager::StdUpdate(UnlockBoomyv, game.window, elapsedTime);								//UnlockBoomy
	UpdateManager::StdUpdate(b1Weaponv, game.window, elapsedTime);								//b1Weapon
	UpdateManager::StdUpdate(bossy2v, game.window, elapsedTime);									//bossy2
	UpdateManager::bossy2WeaponUpdate(bossy2Weaponv, game.window, elapsedTime, player1);			// b2Weapon
	UpdateManager::StdUpdate(bossy3v, game.window, elapsedTime);									//bossy3
	UpdateManager::StdUpdate(camelv, game.window, elapsedTime);									//camel
	UpdateManager::StdUpdate(healthv, game.window, elapsedTime);								//health
	UpdateManager::StdUpdate(bossy3FWeaponv, game.window, elapsedTime);							//bossy3firstWeapon
	UpdateManager::StdUpdate(bossy3SWeaponv, game.window, elapsedTime);							//bossy3SecWeapon
																								
	UpdateManager::WeaponUpdate(bulletv, elapsedTime);								//bullet
	UpdateManager::WeaponUpdate(dShotv, elapsedTime);								//double shot
	UpdateManager::WeaponUpdate(pewv, elapsedTime);									//pewv

	UpdateHUD(game.window);

	if (player1.getActiveBool())
	player1.Update(game.window, elapsedTime);
}

void PlayState::HandleDraws(Game &game){
	if (player1.getActiveBool())
		player1.Render(game.window);

	Rm::StdDraw(healthv, game.window);//health
	Rm::StdDraw(UnlockBoomyv, game.window);//UnlockBoomy

	Rm::StdDraw(enemyv, game.window);//Enemy
	Rm::StdDraw(yesv, game.window);//yes
	Rm::StdDraw(doggov, game.window);//doggo

	Rm::StdDraw(enemyFormationv, game.window);//enemyFormation
	Rm::StdDraw(camelv, game.window);//camel

	Rm::StdDraw(b1Weaponv, game.window);//b1Weapon
	Rm::StdDraw(bossy1v, game.window);//bossy1
	Rm::StdDraw(bossy2Weaponv, game.window);//b2Weapon
	Rm::StdDraw(bossy2v, game.window);//bossy2

	Rm::StdDraw(bossy3FWeaponv, game.window);//bossy3FirstWeapon
	Rm::StdDraw(bossy3SWeaponv, game.window);//bossy3SecWeapon
	Rm::StdDraw(bossy3v, game.window);//bossy3

	Rm::StdDraw(bulletv, game.window);//bullet
	Rm::StdDraw(dShotv, game.window);//doubleShot
	Rm::StdDraw(pewv,game.window);//Pew
}

void PlayState::HandleCollisions(Game &game){
	CollisionManager::WeaponToEnemy(bulletv, points, sound, game.highscore, enemyv, doggov, yesv, bossy1v, bossy1Dead, bossy2Weaponv, enemyFormationv, bossy3v, bossy3FWeaponv, bossy3SWeaponv, bossy3dead, game.window);//bullet
	CollisionManager::WeaponToEnemy(dShotv, points, sound, game.highscore, enemyv, doggov, yesv, bossy1v, bossy1Dead, bossy2Weaponv, enemyFormationv, bossy3v, bossy3FWeaponv, bossy3SWeaponv, bossy3dead, game.window);//doubleShot
	CollisionManager::PewToEnemy(pewv, points, sound, game.highscore, enemyv, doggov, yesv, bossy1v, bossy2v, bossy2Weaponv, enemyFormationv, bossy3v, bossy3FWeaponv, bossy3SWeaponv, bossy3dead, game.window);//Pew
	if (player1.getActiveBool())	{
		//player collision
		coll::PlayerEnemyInactive(enemyv, player1, sound);//enemy
		coll::PlayerEnemyInactive(yesv, player1, sound);//yes
		coll::PlayerEnemyInactive(b1Weaponv, player1, sound);//b1Weapon
		coll::PlayerEnemyInactive(bossy2Weaponv, player1, sound);//b2Weapon
		coll::PlayerEnemyInactive(enemyFormationv, player1, sound);//enemyFormation
		coll::PlayerEnemyInactive(bossy3FWeaponv, player1, sound);//bossy3firstWeapon
		coll::PlayerEnemyInactive(bossy3SWeaponv, player1, sound);//bossy3secWeapon
		coll::PlayerHealthGet(healthv, player1, sound);//health
		coll::PlayerUnlockBoomy(UnlockBoomyv, player1, sound, gotPew, pewOnCooldown);//UnlockBoomy

		//for enemies that are not set inactive there is a damagechill.. otherwise player would instantly die
		if (damageChill > 500){
			coll::PlayerEnemyActive(camelv, player1, sound);//camel
			coll::PlayerEnemyActive(doggov, player1, sound);//doggo
			coll::PlayerEnemyActive(bossy1v, player1, sound);//bossy1
			coll::PlayerEnemyActive(bossy2v, player1, sound);//bossy2
			coll::PlayerEnemyActive(bossy3v, player1, sound);//bossy3
			damageChill = 0;
		}
	}
}

void PlayState::CountersToNull(){
	bulletTimeCount = 0;
	enemyTimeCount = 0;
	enemyFormationCount = 0;
	yesCount = 0;
	healthDropCount = 0;
	camelTimeCount = 0;
	randomX = 0;
	showLvUp = 0;
	damageChill = 0;
	bossy1WeaponCount = 0;
	bossy2WeaponCount = 0;
	bossy3FirstWeaponCount1 = 0;
	bossy3FirstWeaponCount2 = 0;
	bossy3SecWeaponCount = 0;
}

void PlayState::UpdateHUD(sf::RenderWindow &window){
	hudHealth.Update(window, player1.getHealth());
	weapon.setWeapon(elapsedTime, points, gotPew);
	weapon.Update();
}