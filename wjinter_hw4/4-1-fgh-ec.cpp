//It is a undefined behavior. The given code hypothetically will run forever, however, there is no guarantee as if there is
//stack overflow, exception, error, etc will occur, the system will stop the program like Xcode in my case.

//Likewise when I compile with the given, the program terminates with EXC_BAD_ACCESS(code=2,address=some location)
//after printing Some textSome textSome textSome textSome textSome textSome textSome textSome... (thousands of them)

//With more detailed inspection, the lower level code stops at return xsputn(__s, __n); or as in follow,
/*template <class _CharT, class _Traits>
  inline _LIBCPP_INLINE_VISIBILITY
  streamsize
  {
      return xsputn(__s, __n);
  }
*/

#include <iostream>
using namespace std;

//could be anything
int g(){
    return -1;
}

//could be anything
int h(){
    return -1;
}

int f() {
    cout << "Some texts";
    try{
        g();
        cout << f();
    }
    catch(...){
        cout<<"error"<<endl;
    }
    cout.flush();
    return 0;
}

int main(void){
    f();
    return 0;
}
