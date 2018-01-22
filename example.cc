#include <cstdlib>
#include <iostream>
#include <fstream>
#include <tuple>
#include <gmp.h>
#include "biginteger.h"
#include "biginteger.cc"
#include "bigrational.cc"
#include "bigrational.h"
#include <algorithm>
#include <string>
#include <climits>


int main() {
	
	
{
std::string a;
std::ifstream plik;
plik.open("test.txt");
biginteger * l =new biginteger("1",10);
biginteger * y =new biginteger("0",10);
for(int k=0;k<99999;k++)
{
plik>>a;
biginteger * x =new biginteger(a.c_str(),10);
*y=*l*(*x);
*l=*y;
x->deleteBiginteger();
delete x;
x = NULL;
}


y->printbiginteger();



return 0;
}
	
	
	
	
	
	
	
	biginteger * a = new biginteger(10);
	biginteger * b = new biginteger(10);
	biginteger * c = new biginteger(10);
	for (long long i = 0; i < 99999999;i++){
	*c = (*a + (*b));
	c->deleteBiginteger();
	*c = (*a * (*b));
	c->deleteBiginteger();
	*c = (*a - (*b));
	c->deleteBiginteger();
	*c = (*a * (*b));
	c->deleteBiginteger();
	*c = (*a / (*b));
	c->deleteBiginteger();
	*c = (*a * (*b));
	c->deleteBiginteger();
	*c = (*a % (*b));
	c->deleteBiginteger();
	
	
	}
	 
	a->deleteBiginteger();
	b->deleteBiginteger();
	
	return 0;
}
