#include <iostream>
#include <memory>

#define PRINT(text,a) std::cout << text << ": " << a << std::endl
#define PRINT_(text) std::cout << text << std::endl;

int main(){



		int* a_pt = new int(30);

		PRINT("Raw pointer content", *a_pt);	
		PRINT("Content address", a_pt);

		PRINT_("Creating shared pointer, constructing with raw pointer");
		std::shared_ptr<int> a_spt(a_pt);
		PRINT("Shared pointer content",*a_spt);
		PRINT_("Changing raw value...");
		*a_pt = 10;
		PRINT("Shared 'a' pointer content",*a_spt);
		PRINT_("Creating shared pointer, constructing with existing shared");

		std::shared_ptr<int> b_spt(a_spt);
		PRINT("Shared 'b' point content", *b_spt);
PRINT_("Changing shared 'b' content");
		*b_spt = 15;
		PRINT("Shared 'a' pointer content", *a_spt);
		PRINT("Raw content",*a_pt);


		PRINT_("Creating heap shared ptr 'c'...");
		std::shared_ptr<int> *c_spt = new std::shared_ptr<int>(b_spt);
		PRINT_("Changing shared 'c' content");
		*c_spt->get() = 5; // or.. **c_spt = 1;
		PRINT("Raw content",*a_pt);
		int count = c_spt->use_count(); 
		PRINT("# of shared",count);
		PRINT_("Deleting heap shared");
		delete c_spt;
		count = b_spt.use_count();
		PRINT("# of shared",count);
		PRINT("Raw address from 'b'",&(*b_spt));
		PRINT("Address of shared 'b'",&b_spt);

		return 0;
}
