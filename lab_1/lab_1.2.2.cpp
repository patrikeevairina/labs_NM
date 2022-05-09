#include <iostream>
#include "cmath"

const double e = 0.001;
int main() {
	double x = 3.5, lambda = 0.33333333333333, last;
	int i = 1;
	do {
		last = x;
		x -= lambda * (5 * x - 8 * log(x) - 8);
		printf("%i. x = %f; epsilon = %f\n", i++, x, fabs(x - last));
	} while (fabs(x - last) > e);
	printf("Answer: %f, epsilon: %f\n", x, fabs(x-last));
	return 0;
}

