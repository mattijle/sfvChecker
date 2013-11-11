/***********************************************************
** sfcChecker.cpp 
**
** Description: Simple command line utility to validate the
** crc checksums of downloaded files.
**
** Mostly written in an effort to learn some C++.
**
***********************************************************
***********************************************************
**
** Author: Matti Leppänen
** Date: 2013-11-12
** Compiler: Visual Studio 2012  (Should be compatible with other compilers too.)
**
***********************************************************/

#include "stdafx.h"
#include "SFV.h"

int main(int argc, char const *  argv[])
{
	if(argc != 2){
		std::cout<<"Usage: "<<argv[0]<<" filename.sfv"<<std::endl;
		return 1;
	}
	SFV sfv(argv[1]);
	std::cout<<"Reading sfv file."<<std::endl;
	sfv.readFile();
	std::cout<<"Checking the crcs"<<std::endl;
	sfv.checkFiles();
	
	return 0;
}

