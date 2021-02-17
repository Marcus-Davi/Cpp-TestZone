#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <unordered_set>

using namespace std;

class myint
{
public:
	myint()
	{
		std::cout << "My int created" << std::endl;
	}
	myint(int value) : _myint(value)
	{
		std::cout << "My int created" << std::endl;
	}

	~myint()
	{
		std::cout << "My int destroyed" << std::endl;
	}

	void operator=(int value)
	{
		_myint = value;
	}

	friend std::ostream &operator<<(std::ostream &os, const myint &value)
	{
		os << value._myint;
		return os;
	}

	int _myint = 0;
};

template <class T>
class MyVector
{
public:
	MyVector(){};
	MyVector(unsigned int N_) : N(N_)
	{
		main_ptr = new T[N];
	}

	unsigned int size() const
	{
		return N;
	}

	T &operator[](unsigned int index)
	{
		return main_ptr[index];
	}

	T &operator[](unsigned int index) const
	{
		return main_ptr[index];
	}
	void clear()
	{
		//						delete[] main_ptr;
		for (int i = 0; i < N; ++i)
		{
			main_ptr[i].~T();
		}
		N = 0;
	}

	~MyVector()
	{
		if (N != 0)
			delete[] main_ptr;

		//						delete main_ptr;
	}

private:
	unsigned int N = 0;
	T *main_ptr;
};

template <class T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &data)
{

	int N = data.size();

	for (int i = 0; i < N; ++i)
	{
		std::cout << data[i] << std::endl;
	}

	return os;
}

// bool containsChar(const string &letters, const string &word)
// {
// 	for(int i =0;i<word.size();++i){
// 		for(int j = 0;j<letters.size();++j){


// 		}

// 	}
// 	return true;
// }

int main()
{

	unordered_set<string> string_set;
	// string letters = "oet";

	vector<string> dictionary = {"toes", "toe", "ote", "god", "gods", "holes"};
	string letters = "oet";

	int LARGEST = -999;

	unordered_set<string> result;

	for (auto it : dictionary)
	{	

		if (it.find_first_not_of(letters) == string::npos)
		// if(containsChar(letters,it))
		{
			// cout << "Erasing " << it << endl;
			// string_set.erase(it);
			string_set.insert(it);

			// cout << LARGEST << ", " << it.size() << endl;

			if(LARGEST >= it.size()){
				// cout << "Add";
				LARGEST = it.size();
				result.insert(it);

			}

			// if(it.size() == LARGEST){
			// 	result.insert(it);
			// }
		}
		else
		{

		}
	}

	

	cout << "Final Result...  " << endl;
	for (auto it : result)
	{
		cout << it << endl;
	}

	exit(0);

	vector<vector<string>> tc1 = {{"Bobby", "87"},
								  {"Charles", "100"},
								  {"Eric", "64"},
								  {"Charles", "90"},
								  {"Charles", "90"}};

	map<string, int> sala;
	vector<int> N;
	for (int i = 0; i < tc1.size(); ++i)
	{
		map<string, int>::iterator it = sala.find(tc1[i][0]);
		if (it == sala.end())
		{ // new entry

			sala.insert(std::make_pair(tc1[i][0], stoi(tc1[i][1])));
			N.push_back(1);
		}
		else
		{ // repeated entry
		}
	}

	for (auto it = sala.begin(); it != sala.end(); ++it)
	{
		cout << it->first << "," << it->second << endl;
	}

	return 0;
	std::cout << "MyVector Test" << std::endl;
	MyVector<int> int_vector(10);

	int_vector[0] = 10;

	std::cout << int_vector << std::endl;

	{
		// std::shared_ptr<myint> s_int(new myint);
		myint *s_int = new myint;
		std::cout << "Shared" << *s_int << std::endl;
		delete s_int;
	}

	int_vector.clear();

	std::cout << "Program Finished." << std::endl;

	return 0;

	//std::cout << "v[0] = " << int_vector[0] << std::endl;
	//
	// 		int_vector[0] = 20;
	//
	// 		std::cout << int_vector[0] << std::endl;

	// 		int_vector.clear();
	//
	// 		std::cout << int_vector.size() << std::endl;

	std::cout << " STD Starting..." << std::endl;

	std::vector<myint> vec(10);

	vec.clear();

	std::cout << "Program finishing..." << std::endl;
	return 0;
}
