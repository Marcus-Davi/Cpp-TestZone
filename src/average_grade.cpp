#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> grade;


void print_map(const map<string,grade>& map_){
    // int N = map_.size();

    for(auto map_it = map_.begin(); map_it != map_.end(); ++map_it){

        cout << "Name -> " << map_it->first << endl;
        cout << "Total Grade -> " << map_it->second.first << endl;
        cout << "Tests -> " << map_it->second.second << endl ;

    }
}

int getMaxAverage(const map<string,grade>& map_){

    int max_grade = INT32_MIN;
    for(auto map_it = map_.begin(); map_it != map_.end(); ++map_it){

        int current_grade = map_it->second.first / map_it->second.second;
        if(max_grade < current_grade)
            max_grade = current_grade;

    }

    return max_grade;

}


int solution(vector<vector<string>> tc1){
    map<string,grade> class_map;

    int N = tc1.size();
    map<string,grade>::iterator map_it;

    for(int i=0;i<N;++i){

        string name = tc1[i][0];
        int grade = stoi(tc1[i][1]);


        map_it = class_map.find(name);
        if(map_it == class_map.end()){
            pair<int,int> dummy;
            dummy.first = grade;
            dummy.second = 1;

            class_map.insert(make_pair(name,dummy));
            
            

        } else {

            class_map[name].first+= grade;
            class_map[name].second++;
            
        }


    }


    print_map(class_map);
    return(getMaxAverage(class_map));

}


int main(){

    vector<vector<string>> tc1 = { {"Charles", "87"},
                                    {"Marcus","88"},
                                    {"Sarah","55"},
                                    {"Bob","67"},
                                    {"Isa","89"},
                                    {"Marcus","99"},
                                    {"Sarah","10"},
                                    {"Charles","5"},
                                     };
    
    
    int grade = solution(tc1);

    cout << endl << endl;


    cout << "Solution = " << grade << endl;

    return 0;
}