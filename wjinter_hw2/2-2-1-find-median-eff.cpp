#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMed(vector<double> num)
{
    double median;
    size_t size = num.size();
    
    sort(num.begin(), num.end());
    
    if (size  % 2 == 0)
    {
        median = (num[size / 2 - 1] + num[size / 2]) / 2;
    }
    else
    {
        median = num[size / 2];
    }
    
    return median;
}

int main(){
    vector<double> aVect {5,2,1,3,4};
    cout<<findMed(aVect);
    cout<<"\n";
}
