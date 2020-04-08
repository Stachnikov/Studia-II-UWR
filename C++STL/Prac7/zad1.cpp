#include <iostream>
#include <complex>

using namespace std;

const double EM = 0.5772156649;

complex<double> Euler_f(complex<double> z, int iterat)
{
	complex<double> result = 1.0 ;
	for (int n = 1; n<= iterat; n++)
	{
		auto const_n = double(n);
		result *= (pow(1.0+1.0/const_n,z))/(1.0+ (z / const_n));
	}
	return result / z;
}

complex<double> I_Euler_f(complex<double> z, int iterat)
{
	complex<double> result = 1.0 ;
	for (int n = 1; n<= iterat; n++)
	{
		auto const_n = double(n);
		result *= ((1.0+z/const_n)*exp(-z/const_n));
	}
	return result * z * exp(z*EM);
}

int main(){
	
	complex<double> z = complex<double>(1.0,1.0);
	
	cout << Euler_f(z , 100) << endl;
	cout << I_Euler_f(z, 100) << endl;
	return 0;
}
