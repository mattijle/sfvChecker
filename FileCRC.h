#pragma once
#include <string>
#include <boost/crc.hpp>
#include <ios>
#include <fstream>
#include <iomanip>
#include <sstream>

#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE  1024
#endif
std::streamsize const  buffer_size = PRIVATE_BUFFER_SIZE;
class FileCRC
{
private:
	std::string filename;
	std::string crc;
public:
	FileCRC(std::string,std::string);
	~FileCRC(void);
	int checkCRC();
	std::string getFilename(){ return filename;};
	std::string getCRC(){ return crc;};
};

