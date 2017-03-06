

#ifndef IOSOUNDS_H
#define IOSOUNDS_H

#include <iostream>
#include <fstream>

class IOsound
{
	public:
	void ReadSoundSettings(int &volume);
	void WriteSoundSettings(int &volume);
};

#endif