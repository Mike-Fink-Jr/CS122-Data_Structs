// A short program illustrating what can (and cannot)
// be down with exceptions in C++
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

//  FactorialVector
//  Fills up a Vector with computed factorials
//  An array would typically make more sense,
//  but arrays provide no subscript range checking,
//  which is one of the features of today's exercise.
int factorialVector(vector<int> &vec, int n)
{
    int product;
    vec[1] = 1;
    for (int i = 2; i <= n; i++)
    {
	vec.at(i) = vec.at(i-1) * i;
    }
}

int main()
{
    vector<int> small(10);		// this vector is too small
    bool repeat = true;			// to allow multiple attempts
    
    while (repeat)
    {
	try 
	{
	factorialVector( small, 15 );
	repeat = false;			// stop when it works
	}
	catch (exception &ex)
	{
	cout << "Caught " << ex.what() << endl;
	repeat = false;			// stop when some new exception happens
	}
    }
    for (int i=0; i<small.size(); i++)	// display the results
	cout << small[i] << " ";
    cout << endl;
}
