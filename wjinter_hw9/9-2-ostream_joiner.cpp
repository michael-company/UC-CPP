#include "9-2-ostream_joiner.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> iterateElem = {1,2,3,4,5,6,7,100,20,999,100};

    copy(iterateElem.begin(), iterateElem.end(), ostream_joiner(cout, ", "));
    cout<<endl;

    return 0;
}