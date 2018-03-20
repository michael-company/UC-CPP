#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//why doesnt it work - how would you fix it

struct maxlenftn {
    maxlenftn() { maxlen = 0; }
    void operator()(string s) {
        maxlen = max(maxlen,s.size());
    }
    string::size_type maxlen;
};

int main() {

    vector<string> names{"Spertus", "Lemon", "Golden", "Melhus"};
    maxlenftn maxf;

    //It doesn't work because it didn't increment the final maxln index which is crucial to be printed out as suggested
    //Ihe fix is simple. Just supply the for_each operation with names string vector to maxlen ie in the maxlenftn

    //for_each(names.begin(),names.end(),maxf);
    //cout << maxf.maxlen << endl;

    //http://en.cppreference.com/w/cpp/algorithm/for_each
    cout<<for_each(names.begin(),names.end(),maxf).maxlen << endl;

    return 0;
}