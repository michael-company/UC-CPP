#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float squareFun (float number) {
    return number*number;
}

int main () {
    
    vector<float> input;
    vector<float> output;
    
    for(int i=0; i<5; i++){
        input.push_back((float)rand());
    }
    
    output.resize(input.size());

    //transform function
    transform (input.begin(), input.end(), output.begin(), squareFun);
    
    for(int i=0; i<5; i++){
        cout<<output.at(i);
        cout<<"\n";
    }
    
    return 0;
}
