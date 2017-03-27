
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
#include "biginteger.h"
#include "biginteger.cc"
#include <algorithm>
#include <string>
using namespace std;
int main() {
	
	
	biginteger x = biginteger(32);
	biginteger v = biginteger("1", 10);
	biginteger w = biginteger(7);
	biginteger w1 = biginteger(13);
	x.printbiginteger();
	unsigned long long int y = 2;
	unsigned long long int z = 7420;
	printf("%d\n", isPrime(power(y, z) - v)); //isPrime takes bigint or unsigned long long int
	                                          // substraction works with unsigned long long int or biginteger
	                                          // we print just a integer now
	                                          
	biginteger u = biginteger(12);
	x.printbiginteger();
	x = u + v - v; // arithmetic works
	x.printbiginteger();
	x *=x;
	x.printbiginteger();
	
	if (x > y) // boolean > works for unsigned long long int and bigint 
	    x *= power(y, z);
	x.printbiginteger();
	

	cout >> "13 mod 7 is: ";(w1 % w).printbiginteger();
	
	/*
	 Outome:
	                     
32
0
32
12
144
6323103910516831208301947314...//very big number
	 * 
6 	
	 */

	 
	return 0;
}
