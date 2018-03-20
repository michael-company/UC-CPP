#include "8-3-Matrix.h"
#include <iostream>
#include <boost/progress.hpp>
using namespace mpcs51044;
using namespace std;

int main()
{
	boost::progress_timer howlong;
	Matrix<2, 2> m = {
			{ 1, 2},
			{ 3, 4}
	};

    Matrix<2, 2> m2 = {
			{ 1, 2},
			{ 3, 4}
    };

    cout<<"Below is the sum of the two matrices:"<<endl;
    cout<<m+m2<<endl;

    //given
	static double total;
	for (int i = 0; i < 10000000; i++) {
		m(1, 1) = i;
		total += m.determinant();
	}
	cout << total << endl;
}
