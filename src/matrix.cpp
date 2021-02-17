#include <iostream>

using namespace std;

void make_matrix(int size){

    int matrix[size][size];

}


int main(){
    int ** dub_vector;

    dub_vector = new int*[5]; // 

    for(int i=0;i<5;++i){ // column
        dub_vector[i] = new int[5];
        for(int j=0;j<5;++j){ // row
            dub_vector[i][j] = j;
        }
    }


    int dub_vector2[5][5];

    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cout << dub_vector[i][j] << " ";
        }
            cout << endl;

    }

    // dub_vector2 = dub_vector;

    







    return 0;
}