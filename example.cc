
#include<cstdlib>    
#include<iostream>    
#include<tuple>    
#include<gmp.h>    
#include "biginteger.h"    
#include "biginteger.cc"    
#include<algorithm>    
#include<string>    
int main() {
	
	
	biginteger x = biginteger (32);
	biginteger v = biginteger("1", 10)  ;
	x.printbiginteger();
	unsigned long long int y = 2;
	unsigned long long int z = 7420;
	printf("%d\n", isPrime(power(y, z) - v); //isPrime takes bigint or unsigned long long int
	                                          // substraction works with unsigned long long int or biginteger
	                                          // we print just an integer now
	return 0;
}
