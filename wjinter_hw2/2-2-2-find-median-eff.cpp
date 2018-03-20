#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Yes. I find it is more efficient find median function as partial sort uses less data as according to C++ manual
//sort performs approximately N*log2(N) (where N is this distance)
//comparisons of elements, and up to that many element swaps (or moves).

//partial sort, on average, less than linearithmic in the distance between first and last:
//Performs approximately N*log(M) comparisons of elements (where N is this distance, and M
//is the distance between first and middle). It also performs up to that many element swaps
//(or moves).

double findMed(vector<double> num){
    int size=num.size();
    //partial_sort function
    partial_sort (num.begin(),num.begin()+((size-1)/2+2), num.end());
    if(size%2 ==0){
        return (num[(size-1)/2]+num[(size-1)/2+1])/2;
    }
    else{
        return num[(size-1)/2];
    }
}

int main(){
    vector<double> aVect {5.5,2.2,1.1,3.3,4.4};
    cout<<findMed(aVect);
    cout<<"\n";
}
