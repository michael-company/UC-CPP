#include "9-1-Matrix.h"
#include <iostream>
#include <boost/progress.hpp>
using namespace mpcs51044;
using namespace std;

//30/30

int main()
{
	boost::progress_timer howlong;
	Matrix<4, 3> m = {
			{ 1, 2, 3, 4},
			{ 4, 5, 6, 8},
			{ 7, 8, 9, 0}
	};
	static double total;
	for (int i = 0; i < 10000000; i++) {
		m(1, 1) = i;
		total += m.determinant();
	}
	//cout << m << endl;
	cout << total << endl;
}
