#include <iostream>
#include <cmath>
#include <array>

using namespace std;

template<size_t n>
class Seidel {
public:
	Seidel(array<array<double, n>, n> matrix, array<double, n> members, const double eps = 0.00000000000000001) :
	eps(eps), matrix(matrix), members(members) {}

	array<double, n> solve() {
		array<double, n> x = {}, p = {};
		if (!diagonal(matrix)) throw runtime_error("диагональное преобладание не выполняется");

		fill(x.begin(), x.end(), 1);

		do {
			for (int i = 0; i < n; i++)
				p[i] = x[i];
			for (int i = 0; i < n; i++) {
				double v = 0;
				for (int j = 0; j < n; j++)
					if (i != j) v += (matrix[i][j] * x[j]);

				x[i] = (members[i] - v) / matrix[i][i];
			}
		} while (!check(x, p));

		return x;
	}

private:
	const double eps;
	array<array<double, n>, n> matrix;
	array<double, n> members;

	bool check(array<double, n> xk, array<double, n> xkp) {
		double norm = 0;
		for (int i = 0; i < n; i++)
			norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
		return sqrt(norm) < eps;
	}

	bool diagonal(array<array<double, n>, n> a) {
		bool k = true;
		for (int i = 0; i < n; i++) {
			double s = 0;
			for (int j = 0; j < n; j++) s += fabs(a[i][j]);
			s -= fabs(a[i][i]);
			if (s >= fabs(a[i][i])) k = false;
		}
		return k;
	}
};


