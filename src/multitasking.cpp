#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
using namespace std;
//#include <thread>

typedef void (*callbackptr)(void);
typedef void (*taskPtr)(void* param);

// namespace task {
//     void delay(uint32_t milliseconds){

//     }
// }

class Scheduler
{
public:
    enum Status
    {
        running,
        terminate
    };

    Scheduler(uint32_t frequency_) : frequency(frequency_)
    {

    }

    void init()
    {
        status = Status::running;
    }
    void Terminate()
    {
        status = Status::terminate;
    }

    // Systick
    void registerCallback(callbackptr callback_)
    {
        callback = callback_;
    }

    //Add Task
    void AddTask(taskPtr task){
        tasks.push_back(task);
    }

    void spin()
    {
        // callback();
        for(int i =0;i < tasks.size() ; ++ i){

            tasks[i](nullptr);
        }



        usleep(1000000U / frequency);
    }

private:
    callbackptr callback = nullptr;
    uint32_t frequency;
    vector<taskPtr> tasks;


public:
    Status status;
};

// Timer Simulation
void Systick(void)
{
    cout << "Systick\n";
}

void Task1(void* param){

    asm(
        "mov %eax,%ebx"
    );
    cout << "Task 1 \n";    
    // delay 1000 ms

    
}

void Task2(void* param){
    cout << "Task 2 \n";
}


int main()
{

    Scheduler sc(1); // 100 Hz
    sc.registerCallback(Systick);

    sc.AddTask(Task1);
    sc.AddTask(Task2);
    sc.init();

    while (sc.status == Scheduler::Status::running)
    {
        sc.spin();
    }

    return 0;
}