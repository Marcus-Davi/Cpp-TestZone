#pragma once

template <typename T>
class Adder {
    public:
    Adder(T a,T b);

    T sum();

    private:
    T a;
    T b;
};