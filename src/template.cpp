#include <iostream>
#include "templated_class.h"

using namespace std;

// We must instantiate the class type



int main(){

    TClass<unsigned int> a;
    a.setVal2<double>(3.5);
    cout << a.getVal() << endl;


}