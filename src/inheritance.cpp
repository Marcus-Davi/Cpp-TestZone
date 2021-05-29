#include <iostream>
#include <memory>
// Inheritance example
using namespace std;

class Parent
{
public:
    Parent() : public_parent_var(0), private_parent_var(0), protected_parent_var(0)
    {
        std::cout << "Parent Created!" << std::endl;
    }
    void ParentPublicMethod() { std::cout << "Public Parent Method" << std::endl; }
    int public_parent_var;
    virtual void GetID()
    {
        std::cout << "ID: PARENT" << std::endl;
    }

    void PrintAll()
    {
        std::cout << "p_public: " << public_parent_var << std::endl;
        std::cout << "p_private: " << private_parent_var << std::endl;
        std::cout << "p_protected: " << protected_parent_var << std::endl;
    }

private:
    int private_parent_var;
    void ParentPrivateMethod() { std::cout << "Parent Private Method" << std::endl; }

protected:
    int protected_parent_var;
    void ParentProtectedMethod() { std::cout << "Parent Protected Method" << std::endl; }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << "Child Created" << std::endl;
    }
    int child_public_var = 1;

    void PrintAll_()
    {
        std::cout << "c_public: " << child_public_var << std::endl;
        std::cout << "c_private: " << private_child_var << std::endl;
        std::cout << "c_protected: " << protected_child_var << std::endl;
    }
    void GetID()
    {
        std::cout << "ID: CHILD" << std::endl;
    }

    void ChildMethod()
    {
        ParentPublicMethod();
        ParentProtectedMethod();
        protected_parent_var = 1;
        // ParentPrivateMethod();
    }

private:
    int private_child_var = 1;

protected:
    int protected_child_var = 1;
};


template <typename type>
class Obj
{
public:
    void print()
    {
        cout << "Parent" << endl;
    }
};

template <typename type>
class Obj_child : public Obj<type>
{
public:
    void print()
    {
        cout << "Child" << endl;
    }
    void new_method(){
        cout << "New method\n";
    }
};

int main()
{
    Obj<int> A;

    A.print();

    Obj_child<int> B;
    B.print();


    Obj<int>* Aptr;
    Aptr = &B;
    ((Obj_child<float>*)Aptr)->new_method();
    

    return 0;
    Parent p;
    Child c;

    // Child* c_pt;
    Parent *p_pt = new Child;

    p_pt->GetID();

    delete p_pt;

    p_pt = new Parent;

    p_pt->GetID();

    return 0;
}