#include <iostream>

using namespace std;

int mult(int a,int b){
    int m = 0;

    for(int i=0;i<b;++i){
        m = m + a;
    }
    return m;
}

int sub(int a,int b){


}

int main(){

    cout << mult(4,5) << endl;

    return 0;
}