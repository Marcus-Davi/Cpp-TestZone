#include <iostream>


int main(int argc,char** argv){

		if(argc < 2) {
				std::cerr << "insert command to be execute in argument!" << std::endl;
				exit(1);
		}

		FILE* fp;
		char path[1000];

		std::string command;

		for(int i=1;i<argc;++i){
				command = command + argv[i] + " ";



		}

		std::cout << "command to be executed: " << command << std::endl;
		// return 0;

		fp = popen(command.c_str(),"r");
		if (fp == NULL){
				std::cerr << "failed to call command" << std::endl;
				exit(1);
		}


		std::string program_output;

		while(fgets(path,sizeof(path),fp) != NULL) {
	program_output += path;
		}


		std::cout << "command output: " << std::endl << std::endl;
 		std::cout << program_output ;
		std::cout << "output string size " << program_output.size() << std::endl;


}
