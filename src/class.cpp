#include <iostream>



class A {
	public:
	A(int in){
	std::cout << "A constrcutor" << std::endl;
   	pub_a = in;
	pri_a = in+1;
	}
	int pub_a;
	private:
	int pri_a;

};

class B : public A {
	public:
	
     B(int in) : A(in) {
	     std::cout << "B constructor" << std::endl;
	    pub_b = in;
     }
     int pub_b;
     

	private:
     int pri_b;
};




int main(){
A a(2);
B b(3);

}
