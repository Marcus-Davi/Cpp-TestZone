#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class ObjA
{
public:
    ObjA() {}
    ObjA(int a) : prot_a(a){};

    virtual ~ObjA() {}

    int getProt() { return prot_a; }

protected:
    int prot_a;

    void ProtMethod() { cout << "Protected Method"; }
};

class ObjA_Child : ObjA
{
public:
    // using ObjA::prot_a; // no more inaccessible
    using ObjA::getProt; // no more inacessible

    ObjA_Child(){};
    ObjA_Child(int a, int b) : ObjA(a + b) {}

    void setProt(int a)
    {
        prot_a = a;
    }
};

template <class T>
class Abstract
{
public:
    Abstract() {}
    virtual ~Abstract() {}

    // Child will call implemented
    virtual void Method1()
    {
        cout << "Abstract Method1" << endl;
    }

    void Method2()
    {
        cout << "Abstract Method2" << endl;
    }

    void SetPrivate(T a)
    {
        priv_a = a;
    }

    T getPrivate()
    {
        return priv_a;
    }

    void compute()
    {
        initCompute(); // call
    }

private:
    T priv_a;

protected:
    virtual bool initCompute() = 0;
    T prot_a;
};

template <class T>
class Child : public Abstract<T>
{
public:
    // using Abstract<T>::priv_a; // private
    using Abstract<T>::prot_a; // Compile error if not used

    void Method1()
    {
        cout << "Child Method 1" << endl;
    }

    void Method2()
    {
        cout << "Child Method 2" << endl;
    }

    // Protected assessible
    T GetProtected()
    {
        return prot_a;
    }

    void setProtected(T a)
    {
        prot_a = a;
    }

private:
protected:
    bool initCompute() override
    {
        cout << "Child Init Compute (Protected)" << endl;

        return true;
    }
};

struct Point
{
    float x;
    float y;
    Point() = default;
    Point(float x_, float y_) : x(x_), y(y_){};
};

class PointCloud
{
public:
    PointCloud() { cout << "created PC" << endl; };

    vector<Point> points;

    ~PointCloud() { cout << "deleted PC" << endl; }

    void Print() const
    {
        cout << "PointCloud!" << endl;
    }

    // private:
};

ostream &operator<<(ostream &s, const PointCloud &p)
{
    int size = p.points.size();
    for (int i = 0; i < size; ++i)
    {
        s << p.points[i].x << "," << p.points[i].y << endl;
    }
    return s;
}

// void ConstTest(const PointCloud& p){
//     p.points.push_back(Point(2,2));
// }

void SharedTest(std::shared_ptr<PointCloud> &cloud)
{
    shared_ptr<PointCloud> copy(cloud); // same object
    cout << "Method called" << endl;
    cloud->points.push_back(Point(8, 8));
    copy->points.push_back(Point(10, 10));

    cloud->Print();
    cloud.reset();
    cloud = make_shared<PointCloud>();
}

template <class T>
void TestPolymorphism(Abstract<T> *obj)
{
    obj->Method1(); // Call inherited
    obj->Method2();
}

// Impl
template <class T>
bool Abstract<T>::initCompute()
{
    cout << "Abstract Init Compute (Protected)" << endl;

    return true;
}

int main()
{
    // Test Stuff Here. Call return 0 after test to assure modular testing.

    // Abstract<float> aaa;
    Child<float> bbb;
    bbb.compute();

    return 0;

    ObjA A;
    ObjA B(2);
    ObjA_Child A_c(5, 6);
    cout << A_c.getProt() << endl;

    return 0;

    // Abstract abs;
    // Abstract<float> *abs_ptr = new Abstract<float>;
    // Child<float> *chld_ptr = new Child<float>;
    // chld_ptr->setProtected(3.4);
    // cout << chld_ptr->getPrivate() << std::endl;

    // std::cout << chld_ptr->GetProtected() << std::endl;

    // // Typecast to Abstract
    // TestPolymorphism(chld_ptr);

    // chld_ptr = (Child<float> *)abs_ptr;
    // // abs_ptr = (Abstract<float>*)chld_ptr;

    // TestPolymorphism(abs_ptr);

    // // abs_ptr = &abs;

    return 0;

    std::shared_ptr<PointCloud> A_ptr(new PointCloud);
    std::shared_ptr<PointCloud> B_ptr(A_ptr); // Same object, dous not call constructor
    // std::shared_ptr<PointCloud> C_ptr = std::make_shared<PointCloud>();

    SharedTest(A_ptr);

    A_ptr->points.push_back(Point(3, 3));
    B_ptr->points.push_back(Point(3, 4));

    cout << "A = " << *A_ptr << endl;
    cout << "B = " << *B_ptr << endl;
}