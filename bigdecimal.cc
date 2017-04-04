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

// -= operators:

bigdecimal& bigdecimal::operator -= (const unsigned long int& a){
	mpf_sub_ui (this->x, x, a);
	return *this;
}


