#include <iostream>

using namespace std;

struct A {
    A(): floatNum(0.0f), intNum(10) {};
    int func(int* pi) { (*pi)++; floatNum++; return *pi;};
    int outer(double (*dbl)(float&)) {
        if (static_cast<int>(dbl(floatNum)))
            return 99;
        else
            return 999;
    }
    float floatNum;
    int intNum;
};

void B(A* pa, char const *pc, char const &cr, long list[], float& rf) {
    if (pa && *pc == cr)
        for (int it = 0; it < 7; ++it)
            cout << list[it] << (it != 6 ? ", " : "\n");
    rf = 0;
}

void C(int (*fip)(), int (*&rfip)()) {
    if (fip == rfip) cout << "equal"<<endl;
}

double inner(float& f) {
    if (static_cast<int>(f))
        return 100;
    return 999;
}

void blank() {
}

int nothing() {
    return 0;
}

char* point(char* a, char* b) { return (*a > *b ? a : b); }

int main() {

    //int *
    int i = 100;
    int* intPointer = &i;
    cout << "int *" << endl;
    cout << intPointer << endl;

    //int&
    int& j = i;
    i = 100;
    cout << "int&" << endl;
    cout << j << endl;

    //double
    double k = 100.999;
    cout << "double" << endl;
    cout << k << endl;

    //A *
    int* ip = new int;
    A* ap = new A;
    cout << "A" << endl;
    cout << ap << endl;

    //char const *
    char const *cp = "A* String";
    cout << "char const *" << endl;
    cout << cp << endl;

    //char const &
    char const &cr = *cp;
    cout << "char const &cr" << endl;
    cout << cr << endl;

    //long[7]
    long l[7] = {100L, 101L, 102L, 103L, 104L, 105L, 107L};
    cout << "long[7]" << endl;
    cout << l << endl;

    //int **
    int** ipp = &ip;
    cout << "int **" << endl;
    cout << ipp << endl;

    //int *&
    int*& ipr = *ipp;
    cout << "int *&" << endl;
    cout << ipr << endl;

    //float &
    float* fi = new float;
    float& fr = *fi;
    cout << "float &" << endl;
    cout<< fr <<endl;

    //int (*) ()
    B(ap, cp, cr, l, fr);
    int (*pfi)() = 0;
    cout << "int (*) ()" << endl;
    cout<< pfi <<endl;

    //int (*&) ()
    int (*&prfi)() = pfi;
    cout << "int (*&) ()" << endl;
    cout<< prfi <<endl;

    //char *(*) (char *, char *)
    C(pfi, prfi);
    char* (*pfc)(char*, char*) = point;
    cout << "char *(*) (char *, char *)" << endl;
    cout<< pfc << endl;

    //char *(*) (char *, char *)
    char first = 'a', second = 'b';
    char *numOne = &first, *numTwo = &second;
    cout << *pfc(numOne, numTwo) << endl;
    cout<<"char *(*) (char *, char *)"<<endl;
    cout<<"hi"<<endl;

    //int A::*
    int A::*pmi = &A::intNum;
    cout<<"int A::*"<<endl;
    cout << ap->*pmi << endl;

    //int (A::*)(int *)
    int (A::*pmf)(int*) = &A::func;
    cout<<"int (A::*)(int *)"<<endl;
    cout << (ap->*pmf)(ip) << endl;

    //int (A::**(int *)
    int (A::**ppmf)(int*) = &pmf;
    cout << "int (A::**(int *) "<< endl;
    cout << (ap->**ppmf)(ip) << endl;

    //int (A::*&(int *)
    int (A::*&prmf)(int*) = *ppmf;
    cout << "int (A::*&(int *)"<< endl;
    cout << (ap->*prmf)(ip) << endl;

    double (*mix)(float&) = inner;

    //int (A::*)(double (*)(float &))
    int (A::*multi)(double(*)(float&)) = &A::outer;
    cout << "int (A::*)(double (*)(float &))"<< endl;
    cout << (ap->*multi)(mix) << endl;

    //void (*p[10]) (void (*)() );
    void (*p[10]) (void (*)());
    cout << "(*p[10]) (void (*)() )"<< endl;
    cout << p[10]<< endl;

}
