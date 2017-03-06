

#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <string>



class IOdiff{
public:
	int ReadDiffSettings();
	void WriteDiffSettings(int &diff);
};



#include "HighscoreManager.h"

class IOHighscore{
public:

	void WriteHighscore(HighscoreManager &highscore);

private:
	std::ifstream readInFile;
	std::ofstream writeInFile;
	void openRead();
	void openWrite();
	void closeRead();
	void closeWrite();
};


class IOscreen{
public:
	bool getScreenSettings();
	void setScreenSettings(bool &screen);
};



class IOsmooth{
public:
	bool ReadSmoothSettings();
	void WriteSmoothSettings(bool &smooth);
};


class IOsound{
public:
	void ReadSoundSettings(int &volume);
	void WriteSoundSettings(int &volume);
};


class IOtwoPlayer{
public:
	bool ReadSettings();
	void WriteSettings(bool &twoPlayer);
};


#endif