//plik z funkcjami bigrational bigrational.cc
#include "bigrational.h"
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>

void bigrational::deleteBigrational(){
	mpq_clear(x);
	
}
bigrational add(bigrational a, bigrational b){
	mpq_t sum;
	mpq_init(sum);
	mpq_add(sum, a.x, b.x);
	return sum;
}
bigrational substract(bigrational a, bigrational b){
	mpq_t sum;
	mpq_init(sum);
	mpq_sub(sum, a.x, b.x);
	return sum;
}
bigrational mult(bigrational a, bigrational b){
	mpq_t sum;
	mpq_init(sum);
	mpq_mul(sum, a.x, b.x);
	return sum;

  } 
bigrational divide(bigrational a, bigrational b){
	mpq_t sum;
	mpq_init(sum);
	mpq_div(sum, a.x, b.x);
	return sum;
}

bigrational invert(bigrational a){
	mpq_t sum;
	mpq_init(sum);
	mpq_inv(sum, a.x);
	return sum;
}
