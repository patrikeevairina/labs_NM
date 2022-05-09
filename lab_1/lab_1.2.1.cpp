#include <iostream>
#include <cmath>

double f(double d)
{
	return d * d * d - 0.2 * d * d + 0.5 * d - 1.4;
}

double lf(double d)
{
	return d - 0.15037593984962405 * f(d);
}

const double e = 0.001;
int main()
{
	double rg = 0, lg = 1.5, x, last;
	int i = 1;

	x = (lg - rg) / 2;
	do {
		last = x;
		x = lf(last);
		printf("%i. x = %f; epsilon = %f\n", i++, x, fabs(x - last));
	} while (fabs(x - last) > e);
	printf("Answer: %f; epsilon = %f\n", x, fabs(x-last)); 
	return 0;
}

