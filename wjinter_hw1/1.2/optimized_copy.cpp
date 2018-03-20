// Directly from Mike's for the check

#include "optimized_copy.h"
#include <iterator>
#include <iostream>
using namespace std;

int
main()
{
  double array[] = { 1, 2, 3, 4, 5 };
  double dest_array[5];
  optimized_copy(begin(array), end(array), dest_array);
  cout << "Print destination array to prove we copied" << endl;
  for (int i : dest_array)
    cout << i << ", ";
  return 0;
}