#include <iostream>
#include <cassert>


using namespace std;

class Increment {
	public:
	Increment(){};


	inline int operator()(int x){
		return num+x;
	}
	private:
	int num = 0;

};


int main(){
		Increment add_1;

		cout << add_1(2) << endl;
		cout << add_1(2) << endl;

		


		return 0;
}
