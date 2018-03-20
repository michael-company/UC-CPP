#include<iostream>
using namespace std;

int main()
{
    //ask user for flexible number of first row(s)
    int rows;
    cout << "Please enter the number of rows: ";
    cin >> rows;

    //print out line by line
    for (int i = 0; i < rows; i++)
    {
        //base case
        int numb = 1;
        //firstly, add space by the begnining of each line to position our Pascal's triangle
        for (int j = 1; j < (rows - i); j++)
        {
            cout << "   ";
        }
        //secondly, add space between the number and the number 1 by 1 to position our Pascal's triangle
        //just keep this loop ie remove the loop above if we not considering buidling the brick wall ie Extra Credit
        for (int j = 0; j <= i; j++)
        {
            cout << "      " << numb;
            numb = numb * (i - j) / (j + 1);
        }
        //thirdly, progress to the next 2 row to position our Pascal's triangle
        cout << endl<<endl;
    }
    //terminate
    cout << endl;
    return 0;
}
