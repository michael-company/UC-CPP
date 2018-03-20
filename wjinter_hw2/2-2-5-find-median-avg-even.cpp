#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class myType> myType

findMed(vector<myType> num)
{
    int size=num.size();
    if(size%2!=0){
        nth_element (num.begin(), num.begin()+(size-1)/2, num.end());
        return num[(size-1)/2];
    }
    else{
        nth_element (num.begin(), num.begin()+(size-1)/2, num.end());
        double first=num[(size-1)/2];
        nth_element (num.begin(), num.begin()+(size-1)/2+1, num.end());
        double second=num[(size-1)/2+1];
        return (first+second)/2;
    }
}

int main(){
    vector<double> aVect {5.5,2.2,1.1,3.3,4.4,0.0};//2.2+3.3=5.5->5.5/2=2.75
    cout<<findMed(aVect);
    cout<<"\n";

    vector<int> anotherVect {5,1,1,3,4,0};//1+3=4->4/2=2
    cout<<findMed(anotherVect);
    cout<<"\n";
}
