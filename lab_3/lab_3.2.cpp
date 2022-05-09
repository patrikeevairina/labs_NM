#include <iostream>
#include <cmath>
using namespace std;

double f1(double x, double y) {
	return tan(x * y + 0.4) - x * x;
}

double f2(double x, double y) {
	return 0.8 * x * x + 2 * y * y - 1;
}

const double eps = 0.001;
int main() {
	double x1 = 0.95, x2 = 0.35, px1, px2, fp, f2p,
	d1 = -0.134183,
	d2 = 0.145684,
	d3 = 0.164712,
	d4 = 0.815246;

	int i = 1;
	do {
		px1 = x1;
		px2 = x2;
		fp = f1(px1, px2);
		f2p = f2(px1, px2);
		x1 = px1 - d1 * fp - d2 * f2p;
		x2 = px2 - d3 * fp - d4 * f2p;
		printf("%i. x = %f; y = %f; epsilon = %f\n", i++, x1, x2, fmax(fabs(x1 - px1), fabs(x2 - px2)));
	} while (fmax(fabs(x1 - px1), fabs(x2 - px2)) > eps);
	printf("Answer: (%f, %f); epsilon = %f\n", x1, x2, fmax(fabs(x1-px1), fabs(x2-px2)));
}
