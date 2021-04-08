#include <iostream>
#include <memory>
#include <vector>

#define PRINT(text, a) std::cout << text << ": " << a << std::endl
#define PRINT_(text) std::cout << text << std::endl;

template <typename T = float>
struct Point
{
	T x;
	T y;
	T z;
};

class PointXYZ : public Point<double>
{
public:
	PointXYZ()
	{
		// std::cout << "Empty Constr.." << std::endl;
		x = 0;
		y = 0;
		z = 0;
		PointXYZ::counter++;
	}
	PointXYZ(double x, double y, double z)
	{
		// std::cout << "Input Constr.." << std::endl;
		this->x = x;
		this->y = y;
		this->z = z;
		PointXYZ::counter++;
	}

	PointXYZ(const PointXYZ &other)
	{
		// std::cout << "Copy Constr.." << std::endl;
		PointXYZ::counter++;
		x = other.x;
		y = other.y;
		z = other.z;
	}

	static void PrintCount()
	{
		std::cout << "CNT: " << counter << std::endl;
	}

	~PointXYZ(){
		std::cout << "deleting point ?" << std::endl;
	}

private:
	static int counter;
};

int PointXYZ::counter = 0;
using PointCloud = std::vector<PointXYZ>;
using PointCloudPtr = std::shared_ptr<PointCloud>;

std::ostream &operator<<(std::ostream &os, const PointCloud &PC)
{
	if (PC.size() == 0)
	{
		os << "no points!" << std::endl;
		return os;
	}

	// for(int i=0;i<PC.size();++i){
	// 	os << PC[i].x << "," << PC[i].y << "," << PC[i].z << std::endl;
	// }

	// for(PointCloud::const_iterator it = PC.begin(); it != PC.end(); ++ it){
	// 		os << it->x << "," << it->y << "," << (*it).z << std::endl;
	// }

	for (const auto &it : PC)
	{
		os << it.x << "," << it.y << "," << it.z << std::endl;
	}

	return os;
}

int main()
{

	PointCloudPtr a = std::make_shared<PointCloud>();
	PointCloudPtr b(new PointCloud);
	a->emplace_back(PointXYZ(1, 1, 1));
	(*a)[0] = PointXYZ(5, 5, 5);
	a->push_back(PointXYZ(2, 2, 2));
	// a->push_back(PointXYZ(3, 3, 3));
	// a->push_back(PointXYZ(3, 3, 3));
	// a->push_back(PointXYZ(3, 3, 3));

	a.reset(new PointCloud);

	std::cout << *a << std::endl;

	// PointXYZ::PrintCount();

	// b->push_back(PointXYZ(9,9,9));

	// std::cout << "Before swap..." << std::endl;
	// std::cout << "a = " << *a << std::endl;
	// std::cout << "b = " << *b << std::endl;

	// b.swap(a);

	// std::cout << "after swap..." << std::endl;
	// std::cout << "a = " << *a << std::endl;
	// std::cout << "b = " << *b << std::endl;

	// PointCloudPtr c(a); //same ownership

	// std::cout << "c(a) = " << *c << std::endl;

	// c = std::make_shared<PointCloud>(*a);

	// a->push_back(PointXYZ(0,0,0));

	// std::cout << "c(a) = " << *c << std::endl;

	return 0;

	int *a_pt = new int(30);

	PRINT("Raw pointer content", *a_pt);
	PRINT("Content address", a_pt);

	PRINT_("Creating shared pointer, constructing with raw pointer");
	std::shared_ptr<int> a_spt(a_pt);
	PRINT("Shared pointer content", *a_spt);
	PRINT_("Changing raw value...");
	*a_pt = 10;
	PRINT("Shared 'a' pointer content", *a_spt);
	PRINT_("Creating shared pointer, constructing with existing shared");

	std::shared_ptr<int> b_spt(a_spt);
	PRINT("Shared 'b' point content", *b_spt);
	PRINT_("Changing shared 'b' content");
	*b_spt = 15;
	PRINT("Shared 'a' pointer content", *a_spt);
	PRINT("Raw content", *a_pt);

	PRINT_("Creating heap shared ptr 'c'...");
	std::shared_ptr<int> *c_spt = new std::shared_ptr<int>(b_spt);
	PRINT_("Changing shared 'c' content");
	*c_spt->get() = 5; // or.. **c_spt = 1;
	PRINT("Raw content", *a_pt);
	int count = c_spt->use_count();
	PRINT("# of shared", count);
	PRINT_("Deleting heap shared");
	delete c_spt;
	count = b_spt.use_count();
	PRINT("# of shared", count);
	PRINT("Raw address from 'b'", &(*b_spt));
	PRINT("Address of shared 'b'", &b_spt);

	return 0;
}
