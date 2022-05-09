#include <iostream>
#include <cmath>

const double e = 0.001;

double f(double x)
{
	return 2 * x * x * x + 9 * x * x - 10;
}

double df(double x)
{
	return 6 * x * x + 18 * x;
}

double ddf(double x)
{
	return 12 * x + 18;
}
int main()
{
	double a = 0, b = 1;
	int i = 1;
	do {
		if (f(a) * ddf(a) < 0)
			a += (b - a) / (f(a) - f(b)) * f(a);
		else
			a -= f(a) / df(a);
		if (f(b) * ddf(b) < 0)
			b += (a - b) / (f(b) - f(a)) * f(b);
		else
			b -= f(b) / df(b);
		printf("%i. x = %f; epsilon = %f\n", i++, (a + b) / 2, fabs(a - b) / 2);
	} while (fabs(a - b) > 2 * e);
	printf("Answer: %f; epsilon = %f\n", (a+b)/2, fabs(a-b)/2);
	return 0;
}

