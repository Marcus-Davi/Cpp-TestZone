#include <iostream>
#include <vector>
#include <cstring>
#include <queue>



using namespace std;



class Queue
{
public:
    Queue(uint8_t length_, uint8_t data_size_) : length(length_), data_size(data_size_)
    {

        pData = malloc(length * data_size); // testar se alocou com sucesso..
    }

    void push(void *data)
    {
        if(isFull()){
            cout << "FULL\n";
            pop();
        }
        
        // cout << "Inserting " << endl;
        int index = (rear + 1)*data_size;
        memcpy(pData + index, data, data_size);
        rear = (rear + 1) % length;
        count++;
    }
    void pop()
    {
        if(isEmpty()){
             cout << "Empty\n";
            return;
        }
        // int index  = (front) * data_size;
        // memcpy(buffer, pData + index, data_size);

        front = (front + 1) % length;
        count--;

    }

    void front_(void * buffer){
        int index  = (front) * data_size;
        memcpy(buffer, pData + index, data_size);
        // buffer = pData + index;
    }

    ~Queue()
    {
        free(pData);
    }

    inline int size()
    {
        return count;
    }
   inline bool isFull()
    {
        return (size() == length);
    }

   inline bool isEmpty() {
    return (size() == 0);
}

private:
    uint8_t length;
    uint8_t data_size;
    int8_t rear = -1;
    int8_t front = 0;
    int8_t count = 0;
    void *pData;
};

struct Vec3 {
    float x,y,z;
    Vec3(float x_,float y_, float z_) {
        x =x_;
        y = y_;
        z = z_;
    }
};

ostream& operator<<(ostream& os, const Vec3 &data){
    os << "(" << data.x << "," << data.y << "," << data.z << ")";
    return os;
}

int main()
{
    Vec3 vetor(1,2,3);
    Vec3 vetor2(4,5,6);
    
    Vec3 vetor3(0,0,0);

    cout << vetor << vetor2 << vetor3 << endl;
    // Queue queue(5, sizeof(float));
    Queue queue(3, sizeof(Vec3));

    queue.push(&vetor);
    queue.push(&vetor);
    queue.push(&vetor2);

    queue.pop();
    queue.pop();

    queue.front_(&vetor3);

    cout << vetor3 << endl;
    

}
