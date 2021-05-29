#include "adder.h"



template <typename T>
Adder<T>::Adder(T a,T b){
    this->a = a;
    this->b = b;
}

template <typename T>
T Adder<T>::sum(){
    return a+b;
}

template class Adder<float>;
template class Adder<int>;