#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "FileCRC.h"
class SFV
{
private:
	std::string filename;
	std::vector<FileCRC> checksums;
public:
	std::string getFilename(){return filename;};
	void readFile();
	void checkFiles();
	SFV(std::string);
	~SFV(void);
};

