#include <iostream>
#include <cmath>
#include <vector>

#define LENGTH 15
#define VARIANT 12

using namespace std;

double _p(double p, int n)
{
	auto buf = p; 
	for(size_t i = 1; i < n; ++i)
	{
		if(i % 2 == 1)
			buf * (p - i);
		else
			buf * (p + i);
	}
	return buf;
}

int factorial(int x)
{
	if(!x) return 1;
	return x*factorial(x-1);
}
	
double gaussF(vector<vector<double>> y, vector<double> x, double point)
{
	int align = LENGTH / 2;
	auto sum = y[align][0];
	double p = (point - x[align]) / (x[1] - x[0]);
	for(size_t i = 1; i < LENGTH; ++i)
		sum += (_p(p, i) * y[(LENGTH - i) / 2][i]) / factorial(i);
	return sum;
}

double stirlingF(vector<vector<double>> y, vector<double> x, double point)
{
	int align = LENGTH / 2;
	double p = (point - x[align]) / (x[1] - x[0]);
	double buf1 = 1.0; double buf2 = 1.0; 
	int k = 1;
	int l = 1;
	long int d = 1;
	double y_p = y[align][0];
	for(size_t i = 1; i < LENGTH; ++i)
	{
		if(i % 2)
		{
			if(k != 2)
			{
				buf1 *= (pow(p, k) - pow((k - 1), 2));
			}	
			else
			{
				buf1 *= (pow(p, 2) - pow((k - 1), 2));
			}
			++k;
			d *= i;
			y_p += (buf1 / (2 * d)) * (y[align][i] + y[align - 1][i]);
			align = (LENGTH - i) / 2;
		}
		else
		{
			buf2 *= (pow(p, 2) - pow((l - 1), 2));
			++l;
			d *= i;
			align = (LENGTH - i) / 2;
			y_p += (buf2 / d) * (y[align][i]);
		}
	}
	return y_p;
}

int main()
{
	std::vector<double> x;
	for(size_t i = 0; i < LENGTH; ++i)
		x.push_back(1.5 + 0.05 * i);
	
	std::vector<vector<double> > y;
	y.resize(LENGTH);
	y[0].push_back(15.132);
	y[1].push_back(17.422);
	y[2].push_back(20.393);
	y[3].push_back(23.994);
	y[4].push_back(28.160);
	y[5].push_back(32.812);
	y[6].push_back(37.857);
	y[7].push_back(43.189);
	y[8].push_back(48.689);
	y[9].push_back(54.225);
	y[10].push_back(59.158);
	y[11].push_back(64.817);
	y[12].push_back(69.550);
	y[13].push_back(74.782);
	y[14].push_back(79.548);
		
	
	for(size_t i = 1; i < LENGTH; ++i)
	{
		//cout << x[i] << '\t';
		for(size_t j = 0; j < LENGTH - i; ++j)
		{
			y[j].push_back(y[j+1][i - 1] - y[j][i - 1]);
		}
		//cout << endl;
	}
	
	for(size_t i = 1; i < LENGTH; ++i)
	{
		cout << x[i] << '\t';
		for(size_t j = 0; j < LENGTH - i; ++j)
		{
			cout << y[i][j] << '\t';
		}
		cout << endl;
	}
	
	double arg_Gauss = 1.60 + 0.006 * VARIANT;
	cout << "Gauss: " << arg_Gauss << " " << fixed << gaussF(y, x, arg_Gauss) << endl;
	double arg_Stirling = 1.725 + 0.002 * VARIANT;
	cout << "Stirling: " << arg_Stirling << " " << fixed << stirlingF(y, x, arg_Stirling) << endl;
	double arg_Bessel = 1.83 + 0.003 * VARIANT;

	return 0;

}
