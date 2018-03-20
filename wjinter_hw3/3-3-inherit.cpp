#include <iostream>
using namespace std;

// Define classes D and B such that D inherits from B and create a B *b
// Base class
class B  {
    //makes B a polymorphic
public:virtual void test1() {
        cout<<("test1 in B\n");
    }

    virtual ~B(){}
};

// D inherits from B
class D:public B {

public:void test2() {
        cout<<("test2 in D\n");
    }

    virtual ~D(){}
};

int
main()
{
    B* b;

    //demonstrate they give different results simply by printing them
    cout << dynamic_cast<D*>(b) << endl;
    cout << (D*)b;


    //Which one is better?
    //cout <<dynamic_cast<D*>(b) is better


    //bad casting since b is not polymorphic
    //would like to use static_cast<D*>(b) instead

    return 0;
}