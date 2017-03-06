

#ifndef __SPLASHSTATE_H__
#define __SPLASHSTATE_H__

#include "Game.h"
#include "IOstuff.h"

class SplashState : public GameState{
public:
	SplashState();
	~SplashState();
	void HandleEvents(Game &game);
	void Update(Game &game);
	void Render(Game &game);

private:
	///PRIVATE MEMBER FUNCTIONS
	void initCredits();
	void initFading();
	void fadeOut();
	void changeState(Game& game);
	void updateCredits();

	///PRIVATE MEMBER VARIABLES

	//Menu related
	Background  m_bg;			///< Background
	sf::Clock   m_clock;		///< Clock to measure elapsed Time

	//SFML
	sf::Texture m_sfmlTex;		///< Texture of SFML-Logo
	sf::Sprite  m_sfmlSprite;	///< Sprite for SFML Texture
	int m_alphaSFML;			///< Alpha value for fading
	bool m_sfmlShown;			///< If this is true -> SFML logo has been shown

	//yesSoft
	sf::Texture m_yesSoftTex;	///< Texture of yesSoft-Logo
	sf::Sprite m_yesSoftSprite;///< Sprite for yesSoft Texture
	int m_alphayesSoft;		///< Alpha value for fading
	bool m_yesSoftShown;		///< If this is true -> yesSoft logo has been shown

	//Credits
	Text m_credits;				///< Textholder for Credits
	int m_alphaCredits;			///< Alpha value for fading
	bool m_CreditsShown;		///< If this is true -> credits have been shown

	//Statechange
	sf::Texture m_fadingTex;	///< Texture for fade IN/OUT
	sf::Sprite m_fadingSprite;	///< Sprite for fade IN/OUT
	bool m_startFading;			///< if this is true -> start increasing alpha
	int m_fadingAlpha;			///< Alpha-Value for fade IN/OUT
	float m_elapsedTime;		///< time elapsed in frame
};
#endif //__SPLASHSTATE_H__