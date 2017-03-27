# GMP_C
copyleft lion137, https://lion137.blogspot.ie/

C ++ wrapper for GMP library.    
Compile with flag: -lgmp
To use it put them two classes in PATH or current directory.   
This repo contains class biginteger which under the hood uses GMP library.
Overloaded operators: +=, -=, *=, /=, +, -, *, /, - can be used also with integers and unsigned long long integers.       
%, %= - works with bigintegers only (so far)
Boolean operators: < >, ==    
Methods: abs(), power(unsigned long long int), mod - works with bigint and unsigned long long int.    

Functions: usage: fun(args):    
isPrime(<biginteger, unsigned long long int>)  - returns 0 if number is not prime, 1 if is probably prime and 2 if definitely prime.    
power(x: unsigned long long int, y: unsigned long long int) returns biginteger x ^ y    

Usage:
biginteger x = biginteger(<(string, base), int, unsigned long long int, signed int>) // overloaded constructor    

All overloaded opertors can be used like a normal expressions:    

Generally, after declaration we can use bigintegrs as a normal numbers with unsigned longs.

Compilation flags:
- when compiling files biginteger.cc and biginteger.h use flags: g++ -c -Wall  -std=c++11 -o %f -lgmp
- main: g++ -Wall -std=c++11 main.cc -lgmp

#end
