#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
	
	/*mpz_t dec(mpz_t x){
		mpz_t T[1];
		//mpz_t zwrot;
		mpz_init(T[1]);
		mpz_sub(T[0], x, 1);
		return T;
		}

	mpz_t power(mpz_t x, mpz_t y){
		mpz_t zwrot;
		mpz_init(zwrot);
		if(y==1) return x;
			else
			
			mpz_mul(zwrot, x, power(x, dec(y)));
			return zwrot;
	}*/ 

int main(){
	
	mpz_t x, y, z, wynik;
	mpz_init_set_str(x, "247092", 10);
	mpz_init_set(y, x);
	mpz_init_set_str(z, "999999", 10);
	mpz_init(wynik);
	mpz_mul(wynik, y, z);
	//gmp_printf("%Zd\n"	, wynik);
	
	unsigned long int * r = malloc(240000001 * sizeof(unsigned long long int));
	if(malloc(240000001 * sizeof(unsigned long int)) == NULL) 
	{
		printf("malloc failed\n");
			return(-1);
	}
	mpz_t t, s, v, r0, r1, r2;	
	mpz_init(t);
	mpz_init(s); 
	mpz_init(v);
	mpz_init_set_str(r0, "0", 10); 
	mpz_init_set_str(r1, "0", 10); 
	mpz_init_set_str(r2, "1", 10);
	r[0] = 0;
	r[1] = 0;
	r[2] = 1;
	
		for(unsigned long int i = 3; i < 30000; ++i){
			mpz_add(v, r0, r1);
			mpz_add(s, v, r2);
			mpz_mod_ui(t, s, 10000000);
			r[i] = mpz_get_ui(t);
			mpz_set(r0, r1);
			mpz_set(r1, r2);
			mpz_set(r2, s);
			}
	for(unsigned long int i = 2000; i < 2500; ++i){
			
	printf("%lu\n", r[i]);
	}
	//printf("%lu\n", r[12] - r[11]);
	free(r);
	}
