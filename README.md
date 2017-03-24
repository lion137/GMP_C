# GMP_C
C ++ wrapper for GMP library.    
To use it put them two classes in PATH or current directory.   
This repo contains class biginteger which under the hood uses GMP library.
Overloaded operators: +=, -=, *=, /=, +, -, *, / - can be used also with integers and unsigned long long integers.    
Boolean operators: < >, ==    
Methods: abs(), power(unsigned long long int), mod - works with bigint and unsigned long long int.    

Functions: usage: fun(args):    
isPrime(<biginteger, unsigned long long int>)  - returns 0 if number is not prime, 1 if is probably prime and 2 if definitely prime.    
power(x: unsigned long long int, y: unsigned long long int) returns biginteger x ^ y    

Usage:
biginteger x = biginteger(<(string, base), int, unsigned long long int, signed int>) // overloaded constructor    

All overloaded opertors can be used like a normal expressions:    

example program:


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


Generally, after declaration we can use bigintegrs as a normal numbers with unsigned longs.
