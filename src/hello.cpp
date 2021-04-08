#include <iostream>
#include <vector>

using namespace std;


int main(){

    vector<int> vec(10) ;

    std::fill(vec.begin(),vec.end(),0);

    int i = 5;
    int region = 3;
    

    std::fill_n(&vec[i],region+1,1);

    for (auto it : vec){
        cout << it << endl;
    }

    





    

}
