// This program file consists of several simple recursive functions
// that can be transformed into iterative functions (loops).
// One could conceivably start with a loop implementation,
// but the point of this exercise is to demonstrate a process
// that can be applied to many functions originally conceived recursively.
#include <iostream>
using namespace std;

// The initially-recursive functions to work with today
int firstDigit(int);
int gcf(int, int);
int bsearch(const int[], int, int, int);
int factorial(int);
double power(double, int);

int main()
{
	int nums[] = { 3, 7, 9, 13, 14, 21, 23, 27, 42, 54 };

	cout << "The first digit of 123 is " << firstDigit(123) << endl;
	cout << "The first digit of 76436 is " << firstDigit(76436) << endl;

	cout << "The gcf of 2 and 4 is " << gcf(2, 4) << endl;
	cout << "The gcf of 63 and 105 is " << gcf(63, 105) << endl;

	cout << "seeking 42 should yield  8: " << bsearch(nums, 42, 0, 9) << endl;
	cout << "seeking 25 should yield -1: " << bsearch(nums, 25, 0, 9) << endl;

	cout << "6! = " << factorial(6) << " and 10! = " << factorial(10) << endl;

	cout << "0.1 ^ 3 = " << power(0.1, 3) << endl;
	cout << "2 ^ 15 = " << power(2, 15) << endl;

	return 0;
}

//  firstDigit:
//  returns the first non-zero digit of an integer value
//  Parameter:
// 	value	(input integer)		the value to examine
//  Returns:				the value of a digit (1 - 9)
//  Pre-condition: value is greater than zero
int firstDigit(int value)
{
	while (value >= 10)		// more than one digit 
		value=value / 10;
			
		return value;
}

//  gcf:
//  returns the greatest common factor of two positive integers
//  Parameters:
// 	a, b	(input integers)	values to examine
//  Returns:				largest integer to divide both a and b
//  Pre-condition:  both input values are greater than zero
int gcf(int a, int b)
{
	int rem;			// remainder of division 
	rem = a % b;
	while (rem > 0)		// no common factor yet found
	{
		a = b;
		b = rem;
		rem = a%b;
	}
			// b divides both a and b
		return b;
}

//  bsearch:
//  implements a binary search of an integer array
//  Parameters:
//  	list	(input integer array)	data to search
//  	value	(input integer)		value to look for
//  	left	(input integer)		lower bound of search
//  	right	(input integer)		upper bound
//  Returns:		the subscript in the array where value is found
//  			or -1, if the value is not present
//  Pre-conditions:
//      left and right are valid subscripts  (within [0..array size)]
//      the array is sorted in increasing order
//      a present value would appear in the bounds specified
int bsearch(const int list[], int value, int left, int right)
{
	int mid;				// midpoint of range

	
	do {
	
		mid = (left + right) / 2;
		

		 if (value < list[mid])		// value would be in lower half
			right = mid-1;
		else	if (value > list[mid])			// value would be in upper half
			left = mid+1;


	} while (list[mid] != value &&  left <= right);
	if (left > right)			// no more array to search
		return -1;
	return mid;
}

//  factorial:
//  computes the sum of all positive integers <= its argument
//  Parameter:
//  	n	(input integer)		N for which to compute N!
//  Returns:				factorial (product of values)
//  Pre-condition:   0 <= n < 13
int factorial(int n)
{
	int sum = n;
	
	while (n > 1)
	{
		n--;
		sum = sum*n;
		
	}
	return sum;
}

//  power:
//  computes the exponentiation of a real number to an integer power
//  Parameters:
//  	base	 (input double)		value to exponentiate
//  	exponent (input integer)	exponent to use
//  Pre-condition:
//  	exponent is non-negative
double power(double base, int exponent)
{
	double sum = base;
	while (exponent > 1)
	{
		exponent--;
		sum = sum*base;
		
	}
		return sum;
}