#include <iostream>
#include <cmath>

const double e = 0.001;

double f(double x)
{
	return x * log10(x) - 1.2;
}
double f2(double x)
{
	return x * x * x - 0.1 * x * x + 0.4 * x - 1.5;
}

double df2(double x)
{
	return 3 * x * x - 0.2 * x + 0.4;
}
int main()
{
	double x = 2, xp = 3;
	int i = 1;
	printf("Метод хорд\n");
	while (fabs(x - xp) > e)
	{
		xp = x;
		x = x - ((x - 3) * f(x)) / (f(x) - f(3));
		printf("%i. x = %f; epsilon = %f\n", i++, x, fabs(f(x)));
	}
	printf("Answer: %f, epsilon = %f\n", x, fabs(f(x)));
	i = 1;
	printf("\nМетод касательных\n");
	double t = 0;
	x = 1;
	while (fabs(x - t) > e)
	{
		t = x;
		x = x - f2(x) / df2(x);
		printf("%i. x = %f; epsilon = %f\n", i++, x, fabs(x - t));
	}
	printf("Answer: %f, epsilon = %f\n", x, fabs(x - t));
	return 0;
}

