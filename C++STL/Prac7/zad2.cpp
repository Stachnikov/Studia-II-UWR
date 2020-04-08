#include <iostream>
#include <complex>
#include <fstream>
using namespace std;

complex<double> dzeta(complex<double> z, int iterat)
{
	complex<double> result = 0.0 ;
	for (int n = 1; n<= iterat; n++)
	{
		auto const_n = double(n);
		result += pow((1.0/const_n),z);
	}
	return result;
}

int main(){
	ofstream file("dzeta.csv");
	complex<double> z = complex<double>(0.5,1.0);
	complex<double> dzeta_val = complex<double>(0.5,1.0);
	
	for(double i = -25; i<= 25;i+= 0.1){
		z.imag(i);
		dzeta_val = dzeta(z,100);
		file << dzeta_val.real() << ';' << dzeta_val.imag() << endl;
	}

	
	file.close();
	return 0;
}
