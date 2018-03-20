#include "8-5-ComplexInt.h"
#include <iostream>
#include <string>
#include <complex>


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

    using namespace std::complex_literals;
    std::complex<double> c = 3.0 + 2i;
    std::complex<double> d = 1.0 + 4i;
    std::cout << "Sum - Lookup Literal in (real, imaginary) form = " << c+d << '\n';
    std::cout << "Product - Lookup Literal in (real, imaginary) form = " << c*d << '\n';


	return 0;
}
