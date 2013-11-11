#include "stdafx.h"
#include "FileCRC.h"

int FileCRC::checkCRC(){
	boost::crc_32_type result;
	std::stringstream res;
	std::ifstream fin(filename,std::ios_base::binary);
	if(fin){
		do{
			char buffer[buffer_size];
			fin.read(buffer,buffer_size);
			result.process_bytes(buffer,fin.gcount());
		}while(fin);
	}else{
		return 0;
	}

	res << std::setfill('0')
		<< std::setw(8)
		<< std::hex
		<< result.checksum();
	if(crc == res.str()){
		return 1;
	}
	return 0;
}
FileCRC::FileCRC(std::string fn, std::string c)
{
	filename = fn;
	crc = c;
}


FileCRC::~FileCRC(void)
{

}
