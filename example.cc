
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
#include "biginteger.h"
#include "biginteger.cc"
#include "bigrational.cc"
#include "bigrational.h"
#include <algorithm>
#include <string>
int main() {
	
	char str1[10] = "123";
	biginteger x = biginteger(32);
	biginteger v = biginteger("10", 10);
	x.printbiginteger();
	unsigned long long int y = 2;
	unsigned long long int z = 7420;
	unsigned long long int n = 3;
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
	printf(" truncated sqrt from 10 = ");
	sqrt_bigint(v).printbiginteger();
	printf("sqrt reminder from 10 = ");
	sqrt_bigint_rem(v).printbiginteger();
	printf("root reminder degree 3 from 33= ");
	rootn_bigint_rem(biginteger(str1, 10), n).printbiginteger();
	bigrational r1 = bigrational(3, 7);
	r1.printbigrational();
	invert(add(r1, r1)).printbigrational();
	
	/*
	 Outome:
	                     
32
0
32
12
144
6323103910516831208301947314...//very big number
 truncated sqrt from 10 = 3
sqrt reminder from 10 = 1
root reminder degree 3 from 33= 6
3/7
7/6

	 *  */
	 
	return 0;
}
