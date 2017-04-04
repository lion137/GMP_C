#ifndef bigrational_h
#define bigrational_h
  
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>


class bigrational{
	public:
	mpq_t x;

bigrational(mpq_t n){
	mpq_init(x);
	mpq_set(x, n);
	mpq_canonicalize (x);
	}
bigrational(unsigned long long  int n, unsigned long long int d){
	mpq_init(x);
	mpq_set_ui(x, n, d);
	mpq_canonicalize (x);
	}
bigrational(signed long int n, unsigned long int d){
	mpq_init(x);
	mpq_set_si(x, n, d);
	mpq_canonicalize (x);
 	}
 bigrational(int n, int d){
 	unsigned long long int num = n;
 	unsigned long long int den = d;
 	mpq_init(x);
 	mpq_set_ui(x, num, den);
	mpq_canonicalize (x);

 }
bigrational(const char* str){
	mpq_init(x);
 	int base = 10;
    mpq_set_str (x, str, base);
 	mpq_canonicalize (x);
 }
 void printbigrational(){
 	gmp_printf ("%#4Qd\n", x);
 }
 void deleteBigrational();
 bigrational add(bigrational a, bigrational b);
 bigrational substract(bigrational a, bigrational b);
 bigrational mult(bigrational a, bigrational b);
 bigrational divide(bigrational a, bigrational b);
 bigrational invert(bigrational a);
};

#endif
