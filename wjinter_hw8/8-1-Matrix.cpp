#include "8-1-Matrix.h"
#include <iostream>
#include <boost/progress.hpp>
using namespace mpcs51044;
using namespace std;

//10/10

int main()
{
	boost::progress_timer howlong;
	Matrix<3, 3> m = {
			{ 1, 2, 3, },
			{ 4, 5, 6, },
			{ 7, 8, 9, }
	};

    Matrix<3, 3> m2 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
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
