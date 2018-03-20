#include <boost/function_output_iterator.hpp>
#include <iostream>

using namespace std;
using boost::function_output_iterator;

struct my_struct {
    my_struct(ostream &_os, string _delimiter): firstElm(true), os(&_os), delimiter(_delimiter) {
    }

    template<typename T>

    void operator()(T const &toString) {
        if(firstElm)
            firstElm = false;
        else
            *os << delimiter;
        *os << toString;
    }

    private:
        ostream *os;
        string delimiter;
        bool firstElm;
};

struct ostream_joiner: public function_output_iterator<my_struct> {
    ostream_joiner(ostream &os, string str): function_output_iterator<my_struct>(my_struct(os, str)) {
    }
};

