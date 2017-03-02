// The second of two driver programs to test an array sum function.
// The use of multiple source files prevents the need to duplicate
// the code that adds an array.
#include <iostream>
using namespace std;

#include "sum.h"

//  This function apparently does nothing, but
//  actually has an effect below, that will soon be evident.
void nothing( int a, int b, int c )
{
}

int main()
{
    int testData[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    string hello = "Hello, World!";

    nothing(0,0,0);
    cout << "The sum of the first 9 integers is " 
	 << sumArray(testData,9) << endl;
}
    
