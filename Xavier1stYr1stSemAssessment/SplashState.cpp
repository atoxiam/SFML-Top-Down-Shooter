#include "SplashState.h"

SplashState::SplashState(){

	m_bg.setFilePath("graphics/core/settings.jpg");

	//init credits
	initCredits();

	//initialize Fading
	initFading();
}

SplashState::~SplashState(){
	//Empty
}

void SplashState::HandleEvents(Game &game){
	sf::Event pEvent;

	while (game.window.pollEvent(pEvent)){
		if (pEvent.type == sf::Event::Closed)
			game.setRunning(false);
	}
}


void SplashState::Update(Game &game){
	
	//get the elapsed time
	m_elapsedTime = (float)m_clock.restart().asMilliseconds();

	if (!m_startFading){
		//Update the Credits to get them fading
		updateCredits();
	}

	//See if we should change the ScreenState
	if (m_startFading){
		fadeOut();
		changeState(game);
	}
}

void SplashState::Render(Game &game){
	//draw Background
	m_bg.Render(game.window);

	//draw Credits
	if (!m_sfmlShown){
		game.window.draw(m_sfmlSprite);
	}
	if (!m_shitSoftShown){
		game.window.draw(m_shitSoftSprite);
	}
	
	if (!m_CreditsShown){
		m_credits.Render(game.window);
	}
	
	//draw fading sprite
	game.window.draw(m_fadingSprite);
}

//Init fading
void SplashState::initFading(){

	if (!m_fadingTex.loadFromFile("graphics/core/settings.jpg")){
		perror("could not load fading graphic from \"graphics/core/settings.jpg\" \n");
	}
	m_fadingTex.setRepeated(true);

	m_fadingSprite.setTexture(m_fadingTex);
	m_fadingSprite.setPosition(0.0f, 0.0f);

	m_startFading = false;
	m_fadingAlpha = 0;
	m_fadingSprite.setColor(sf::Color(128, 128, 128, m_fadingAlpha));

}

//fade out by increasing the alpha-Value
void SplashState::fadeOut() {

	//increase as long as value is not 255
	if (m_fadingAlpha <= 255) {
		m_fadingAlpha += (int)m_elapsedTime / 2;
		//set alpha
		m_fadingSprite.setColor(sf::Color(255, 255, 255, m_fadingAlpha));
	}
}

//change the state (after fadeOut is done)
void SplashState::changeState(Game& game){
	//if the fadeOut is done we are ready to change the screen
	if (m_fadingAlpha >= 255){
			game.ChangeState(Game::gameStates::MAINMENU);
	}
}

//initialize Credits
void SplashState::initCredits(){



	//Credits
	std::string tmp;
	//Programmed by
	tmp = "PROGRAMMED BY\n\n";
	tmp += "\t - Xavier A. Melton\n";
	tmp += "\t - For AIE 1st Year\n";
	tmp += "\t  1st Semester Assessment\n\n";
	m_alphaCredits = 0;
	m_CreditsShown = false;
	m_credits.setStringAndSize(tmp, 30);
	m_credits.setPosition(150, 70);
	m_credits.setColor(sf::Color(255, 255, 255, m_alphaCredits));
}

//Update the Credits to change their alpha-Value
void SplashState::updateCredits(){

	//Start with SFML
	if (m_alphaSFML <= 255 && !m_sfmlShown){
		m_alphaSFML += (int)m_elapsedTime / 5;
		m_sfmlSprite.setColor(sf::Color(255, 255, 255, m_alphaSFML));
	}
	if (m_alphaSFML >= 255 && !m_sfmlShown){
		m_sfmlShown = true;
	}

	//Then ShitSoft
	if (m_alphaShitSoft <= 255 && !m_shitSoftShown && m_sfmlShown){
		m_alphaShitSoft += (int)m_elapsedTime / 5;
		m_shitSoftSprite.setColor(sf::Color(255, 255, 255, m_alphaShitSoft));
	}
	if (m_alphaShitSoft >= 255 && !m_shitSoftShown){
		m_shitSoftShown = true;
	}

	//Then Credits
	if (m_alphaCredits <= 255 && !m_CreditsShown && m_shitSoftShown && m_sfmlShown){
		m_alphaCredits += (int)m_elapsedTime / 7;
		m_credits.setColor(sf::Color(255, 255, 255, m_alphaCredits));
	}
	if (m_alphaCredits >= 255 && !m_CreditsShown){
		m_CreditsShown = true;
	}

	//After everything has been shown - init fadeout
	if (m_sfmlShown && m_shitSoftShown && m_CreditsShown){
		m_startFading = true;
	}
}