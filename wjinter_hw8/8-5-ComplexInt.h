#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ComplexInt {
	public:

	int r;
	int i;

	ComplexInt() : r(0), i(0) {}
	ComplexInt(int x) : r(x), i(0) {}
	ComplexInt(int x, int y): r(x), i(y) {}

	friend ComplexInt operator +(const ComplexInt &x, const ComplexInt &y) {
		ComplexInt add(x.r + y.r, x.i + y.i);
		return add;
	}
	friend ComplexInt operator *(const ComplexInt &x, const ComplexInt &y) {
	    //https://www2.clarku.edu/~djoyce/complex/mult.html
		ComplexInt mult(x.r * y.r - x.i * y.i, x.r * y.i + x.i * y.r);
	    //return the result real and imaginary parts
		return mult;
	}

	friend ostream& operator <<(ostream &result, const ComplexInt &x) {
		ostringstream os;
		os << left << x.r << '+' << x.i << 'i';
		result << os.str();
        return result;
	}


};
