#include <iostream>
#include <string.h>

class CommandParser {
	public:
	enum Ret {
	A,
	B,
	C,
	LS

	};

	static unsigned int Parse(const std::string& buffer){
	for(int i=0;i<NCMDS;++i){
	std::cout << "i = " << i << std::endl;
	if(buffer.find(CMDS[i]) != std::string::npos)	{
//	std::cout << buffer << " = " << CMDS[i] << std::endl;
	return i;
	}
	}

	return -1;

	}

	static int Parse(const char* buffer){
		for(int i=0;i<NCMDS;++i){
		std::cout << "i = " << i << std::endl;
		if( strstr(buffer,CMDS[i]) != 0){	
//		std::cout << buffer << " = " << CMDS[i] << std::endl;
		return i;

		}
		
		}
	return -1;
	}

	private:
	static const char* CMDS[];
	static int NCMDS;


};

const char* CommandParser::CMDS[] = {"A","B","C","LS"};
int CommandParser::NCMDS = 4;

int main(){

	char kek[] = "A";
	std::string input0(kek);

	int res = CommandParser::Parse(input0);

	if(res == CommandParser::A)
	std::cout << "res = " << res << std::endl;








}
