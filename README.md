# GMP_C
copyleft lion137, https://lion137.blogspot.ie/

C ++ wrapper for GMP library.    
Compile with flag: -lgmp
To use it put them two classes in PATH or current directory.   
This repo contains classes biginteger and bigrational, which under the hood uses GMP library.    
For bigintegers:    
Overloaded operators: +=, -=, *=, /=, +, -, *, /, - can be used also with integers and unsigned long long integers.       
%, %= - works with bigintegers only (so far)
Boolean operators: < >, ==    
Methods: abs(), power(unsigned long long int), mod - works with bigint and unsigned long long int.    

Functions: usage: fun(args):    
isPrime(<biginteger, unsigned long long int>)  - returns 0 if number is not prime, 1 if is probably prime and 2 if definitely prime.    
power(x: unsigned long long int, y: unsigned long long int) returns biginteger x ^ y 
sqrt_bigint(biginteger) - gives truncted part of sqrt
sqrt_bigint_rem(biginteger) - reminder from sqrt or zero if perfect square    
rootn_bigint(biginteger) - returns truncated part of root n from argument
rootn_bigint_rem(biginteger) - returns reminder from root n or zero if perfect square    
  
power(x: unsigned long long int, y: unsigned long long int) returns biginteger x ^ y     
sqrt_bigint(biginteger) - gives truncted part of sqrt    
sqra_bigint_rem(biginteger) - reminder from sqrt or zero if perfect square       

Usage:
biginteger x = biginteger(<(* char, base), int, unsigned long long int, signed int>) // overloaded constructor    

All overloaded opertors can be used like a normal expressions:    

Generally, after declaration we can use bigintegrs as a normal numbers with unsigned longs.    

For bigrationals:   

Functions:    
add(bigrational, bigrtional) - returns bigrational    
substract(bigrational, bigrational) - returns bigrational    
mult(bigrational, bigrational) - returns bigrtional    
divide(bigrational, bigrational) - returns bigrational    
invert(bigrational) - returns inverted bigrational    



Compilation flags:
- when compiling files biginteger.cc and biginteger.h use flags: g++ -c -Wall  -std=c++11 -o %f -lgmp
- main: g++ -Wall -std=c++11 main.cc -lgmp
    
    		


#end
