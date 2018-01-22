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
#include <climits>

int main() {
	
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
