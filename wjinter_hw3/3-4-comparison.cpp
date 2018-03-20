//The const modifier are valid and equivalent, can appear on either side, of most types.

//For example
//int const A = 100;
//const int A = 100;

//I personally think const int is better.
//because const is a keyword makes compiler points the following to constant variable
//int is a keyword makes compiler points the following to integer variable
//thus it is logically sound to use const int, as it represents a is an integer which is constant

//Regardless, below are examples noted that either one is fine
//const int a; // "a is an integer which is constant"
//int const a; // "a is a constant integer"

//a=1000;      //compiler error, since a is a constant or can't be changed

//Above can also be verified by the program below
//Just decomment based on what had stated
/*
#include <iostream>
using namespace std;


int
main()
{
    //const int A = 100;
    int const a = 100;

    //a = 1000;

    return 0;
}
*/


//Furthermore, both ways are valid but they are not equivalent of pointer type
//Followed with the above, it can also be verified by the program below
//Just decomment based on what had stated

/*
#include <iostream>
using namespace std;

int
main()
{
    const char *b; // "b is a pointer to a char that is constant"

    //*b = 'A';      // compiler error, because pointer b pointed to a char is constant
    b++;           // no error, because the pointer b isn't constant

    char c;

    char *const t = &c; // "t is a constant pointer pointed to a char"


    //t++;           // compiler error, because the pointer is constant
    *t = 'A';      // no error, because the char isn't constant

    return 0;
}
*/