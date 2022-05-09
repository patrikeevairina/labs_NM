#include <iostream>
#include <chrono>
#include "lab_2.1.cpp"
#include "lab_2.2.cpp"

using std::chrono::high_resolution_clock;
using std::chrono::duration;

const int n = 4;
const int iterations = 10000;
int main() {
	array<array<double, n>, n> matrix =
			{{
					 { 3, -0.5, 0.5, -1 },
					 { 1, 5, -1, -2 },
					 { 2, -1, 4, -0.5 },
					 { 1, 2, -1, 5 },
			 }};
	array<double, n> members = { 2.5, -8, 20, 42 };

	{
		printf("Расчёт методом Крамера.\n");
		auto t = high_resolution_clock::now();

		auto k = Kramer<n>(matrix, members);
		for (int i = 0; i < iterations; ++i) {
			k.solve();
		}

		duration<double, std::milli> d = high_resolution_clock::now() - t;
		printf("Время расчёта %fms\n", d.count());

		auto s = k.solve();
		for (int i = 0; i < n; i++) printf("x%i = %.17g\n", i, s[i]);
	}
	{
		const double eps = 0.00000000000000001;

		printf("\nРасчёт методом Зейделя. Погрешность = %.17f\n", eps);
		auto t = high_resolution_clock::now();

		auto k = Seidel<n>(matrix, members, eps);
		for (int i = 0; i < iterations; ++i) {
			k.solve();
		}

		duration<double, std::milli> d = high_resolution_clock::now() - t;
		printf("Время расчёта %fms\n", d.count());

		auto s = k.solve();
		for (int i = 0; i < n; i++) printf("x%i = %.17g\n", i, s[i]);
	}
	{
		const double eps = 0.00000001;

		printf("\nРасчёт методом Зейделя. Погрешность = %.8f\n", eps);
		auto t = high_resolution_clock::now();

		auto k = Seidel<n>(matrix, members, eps);
		for (int i = 0; i < iterations; ++i) {
			k.solve();
		}

		duration<double, std::milli> d = high_resolution_clock::now() - t;
		printf("Время расчёта %fms\n", d.count());

		auto s = k.solve();
		for (int i = 0; i < n; i++) printf("x%i = %.17g\n", i, s[i]);
	}
	{
		const double eps = 0.1;

		printf("\nРасчёт методом Зейделя. Погрешность = %.1f\n", eps);
		auto t = high_resolution_clock::now();

		auto k = Seidel<n>(matrix, members, eps);
		for (int i = 0; i < iterations; ++i) {
			k.solve();
		}

		duration<double, std::milli> d = high_resolution_clock::now() - t;
		printf("Время расчёта %fms\n", d.count());

		auto s = k.solve();
		for (int i = 0; i < n; i++) printf("x%i = %.17g\n", i, s[i]);
	}
	return 0;
}

