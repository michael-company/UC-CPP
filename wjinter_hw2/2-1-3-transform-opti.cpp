
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

float squareFun (float before, float number) {
    return before+number*number;
}

int main () {
    
    vector<float> input;
    vector<float> output;

    for(int i=0; i<5; i++){
        input.push_back((float)rand());
    }
    
    output.resize(input.size());
    //accmulate function
    cout<<sqrt(accumulate(input.begin(),input.end(),0.0,squareFun))<<endl;
    
    return 0;
}
