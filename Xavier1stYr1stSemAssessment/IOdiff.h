

#ifndef IODIFF_H
#define IODIFF_H

#include <fstream>

class IOdiff
{
public:
	int ReadDiffSettings();
	void WriteDiffSettings(int &diff);
};

#endif