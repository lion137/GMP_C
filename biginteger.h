#ifndef biginteger_h
#define biginteger_h

#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
 class biginteger{
	public:
	mpz_t x;
	biginteger(mpz_t n){
		mpz_init(x);
		mpz_set(x, n); 
	}
	biginteger(unsigned long long int a){
		mpz_init(x);
		mpz_set_ui(x, a);
	}
	biginteger(signed long int a){
		mpz_init(x);
		mpz_set_si(x, a);
	}
	biginteger(int a){
		mpz_init(x);
		mpz_set_si(x, a);
	}
	biginteger(const char *str, int base){
		mpz_init_set_str(x, str, base);
	}	
	
void deleteBiginteger();
void printbiginteger();
biginteger& operator += (const unsigned long long int& a);
biginteger& operator += (const signed long int& a);
biginteger& operator += (const biginteger& a);
biginteger& operator -= (const unsigned long long int& a);
biginteger& operator -= (const signed long int& a);
biginteger& operator -= (const biginteger& a);
biginteger& operator *= (const unsigned long long int& a);
biginteger& operator *= (const signed long int& a);
biginteger& operator *= (const biginteger& a);
biginteger& operator /= (const unsigned long long int& a);
biginteger& operator /=(const signed long int& a);
biginteger& operator /=(const biginteger& a);
biginteger abs();
biginteger power(unsigned long long int& a);
biginteger mod(const biginteger& a);
biginteger mod(const unsigned long long int& a);

char * mpz_get_str(char *str, int base, const mpz_t a);

biginteger mod(biginteger a, biginteger b);
biginteger mod(biginteger a, unsigned long long int b);

		};
		// + and - methods
	inline biginteger operator +(biginteger lhs, const biginteger&  rhs){
		biginteger sum = biginteger(lhs.x);
		sum += rhs;
		return sum;
	}
	inline biginteger operator +(const unsigned long long int& a, biginteger b){
		biginteger sum = biginteger(b.x);
		sum += a;
		return sum;
	}
	inline biginteger operator +(biginteger b, const unsigned long long int& a){
		biginteger sum = biginteger(b.x);
		sum += a;
		return sum;
	}
	inline biginteger operator +(const signed long int& a, biginteger b){
		biginteger sum = biginteger(b.x);
		sum += a;
		return sum;
	}
	
	inline biginteger operator +(biginteger b, const signed long int& a){
		biginteger sum = biginteger(b.x);
		sum += a;
		return sum;
	}
	
	
	
	
	inline biginteger operator -(biginteger lhs, const biginteger& rhs){
		biginteger dif = biginteger(lhs.x);
		dif -= rhs;
		return dif;
	}
	inline biginteger operator -(const unsigned long long int& a, biginteger b){
		mpz_neg (b.x, b.x);
		biginteger dif = biginteger(b.x);
		dif += a;
		return dif;
	}
	inline biginteger operator -(biginteger b, const unsigned long long int& a){
		biginteger dif = biginteger(b.x);
		dif -= a;
		return dif;
	}
	inline biginteger operator -(const signed long int& a, biginteger b){
		mpz_neg (b.x, b.x);
		biginteger dif = biginteger(b.x);
		dif += a;
		return dif;
	}
	inline biginteger operator -(biginteger b, const signed long int& a){
		biginteger dif = biginteger(b.x);
		dif -= a;
		return dif;
	}
	
		
	// * and / methods
	inline biginteger operator *(biginteger lhs, const biginteger& rhs){
		biginteger mul = biginteger(lhs.x);
		mul *= rhs;
		return mul;
	}
	inline biginteger operator *(const unsigned long long int& a, biginteger b){
		biginteger mul = biginteger(b.x);
		mul *= a;
		return mul;
	}
	inline biginteger operator *(biginteger b, const unsigned long long int& a){
		biginteger mul = biginteger(b.x);
		mul *= a;
		return mul;
	}
	inline biginteger operator *(const signed long int& a, biginteger b){
		biginteger mul = biginteger(b.x);
		mul *= a;
		return mul;
	}
	inline biginteger operator *(biginteger b, const signed long int& a){
		biginteger mul = biginteger(b.x); 
		mul *= a;
		return mul;
	}
	
	
	inline biginteger operator /(biginteger b, const biginteger& a){
		biginteger div = biginteger(b.x);
		div /= a;
		return div;
	}
	inline biginteger operator /(const unsigned long long int& a, biginteger b){
		biginteger div = biginteger(b.x);
		biginteger den = biginteger(a);
		den /= div;
		return den;
	}
	inline biginteger operator /(biginteger& b, const unsigned long long int& a){
		biginteger div = biginteger(b.x);
		div /= a;
		return div;
	}
	inline biginteger operator /(const signed long int& a, biginteger b){
		biginteger div = biginteger(b.x);
		biginteger den = biginteger(a);
		den /= div;
		return den;
	}
	inline biginteger operator /(biginteger b, const signed long int& a){
		biginteger div = biginteger(b.x);
		div /= a;
		return div;
	}
	// == methods
	inline bool operator ==(const biginteger& b, const biginteger& a){
		 if (mpz_cmp (b.x, a.x) == 0) return true;
		 else return false;
	}
	inline bool operator ==(const biginteger& b, const unsigned long long int& a){
		if ( mpz_cmp_ui (b.x, a) == 0) return true; else return false;
	}
	inline bool operator ==(const unsigned long long int& a, const biginteger& b){
		if (  mpz_cmp_ui (b.x, a) == 0 ) return true; else return false;
	}
	inline bool operator ==(const biginteger& b, const signed long int& a){
		if (mpz_cmp_si (b.x, a) == 0) return true; else return false;
	}
	inline bool operator ==(const signed long int& a, const biginteger& b){
		if (mpz_cmp_si (b.x, a) == 0) return true; else return false;
	}
	// < and > methods
	inline bool operator >(const biginteger& b, const biginteger& a){
		 if (mpz_cmp (b.x, a.x) > 0) return true;
		 else return false;
	}
	inline bool operator >(const biginteger& b, const unsigned long long int& a){
		 if (mpz_cmp_ui (b.x, a) > 0) return true;
		 else return false;
	}
	inline bool operator >(const unsigned long long int& a, const biginteger& b){
		if (  mpz_cmp_ui (b.x, a) < 0 ) return true; else return false;
	}
	inline bool operator >(const biginteger& b, const signed long int& a){
		if (mpz_cmp_si (b.x, a) > 0) return true; else return false;
	}
	inline bool operator >(const signed long int& a, const biginteger& b){
		if (mpz_cmp_si (b.x, a) < 0) return true; else return false;
	}
	
	inline bool operator <(const biginteger& b, const biginteger& a){
		 if (mpz_cmp (b.x, a.x) < 0) return true;
		 else return false;
	}
	inline bool operator <(const biginteger& b, const unsigned long long int& a){
		 if (mpz_cmp_ui (b.x, a) < 0) return true;
		 else return false;
	}
	inline bool operator <(const unsigned long long int& a, const biginteger& b){
		if (  mpz_cmp_ui (b.x, a) > 0 ) return true; else return false;
	}
	inline bool operator <(const biginteger& b, const signed long int& a){
		if (mpz_cmp_si (b.x, a) < 0) return true; else return false;
	}
	inline bool operator <(const signed long int& a, const biginteger& b){
		if (mpz_cmp_si (b.x, a) > 0) return true; else return false;
	}
	// unsigned long power unsigned long
	inline biginteger power(unsigned long long int& a, unsigned long long int& b){
		mpz_t tmp;
		mpz_init(tmp);
		mpz_ui_pow_ui (tmp, a, b);
		return tmp;
	}
	
	inline  int isPrime(unsigned long long int a){
	mpz_t number;
	mpz_init(number);
	mpz_set_ui(number, a);
	return(mpz_probab_prime_p (number, 70));
	}
	
	
int isPrime(biginteger a){
	return(mpz_probab_prime_p (a.x, 70));
	}
	
#endif
