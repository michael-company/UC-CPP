#include "8-4-ComplexInt.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    //example
    ComplexInt showcase(5, 3);
    cout << "Below is 5+3i" << endl;
    cout << showcase << endl;
    //test cases
	ComplexInt complexIntA(3, 2), complexIntB(1, 4);
	cout << "Below is the 5+3i form" << endl;
	cout << complexIntA << endl;
	cout << "Below is the sum" << endl;
	cout << complexIntA + complexIntB << endl;
	cout << "Below is the product" << endl;
	cout << complexIntA * complexIntB << endl;
	return 0;
}
