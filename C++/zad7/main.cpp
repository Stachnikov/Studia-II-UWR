#include "definitions.hpp"

//using namespace Obliczenia;

int main(int argc, char** argv) {
	
	int Ro= 5;
	Macierz test(Ro);
	Macierz copytest(test);	
    test += test;
    test *= test;
    test *= test;
    test *= test;
    
	std::cout<< "TEST COPY\n";
	for(int i = 0; i < Ro; i++)
	{
		for(int j=0; j < Ro; j++)
			std::cout<< copytest.tab2d[i][j] <<"\t";
		std::cout << std::endl;
	}
	
	copytest= copytest.operator~();
	
		std::cout<< "TEST COPY\n";
	for(int i = 0; i < Ro; i++)
	{
		for(int j=0; j < Ro; j++)
			std::cout<< copytest.tab2d[i][j] <<"\t";
		std::cout << std::endl;
	}
	std::cout<< "TEST\n";
	
	for(int i = 0; i < Ro; i++)
	{
		for(int j=0; j < Ro; j++)
			std::cout<< test.tab2d[i][j] <<"\t";
		std::cout << std::endl;
	}
	
	return 0;
}
