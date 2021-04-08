#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    A()
    {
        std::cout << "A created." << endl;
        ++count;
    }

    // Copy Construct
    A(const A& other){
        std::cout << "Copy Constructor" << endl;
        this->ID = other.ID;
    }

    A(int id) : ID(id)
    {
        std::cout << "A created(int)." << endl;
        ++count;
    }
    virtual ~A()
    {
        std::cout << "A destroyed." << endl;
        --count;
    }

    int getId() const { return ID; } // const needed

    static int getCount() { return A::count; }

private:
    static int count;
    int ID;
};

template <class T>
void VecAccess(const vector<T> &obj)
{
    cout << "Accessing " << endl;
    // const int& ref = obj[0].getId();
    int N = obj.size();
    for (int i = 0; i < N; ++i)
    {
        const A& element = obj[i]; ; // using const ref avoids copy | otherwises call copy constructor
        
        cout << "Idx: " << i << " ID: " << element.getId() << endl;
    }
}

int A::count = 0;

int* x_str; 

int& soma(int a,int b){
    int* x = new int;
    x_str = x;
    *x = a+b;
    // cout << "x addr&: " << &x << endl;
    cout << "x addr: " << x << endl;
    return *x;
}

int main()
{
    int um = 1;

    int& _um = um;

    cout << _um << endl;

    um = 2;

    cout << _um << endl; // ref
    int& a = soma(5,6);
    *x_str = 2;
    cout << "a = " << a << endl;
    cout << "x_str = " << x_str << endl;


    return 0;

    vector<A> A_vec;
    A_vec.reserve(5);
    for (int i = 0; i < 5; ++i)
    {
        A ai(i + 1);
        A_vec.push_back(ai);
    }

    // A a0(0);

    cout << "Created..." << endl;

    VecAccess(A_vec);
    // std::cout << A::getCount() << endl;

    return 0;
}