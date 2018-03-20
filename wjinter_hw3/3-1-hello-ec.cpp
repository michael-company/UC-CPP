#include <iostream>
using namespace std;

class MyClass2
{
public:
    MyClass2()
    {
        cout << ",";
    }
}two;


class MyClass3
{
public:
    MyClass3()
    {
        cout << " ";
    }
};


class MyClass4
{
public:
    MyClass4()
    {
        cout << "world";
    }
};

void myHello (void) __attribute__ ((constructor));

void myHello (void)
{
    cout << "Hello";
}

struct exclamation_mark {
    exclamation_mark() { cout << "!";}
};

MyClass3 a3;
MyClass4 a4;
exclamation_mark a5;

//given
int
main()
{
    return 0;
}