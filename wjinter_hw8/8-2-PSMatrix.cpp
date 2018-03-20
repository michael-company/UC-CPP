//8-2

#include "8-2-PSMatrix.h"
#include <boost/progress.hpp>
#include <iostream>
using namespace std;
using namespace mpcs51044;

//15/15

int main()
{
	boost::progress_timer howlong;
	Matrix<double, 2, 2> m = {
    			{ 1, 2},
    			{ 3, 4}
    };
	static double total;
	for (int i = 0; i < 10000000; i++) {
		m(1, 1) = i;
		total += m.determinant();
	}
	cout << total << endl;
}