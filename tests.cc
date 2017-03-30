
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <gmp.h>
#include "biginteger.h"
#include "biginteger.cc"
#include "bigrational.cc"
#include "bigrational.h"
#include <algorithm>
#include <string>


using namespace std;


int main() {
	
	bigrational r1 = bigrational(3, 7);
	r1.printbigrational();
	invert(add(r1, r1)).printbigrational();
	
	
	
	
	
	
	
	
	/*char str1[10] = "999999999999";
	string s1;
	s1 = "99999";
	int a = 1100;
	//cout << s1<<endl;
	//biginteger x = biginteger(s1, 10);
	biginteger sum = biginteger(str1, 10);
	for (unsigned long long int i = 0; i < 1000000; ++i){
		sum += i;
	}
	//sum.printbiginteger();
	sum.power(a).printbiginteger();
	//mpz_t sum, x;
	
	//mpz_init_set_str(sum, "0", 10);
	//mpz_init(x);
	//mpz_init_set_str(x, "9999999", 10);
	
	/*for (unsigned long long int  i = 0; i < 1000000000; ++i){
		mpz_set_ui(x, i);
		mpz_add(sum, sum, x);
	}
	gmp_printf("sum = %Zd", sum);
	std::cout << std::endl;*/
	//char str1[10] = "999";
	//biginteger x = biginteger(str1, 10);
	
	//for (int i = 0; i < 200; ++i)
	//x *= x;
	
	
	
}
