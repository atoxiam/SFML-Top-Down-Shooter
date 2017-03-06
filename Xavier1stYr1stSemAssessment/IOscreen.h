

#ifndef IOSCREEN_H
#define IOSCREEN_H

#include <fstream>


class IOscreen
{
public:
	bool getScreenSettings();
	void setScreenSettings(bool &screen);
};

#endif