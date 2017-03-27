//biginteger.cc
#include "biginteger.h"
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>

void biginteger::deleteBiginteger(){
	std::cout << "sprzatam bigintegera"; std::cout << std::endl;
	mpz_clear(x);
}
void biginteger::printbiginteger(){
	gmp_printf("%Zd\n", this->x); //std::cout <<std::endl;
}
// overloaded += operators
biginteger& biginteger::operator += (const unsigned long long int& a){
	mpz_add_ui(this->x, x, a);
	return *this;
}
biginteger& biginteger::operator += (const signed long int& a){
	if (a < 0) {
		signed long int tmp1 = -a;
		unsigned long long int tmp2 = tmp1;
		mpz_sub_ui(this->x, x, tmp2);
		return *this;
	}
	else{
		unsigned long long int t1 = (unsigned long long int) a;
		mpz_add_ui(this->x, x, t1);
		return *this;
	}
}
biginteger& biginteger::operator += (const biginteger& a){
	mpz_add(this->x, this->x, a.x);
	return *this;
}
// overloaded -= operators
biginteger& biginteger::operator -= (const unsigned long long int& a){
	mpz_sub_ui (this->x, x, a);
	return *this;
}
biginteger& biginteger::operator -= (const signed long int& a){
	if (a < 0){
		signed long int tmp1 = -a;
		unsigned long long int tmp2 = tmp1;
		mpz_add_ui(this->x, x, tmp2);
		return *this;
	}
	else{
		unsigned long long int t1 = (unsigned long long int) a;
		mpz_sub_ui(this->x, x, t1);
		return *this;
	}
}
biginteger& biginteger::operator -= (const biginteger& a){
	mpz_sub(this->x, x, a.x);
	return *this;
}
//overloaded *= operators
biginteger& biginteger::operator *=(const unsigned long long int& a){
	mpz_mul_ui(this->x, x, a);
	return *this;
}
biginteger& biginteger::operator *=(const signed long int& a){
	mpz_mul_si(this->x, x, a);
	return *this;
}
biginteger& biginteger::operator *=(const biginteger& a){
	mpz_mul(this->x, x, a.x);
	return *this;
}
// overloaded /= operators
biginteger& biginteger::operator /=(const unsigned long long int& a){
	if (a == 0) throw "Division by zero in overloaded /=(const unsigned long long int&)";
	mpz_tdiv_q_ui (this->x, this->x, a);
	return *this;
}
biginteger& biginteger::operator /=(const signed long int& a){
	if (a == 0) throw " Division by zero in overloaded /=(const signed long int&)";
	if (a < 0) {
		signed long int tmp1 = -a;
		unsigned long long int tmp2 = tmp1;
		mpz_tdiv_q_ui (this->x, this->x, tmp2);
		mpz_neg(this->x, this->x);
		return *this;
	}
	else{
		unsigned long long int t1 = (unsigned long long int) a;
		mpz_tdiv_q_ui(this->x, x, t1);
		return *this;
	}
}
biginteger& biginteger::operator /=(const biginteger& a){
	mpz_tdiv_q(this->x, this->x, a.x);
	return * this;
} 

//overloaded %= operator
 biginteger& biginteger::operator %=(const biginteger& a){
	 //Function: void mpz_mod (mpz_t r, const mpz_t n, const mpz_t d)
	 mpz_mod(this->x, this->x, a.x);
	 return * this;
}
biginteger biginteger::abs(){
	biginteger tmp = biginteger(this->x);
	mpz_abs (tmp.x, this->x);
	return tmp;
}
biginteger biginteger::power(unsigned long long int& a){
	biginteger tmp = biginteger(this->x);
	mpz_pow_ui (tmp.x, this->x, a);
	return tmp;
}
biginteger biginteger::mod(const biginteger& a){
	biginteger tmp = biginteger(this->x);
	 mpz_mod (tmp.x, this->x, a.x);
	 return tmp;
}
biginteger biginteger::mod(const unsigned long long int& a){
	biginteger tmp = biginteger(this->x);
	 mpz_mod_ui (tmp.x, this->x, a);
	 return tmp;
}


 
 
 
 
 
 



