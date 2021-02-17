#include <iostream>
#include <map>


using namespace std;
    struct DataItem{
        int key;
        int value;

        friend ostream& operator<<(ostream& os,const DataItem& data){
            os << data.key << "," << data.value;
        }

        bool operator<(const DataItem& other) const {
            return (key < other.key);
        }
    };

class myHash {
    public:
    myHash(int size = 1){
    hashTable = new DataItem *[size];
    tableSize = size;
    }

    void insert(int key,int value){
        DataItem * new_item = new DataItem;
        new_item->key = key;
        new_item->value = value;

        int arrIndex = hashCode(key);

        while(hashTable[arrIndex] != nullptr){
            
            if(hashTable[arrIndex]->key == key){
                // Duplicate, do nothing
                cout << "duplicate!" << endl;
                return;
            }
            
            arrIndex++;

            arrIndex %= tableSize;
        }

        hashTable[arrIndex] = new_item;


    }

    void Delete(int key){

    }

    DataItem* search(int key){
        int hashIndex = hashCode(key);


        while(hashTable[hashIndex] != nullptr){
            


            if(hashTable[hashIndex]->key == key)
                return hashTable[hashIndex];

            hashIndex++;

            hashIndex %= tableSize;
        }

        return nullptr;

    }

    void printTable(){
        for(int i=0;i<tableSize;++i){
            if(hashTable[i] != nullptr)
            cout << "(" << hashTable[i]->key << "," << hashTable[i]->value << ")" << endl;
        }

    }


    //Convert key into index
    int hashCode(int key){
        return key % tableSize;
    }




    private:
    int items = 0;
    int tableSize;
    DataItem ** hashTable;

    //doubles every overflow
    void realloc(){
        
        tableSize = tableSize*2; // new size
        cout << "reallocing ... new size = " << tableSize << endl;
        int* newTable = new int[tableSize];
        for(int i=0;i < items;++i){
            // newTable[i] = hashTable[i];s
        }
        delete hashTable;
        // hashTable = newTable;

        
    }

};

#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

int main(){
    myHash myTable(2);

    short int word = 0x0001;
    char* byte = (char*)&word;
    cout << (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN) << endl;
    return 0;

    map<DataItem,int> o_map;
    DataItem AA,BB;
    AA.key = 10;
    AA.value = 10;

    BB.key = 11;
    BB.value = 5;

    // if(AA < BB){
    //     cout << "AA less than BB" << endl;
    // }
    // cout << (AA < BB) << endl;
    // cout << AA;
    o_map[AA] = 15;
    cout << o_map[BB];
    return 0;
    
    myTable.insert(10,25);
    // myTable.insert(50,99);
    DataItem* found;
    if ( ( (found = myTable.search(22) ) != nullptr )  ){
        cout << "val: " << found->value << endl;
    } else {
        cout << "does not exist." << endl;
    }

    // myTable.insert(10,22);
    myTable.printTable();





    return 0;
}