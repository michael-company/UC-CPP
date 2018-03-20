#include <future>
#include <iostream>
#include <thread>
#include <cstdio>
#include <ctime>

using namespace std;

//10/10

/*
 No. 10 of Fibonacci - Asynchronous Recursion: 55
 Relative Time, CLOCKS_PER_SEC - Asynchronous:0.007712
 No. 10 of Fibonacci - Given Recursion: 55
 Relative Time, CLOCKS_PER_SEC - Given:7e-06
 Effect: Asynchronous Recursion Fibonacci takes more time than in Given Recursion.

 No. 10 of Fibonacci -  One Line Recursion: 55
 Relative Time, CLOCKS_PER_SEC - One Line:5e-06
 Effect: One Line Recursion Fibonacci takes less time in Given Recursion.
 Program ended with exit code: 0
 */

// Find the nth Fibonacci number
unsigned fibonacci_async(unsigned num) {

    if (num <= 0) {
        return 0;
    } else if (num < 2) {
        return num;
    }

    auto handle = async(launch::async, fibonacci_async, num - 1);

    return handle.get() + fibonacci_async(num - 2);
}

// Find the nth Fibonacci number
unsigned fib(unsigned n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// Find the nth Fibonacci number
unsigned fib_short(unsigned n) {
    return n<2 ? n : fib_short(n-2) + fib_short(n-1);
}


int main() {

    unsigned nth = 10;

    clock_t start, start2, start3;
    double duration, duration2, duration3;

    start = clock();
    cout <<"No. "<< nth << " of Fibonacci - Asynchronous Recursion: " << fibonacci_async(nth) << std::endl;
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout<<"Relative Time, CLOCKS_PER_SEC - Asynchronous:"<< duration <<'\n';

    start2 = clock();
    cout <<"No. "<< nth << " of Fibonacci - Given Recursion: " << fib(nth) << std::endl;
    duration2 = (clock() - start2 ) / (double) CLOCKS_PER_SEC;
    cout<<"Relative Time, CLOCKS_PER_SEC - Given:"<< duration2 <<'\n';

    if(duration2<duration)
        cout<<"Effect: Asynchronous Recursion Fibonacci takes more time than in Given Recursion."<<endl;
    else if(duration2==duration)
        cout<<"Effect: None"<<endl;
    else
        cout<<"Effect: Asynchronous Recursion Fibonacci takes less time in Given Recursion."<<endl;

    cout<<endl;

    start3 = clock();
    cout <<"No. "<< nth << " of Fibonacci -  One Line Recursion: " << fib_short(nth) << std::endl;
    duration3 = (clock() - start3 ) / (double) CLOCKS_PER_SEC;
    cout<<"Relative Time, CLOCKS_PER_SEC - One Line:"<< duration3 <<'\n';

    if(duration3>duration2)
        cout<<"Effect: One Line Recursion Fibonacci takes more time in Given Recursion."<<endl;
    else if(duration2==duration)
        cout<<"Effect: None"<<endl;
    else
        cout<<"Effect: One Line Recursion Fibonacci takes less time in Given Recursion."<<endl;


    return 0;
}
