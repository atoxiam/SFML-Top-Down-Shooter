

#ifndef IOSMOOTH_H
#define IOSMOOTH_H

#include <fstream>

class IOsmooth
{
public:
	bool ReadSmoothSettings();
	void WriteSmoothSettings(bool &smooth);
};

#endif