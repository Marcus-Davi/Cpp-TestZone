#include <iostream>
#include <memory>



int main(){

		
	
		int* a_pt = new int(30);




		
		std::shared_ptr<int> aa_spt(a_pt);
		std::shared_ptr<int> aa_made = std::make_shared<int>();
		

		{
		std::cout << "aa_spt = " << *aa_spt << std::endl;
		*a_pt = 55;
//		delete a_pt;
//
		}
		std::cout << "aa_spt = " << *aa_spt << std::endl;



		

		std::shared_ptr<int> a_spt(new int) ;

		*a_spt = 20;

		std::shared_ptr<int> b_spt(a_spt);

		std::shared_ptr<int> c_spt;
		c_spt = b_spt;

		*c_spt = 5;




		std::cout << "a_pt = " << *a_pt << std::endl;


		std::cout << "a_spt = " << *a_spt << std::endl;

		return 0;
}
