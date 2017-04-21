//plik z funkcjami bigdecimal:

#include "bigdecimal.h"
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
#include <climits>

void bigdecimal::printbigdecimal(int num_digits){
	mpf_out_str(stdout, 10, num_digits, this ->x); std::cout <<std::endl;
}

void bigdecimal::deleteBigdecimal(){
	mpf_clear (x);
}

bigdecimal::~bigdecimal(void){
	mpf_clear (x);
	std::cout << "delete bigdecimal";std::cout <<std::endl;
}

//unary operators:
// - 

bigdecimal& bigdecimal::operator - () {
	mpf_neg(this->x, this->x);//set left mpf_t var to -right
	return *this;
}

// += operators:
bigdecimal& bigdecimal::operator +=(const unsigned  long int& a){
	 mpf_add_ui (this->x, x, a);
	 return *this;
}

bigdecimal& bigdecimal::operator +=(const int& a){
	if (a < 0){
		signed long int tmp = -a;
		unsigned long  int tmp2 = tmp;
		mpf_sub_ui(this->x, x, tmp2);
		return *this;
	}
	else{
		unsigned long  int t1 = (unsigned  long int) a;
		mpf_add_ui(this -> x, x, t1);
		return *this;
	}
}

bigdecimal& bigdecimal::operator += (const bigdecimal& a){
	mpf_add(this->x, this->x, a.x);
	return *this;
}

bigdecimal& bigdecimal::operator += (const biginteger& a){
	bigdecimal tmp = bigdecimal(this->x);
	mpf_set_z (tmp.x, a.x);
	*this += tmp;
	return *this;
}

// -= operators:

bigdecimal& bigdecimal::operator -= (const unsigned long int& a){
	mpf_sub_ui (this->x, x, a);
	return *this;
}

bigdecimal& bigdecimal::operator -= (const int& a){
	if (a < 0) {
		signed long int tmp = -a;
		unsigned long int tmp2 = tmp;
		mpf_add_ui(this->x, x, tmp2);
		return *this;
	}
	else{
		unsigned long int t1 = (unsigned long int) a;
		mpf_sub_ui(this->x, x, t1);
		return *this;
	}
}

bigdecimal& bigdecimal::operator -= (const bigdecimal& a){
	mpf_sub(this->x, this->x, a.x);
	return *this;
}

bigdecimal& bigdecimal::operator -= (const biginteger& a){
	bigdecimal tmp = bigdecimal(this->x);
	mpf_set_z (tmp.x, a.x);
	*this -= tmp;
	return *this;
}


// *= operators: unsigned long ints, ints, bigdecimals, bigintegers

bigdecimal& bigdecimal::operator *= (const unsigned long int& a){
	mpf_mul_ui(this->x, x, a);
	return *this;
}

bigdecimal& bigdecimal::operator *= (const int& a){
		if (a < 0) {
			signed long int tmp = -a;
			unsigned long int tmp2 = tmp;
			mpf_mul_ui(this->x, x, tmp2);
			return -(*this);
		}
		else{
		unsigned long int t1 = (unsigned long int) a;
		mpf_mul_ui(this->x, x, t1);
		return *this;
		}
}

bigdecimal& bigdecimal::operator *= (const bigdecimal& a){
	mpf_mul(this->x, this->x, a.x);
	return *this;
}

bigdecimal& bigdecimal::operator *= (const biginteger& a){
	bigdecimal tmp = bigdecimal(this->x);
	mpf_set_z (tmp.x, a.x);
	*this *= tmp;
	return *this;
	
}

// /= operators, unsigned long ints, ints, bigdecimals, bigintegers
	
bigdecimal& bigdecimal::operator /= (const unsigned long int& a){
		mpf_div_ui (this->x, this->x, a);
		return *this;
}

bigdecimal& bigdecimal::operator /= (const int& a){
	if (a < 0){
		signed long int tmp1 = -a;
		unsigned long int tmp2 = tmp1;
		mpf_div_ui(this->x, this->x, tmp2);
		return -(*this);
	}
	else{
		unsigned long int t1 = (unsigned long int) a;
		mpf_div_ui(this->x, this->x, t1);
		return *this;
	}
	
}

bigdecimal& bigdecimal::operator /= (const bigdecimal& a){
	mpf_div(this->x, this->x, a.x);
	return *this;
}

bigdecimal& bigdecimal::operator /= (const biginteger& a){
	bigdecimal tmp = bigdecimal(this->x);
	mpf_set_z (tmp.x, a.x);
	*this /= tmp;
	return *this;
}




	


