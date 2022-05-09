#include <iostream>
#include <cmath>
#include <vector>

#define LENGTH 9
#define VARIANT 12

using namespace std;

double newtonF(vector<vector<long double>> y, vector<double> x, double point)
{
	vector<long double> diff_coef;	
	diff_coef.push_back(y[0][0]);

	for(size_t i = 1; i < LENGTH; ++i)
	{
		for(size_t j = 0; j < LENGTH - i; ++j)
		{	
			long double buf = (y[j + 1][i - 1] - y[j][i - 1])
                                                 / (x[j+i] - x[j]); 
			y[j].push_back(buf);
			if(!j)
				diff_coef.push_back(y[j][y[j].size() - 1]);
		}
	}
	/*for(int i = 0; i < LENGTH; ++i)
	{
		for(int j = 0; j < LENGTH - i; ++j)
		{
			cout <<  fixed << y[i][j] << "\t\t";
		}
		cout << endl;
	}*/
	
	long double sum = 0.0;
	for(size_t i = 0; i < LENGTH; ++i)
	{
		long double buf = diff_coef[i];
		for(size_t j = 0; j < i; ++j)
			buf *= point - x[j];
		sum += buf;
	}
	return sum;
}

int main()
{
	std::vector<double> x;
	x.push_back(0.593);
	x.push_back(0.598);
	x.push_back(0.605);
	x.push_back(0.613);
	x.push_back(0.619);
	x.push_back(0.627);
	x.push_back(0.632);
	x.push_back(0.640);
	x.push_back(0.650);
	
	std::vector<vector<long double> > y;
	y.resize(9);
	y[0].push_back(0.532050);
	y[1].push_back(0.535625);
	y[2].push_back(0.540598);
	y[3].push_back(0.546235);
	y[4].push_back(0.550431);
	y[5].push_back(0.555983);
	y[6].push_back(0.559428);
	y[7].push_back(0.568738);
	y[8].push_back(0.575298);
	
	cout << "x\ty\n";
	for(size_t i = 0; i < LENGTH; ++i)
	{
		cout << x[i] << '\t' << y[i][0] << endl;
	}
	
	vector<double> arg_Newton;
	for(int i = 9; i <= VARIANT * 3; ++i)
		arg_Newton.push_back(0.609 + 0.002 * i);

	cout << "Newton: x\ty\n";
	for(int i = 0; i < arg_Newton.size(); ++i)
		cout << '\t' << arg_Newton[i] << '\t' << newtonF(y, x, arg_Newton[i]) << endl;
		
	vector<double> arg_Lagrange;
	for(int i = 5; i <= VARIANT * 3; ++i)
		arg_Lagrange.push_back(0.629 + 0.003 * i);	

	return 0;
}
