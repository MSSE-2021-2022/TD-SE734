/*
* Programme à tester sur la carte
* TODO: Absolument besoin de faire une version récursive ?
*/

#include <stdint.h>

uint32_t a;
uint32_t b;
uint32_t c;

uint32_t fibo(uint32_t n) {
	uint32_t out = 0;
	if(n < 2)
		return n;
	
	for(uint32_t i = 0; i < n - 1; i++) {
		out += i;
	}

	return out;
}

int main() {
	uint32_t o = fibo(8);
	return o;
}
