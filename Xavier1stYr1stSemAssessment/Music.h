

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>
#include <string>



class IngameMusic{
public:
	void LoadMusic(int &volume);
	void PlayMusic();
	void Pause();
	void GameVolume(int &volume);
private:
	sf::Music gameTheme;
};



class MenuMusic{
public:
	void LoadMusic(int &volume);
	void PlayMusic(std::string music);
	void Pause(std::string which);
	void MenuVolume(int &volume);
	void IntroVolume(int &volume);
private:
	sf::Music menuTheme;
	sf::Music introTheme;
};



#endif