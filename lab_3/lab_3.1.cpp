#include <cmath>
#include <stdio.h>
//#include <z3.h>
double f(double x, double y) {
	return sin(y) + 2 * x - 2;
}
double f2(double x, double y) {
	return cos(x-1)+y-0.7;
}

const double eps = 0.001;

int main() {
	double x1 = 1.15, x2 = -0.3, px1, px2, fp, f2p,
	lambda1 = -0.466687, lambda2 = 0.445844, lambda3 = -0.069742, lambda4 = -0.933373;
	int i = 1;

	do {
		px1 = x1;
		px2 = x2;
		fp = f(x1, x2);
		f2p = f2(x1, x2);
		x1 = px1 + lambda1 * fp + lambda2 * f2p;
		x2 = px2 + lambda3 * fp + lambda4 * f2p;
		printf("%i. x = %f; y = %f; epsilon = %f\n", i++, x1, x2, fmax(fabs(x1 - px1), fabs(x2 - px2)));
	} while (fmax(fabs(x1 - px1), fabs(x2 - px2)) > eps );
	printf("Answer: (%f, %f); epsilon = %f\n", x1, x2,  fmax(fabs(x1 - px1), fabs(x2 - px2)));
	return 0;
}

