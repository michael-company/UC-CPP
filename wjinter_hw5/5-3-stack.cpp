#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

namespace mpcs51044
{
    template <typename T>
    class stack
    {
    public:
        stack() { this->intVal = new vector<T>(0); }

        stack(initializer_list<T> aList) { this->intVal = new vector<T>(aList); }

        ~stack() { this->intVal->clear(); delete this->intVal; }

        //use lock_guard<std::mutex> as in HW5-2
        void push(T value)
        {
            //thread safe
            lock_guard<std::mutex> guard(amutex);
            this->intVal->push_back(value);
        }


        //use lock_guard<std::mutex> as in HW5-2
        T pop()
        {
            //thread safe
            lock_guard<mutex> guard(amutex);
            T temp = this->intVal->back();
            this->intVal->pop_back();
            return temp;
        }

        //use lock_guard<std::mutex> as in HW5-2
        void print_stack()
        {
            //thread safe
            std::lock_guard<std::mutex> guard(amutex);
            for (auto elt : *intVal)
            {
                std::cout << elt << ' ';
            }
            std::cout << std::endl;
        }

    private:
        std::vector<T>* intVal;
        std::mutex amutex;
    };

}


void concurrent_test(mpcs51044::stack<int> &s)
{
    for (int i = 0; i < 9; ++i)
    {
        s.push(i);
    }

    for (int i = 0; i < 9; ++i)
    {
        s.pop();
    }
}

int main()
{
    mpcs51044::stack<int> s;


    cout<<"basic stack test:"<<endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    //print out 1 2 3 4 5 6
    s.print_stack();

    //pop out the top of the stack 6
    cout<<"pop out test:"<<endl;
    s.pop();

    //print out 1 2 3 4 5
    s.print_stack();

    cout<<"concurrent test:"<<endl;

    //create 9 threads
    thread t1((concurrent_test), ref(s));
    thread t2((concurrent_test), ref(s));
    thread t3((concurrent_test), ref(s));
    thread t4((concurrent_test), ref(s));
    thread t5((concurrent_test), ref(s));
    thread t6((concurrent_test), ref(s));
    thread t7((concurrent_test), ref(s));
    thread t8((concurrent_test), ref(s));
    thread t9((concurrent_test), ref(s));

    //join 9 threads
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();

    s.print_stack();

    cout<<"extra credit test:"<<endl;
    mpcs51044::stack<int> ec = {101, 102, 103, 104, 105};
    ec.print_stack();

    return 0;
}
