#include <iostream>
#include <vector>
#include <dirent.h>
#include <string.h>

class foo {
	public:
static	int getsize(){
	return N;
	}


	private:
	static const char* comandos[];
	static const int N;

};

const char* foo::comandos[] = {"A","B","C","MARCUS"};
const int foo::N = sizeof(foo::comandos)/sizeof(char*);



int main(){

	std::cout << foo::getsize() << std::endl;	
	return 0;
	const char* homedir = getenv("HOME");	
	std::string path = std::string(homedir) + "/Waypoints";
	std::vector<std::string> files;

	DIR* dir;
	dirent* dirp;

	if (  (dir = opendir(path.c_str())) == NULL) {
	 std::cout << "ERROR" << std::endl;
	
	}


	while ( (dirp = readdir(dir)) != NULL ){
	if (strstr(dirp->d_name,".wpt") != 0)		
	files.push_back(std::string(dirp->d_name));
	
	}	
	closedir(dir);

	std::cout << "Files = ... " << std::endl;
	for(unsigned int i=0;i<files.size();++i){
	std::cout << files[i] << std::endl;
	}	



}
