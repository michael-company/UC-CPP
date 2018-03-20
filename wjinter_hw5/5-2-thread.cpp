#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>

using namespace std;

mutex amutex;

//Explanation:
//
//This code will create 3 threads each with the property of the counter more importantly the lock guard
//The 3 seperate threads are created and called in the main. Since the lock guard follow a single total order,
//Each thread will be synchronized between the lock operations and previous unlock operations on that same object.
//Thus essentially, each thread will be required to be called 100 times upon the cycle compeletion.
//Please check output in 5-2-thread-output if needed. Thanks.

void counter(){
    //http://en.cppreference.com/w/cpp/thread/mutex
    lock_guard<std::mutex> guard(amutex);
    //thread::id tempInt = this_thread::get_id(); ;
    for(int i=0; i < 100; i++){
        thread::id threadid = this_thread::get_id();
        cout << "Thread whose thread number is " << threadid << " has been called " << i+1 << " time" << endl;
    }
}

int main(void){

    //create 3 threads
    thread t1(counter);
    thread t2(counter);
    thread t3(counter);

    //call 3 threads
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
