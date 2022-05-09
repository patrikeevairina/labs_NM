#include <iostream>
#include <cmath>
#include <array>

using namespace std;

template<size_t n>
class Kramer {
public:
	Kramer(array<array<double, n>, n> matrix, array<double, n> members) : matrix(matrix), members(members) {};
	array<double, n> solve() {
		array<array<double, n>, n> a2 = {};
		array<double, n> array = {};

		double d = det(matrix, n);
		if (d == 0.0) throw runtime_error("определитель равен нулю");

		for (int i = 0; i < n; ++i) {
			for (int i2 = 0; i2 < n; ++i2)
				for (int j2 = 0; j2 < n; ++j2)
					a2[i2][j2] = matrix[i2][j2];
			for (int j = 0; j < n; ++j) {
				a2[j][i] = members[j];
			}
			array[i] = det(a2) / d;
		}
		return array;
	}
private:
	array<array<double, n>, n> matrix;
	array<double, n> members;

	double det(array<array<double, n>, n> a, int vn = n) {
		if (vn == 2) {
			return (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
		}
		array<array<double, n>, n> a2 = {};
		double d = 0;
		for (int l = 0; l < vn; l++) {
			int l2 = 0;
			for (int i = 1; i < vn; i++) {
				int i2 = 0;
				for (int j = 0; j < vn; j++) {
					if (j != l) {
						a2[l2][i2] = a[i][j];
						i2++;
					}
				}
				l2++;
			}
			d += pow(-1, l) * a[0][l] * det(a2, vn - 1);
		}

		return d;
	}
};


