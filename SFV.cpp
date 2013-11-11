#include "stdafx.h"
#include "SFV.h"
void SFV::readFile(){
	std::ifstream fin(filename);
	std::string ff;
	std::string path = filename.substr(0,filename.rfind("\\"));
	while(std::getline(fin,ff)){
		int tt = ff.rfind(" ");
		FileCRC cc(path+"\\"+ff.substr(0,tt),ff.substr(tt+1,8));		
		checksums.push_back(cc);
	}
}

void SFV::checkFiles(){
	for(unsigned int i=0;i < checksums.size();++i){
		std::string st = checksums[i].checkCRC()>0?"Success":"Failure";
		std::cout<<std::endl<<checksums[i].getFilename()<<" "<<checksums[i].getCRC()<<" "<<st;		
	}
}
SFV::SFV(std::string fn)
{
	filename = fn;
}


SFV::~SFV(void)
{

}
