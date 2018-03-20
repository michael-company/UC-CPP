#include <vector>
#include <numeric>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>

using namespace std;

class TriangleObjectClass{
    typedef vector<int> Row;
    typedef vector<Row> Triangle;

public:
    //given
    int const rows=12;
    Triangle triangle;

    void initializeTriangle(){
        Row previousRow;
        previousRow.push_back(1);
        for(int i = 0; i < rows; i++) {
            triangle.push_back(previousRow);
            previousRow = nextRow(previousRow);
        }
    }

    //given
    Row
    nextRow(Row row)
    {
        Row result;
        int previous = 0;
        for (auto it = row.begin(); it != row.end(); it++) {
            result.push_back(previous + *it);
            previous = *it;
        }
        result.push_back(previous);
        return result;
    }

    //given
    int
    numDigits(int i)
    {
        int digits = 1;
        while((i/=10) != 0) {
            digits++;
        }
        return digits;
    }

    //given
    int
    numDigits_alternate(int i)
    {
        ostringstream os;
        os << i;
        return os.str().size();
    }

    //given
    int
    numDigits_alt2(int i)
    {
        return std::to_string(i).size();
    }


    //given
    int eltSize;

    //given
    string
    centeredInt(int i)
    {
        ostringstream os;
        os << i;
        string str = os.str();
        return string((eltSize - str.size())/2, ' ') + str;
    }

    //change field
    void
    printRow(Row row)
    {
        for(auto it = row.begin(); it != row.end(); it++) {
            cout << left << setw(eltSize) << centeredInt(*it) << " ";
        }
        cout << endl;
    }

    //change header
    void
    printPascalTriangle()
    {
        Row lastRow = triangle[rows - 1];
        int maxElement = *max_element(lastRow.begin(), lastRow.end());
        eltSize = numDigits(maxElement);
        for(int i = 0; i < rows; i++) {
            string spaces((rows - i - 1) * (eltSize + 1) / 2, ' ');
            cout << spaces;
            printRow(triangle[i]);
        }
    }
};

int
main()
{
    TriangleObjectClass aTriangle;
    aTriangle.initializeTriangle();
    aTriangle.printPascalTriangle();
    return 0;
}
