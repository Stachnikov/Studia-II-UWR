#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>
#include <fstream>


using namespace std;

uint64_t  phi(uint64_t n) // phi Euler  function
{
	uint64_t result = n;
	for (uint64_t  p=2; p*p<n; p++)
	{
		if (n%p==0)
		{
			while (n % p == 0) 
                n /= p; 
			result *= (1.0 - (1.0/p));
		}
	}
	
	if (n > 1) 
        result *= (1.0 - (1.0 / (float)n)); 
  
    return (int)result; 
}

vector<uint64_t> phi_vec(uint64_t k){
	vector<uint64_t> v;
	for(uint64_t i=1; i<=k;i++)
		v.push_back(phi(i));
	
	return v;
}


int main(){
	std::cout<<" Podaj k = \n";
	uint64_t k;
	std::cin >> k;
	 
	vector<uint64_t> result_vec = phi_vec(k);
	 
	std::ofstream file("phi.txt");
	copy(result_vec.begin(), result_vec.end(), ostream_iterator<uint64_t>(file, "; "));
	return 0;
}
