#pragma once

template <typename T>
class TClass {
    public:
    TClass(){}
    virtual ~TClass(){}

    T getVal() {
        return val;
    }
    void setVal(T v){
        val = v;
    }

    template <typename T2>
    void setVal2(T2 val){
        this->val = val;
    }

    T val;
    private:
    T a,b,c;
};


