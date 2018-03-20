
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <string>

using namespace std;

float squareFun (float number) {
    return number*number;
}

int main () {

    vector<float> input;
    vector<float> output;

    double aNum;

    for(int i=0; i<5; i++){
        cout<<"Please enter No. "<<i+1<<" number.\t";
        cin >> aNum ;
        input.push_back(aNum);
    }

    output.resize(input.size());
    //transform function
    transform (input.begin(), input.end(), output.begin(), squareFun);
    //accmulate function
    cout<<sqrt(accumulate(output.begin(),output.end(),0))<<endl;

    return 0;
}
