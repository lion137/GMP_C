#ifndef bigdecimal_h
#define bigdecimal_h

#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
#include <climits>
#include "biginteger.h"
//#include "biginteger.cc"

class bigdecimal {
	public: mpf_t x;
	
	explicit bigdecimal(mpf_t y){
		 mpf_init_set (x, y);
	}
	
	explicit bigdecimal(unsigned long int y, mp_bitcnt_t prec){
		mpf_set_default_prec (prec);
		mpf_init_set_ui(x, y);
	}
	
	explicit bigdecimal(int y, mp_bitcnt_t prec){
		mpf_set_default_prec (prec);
		signed long int tmp = y;
		mpf_init_set_si(x, tmp);
	}
	
	explicit bigdecimal(const char  *str, int base, mp_bitcnt_t prec){//initalize bigdecimal to string with base base in form: MeN
		mpf_set_default_prec (prec);				// ex.: bigdecimal(char * str = 1e0, 64, 10) - creates bigdecimal 1
		mpf_init_set_str(x, str, base);											  
	}
	
	explicit bigdecimal(double y, mp_bitcnt_t prec){
		mpf_set_default_prec (prec);
		mpf_init_set_d(x, y);
	}
	
	explicit bigdecimal(biginteger y){
		mpf_init(x);
		mpf_set_z(x, y.x);
	}
	//print and delete:
	void deleteBigdecimal();
	void printbigdecimal(int = 16);
	~bigdecimal();
	
	//overloaded operators:
    // unary operators:
    // - 
    bigdecimal& operator - () ;
    
    // = operator
    void operator = (const bigdecimal& R ) { 
         mpf_set(x, R.x);
      }
    
	// += works for unsigned longs, ints, bigdecimal
	
	bigdecimal& operator += (const unsigned long  int& a);
	bigdecimal& operator += (const int& a);
	bigdecimal& operator += (const bigdecimal& a);
	bigdecimal& operator += (const biginteger& a);
	
	// -= - unsigned longs, ints, bigdecimals
	
	bigdecimal& operator -= (const unsigned long int& a);
	bigdecimal& operator -= (const int& a);
	bigdecimal& operator -= (const bigdecimal& a);
	bigdecimal& operator -= (const biginteger& a);
	
	// *= - unsigned longs, ints, bigdecimals, bigintegers
	bigdecimal& operator *= (const unsigned long int& a); 
	bigdecimal& operator *= (const int& a); 
	bigdecimal& operator *= (const bigdecimal& a); 
	bigdecimal& operator *= (const biginteger& a);
	
	// /= operators for unsigned longs, ints, bigdecimals, bigintegers:
	bigdecimal& operator /= (const unsigned long int& a); 
	bigdecimal& operator /= (const int& a); 
	bigdecimal& operator /= (const bigdecimal& a); 
	bigdecimal& operator /= (const biginteger& a);
	
	
	 
};


// overloaded binary operators:

// +

inline bigdecimal operator +(bigdecimal lhs,  bigdecimal& rhs){
	bigdecimal sum = bigdecimal(lhs.x);
	sum += rhs;
	return sum;
}

inline bigdecimal operator +(bigdecimal lhs, biginteger& rhs){
	bigdecimal sum = bigdecimal(rhs);
	sum += lhs;
	return sum;
}

inline bigdecimal operator +(biginteger& lhs, bigdecimal rhs){
	bigdecimal sum = bigdecimal(lhs);
	sum += rhs;
	return sum;
}

// - 

inline bigdecimal operator -(bigdecimal lhs, bigdecimal& rhs){
	bigdecimal sub = bigdecimal(lhs.x);
	sub -= rhs;
	return sub;
}

inline bigdecimal operator -(bigdecimal lhs, biginteger& rhs){
	bigdecimal sub = bigdecimal(lhs.x);
	bigdecimal sub1 = bigdecimal(rhs);
	sub +=  -sub1;
	return sub;
}

inline bigdecimal operator -(biginteger& lhs, bigdecimal rhs){
	bigdecimal sub = bigdecimal(lhs.x);
	sub += rhs;
	return sub;
}

#endif
