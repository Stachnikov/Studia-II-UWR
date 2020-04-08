#include <iostream>
#include <iterator>
#include <iomanip>
#include <vector>


using namespace std;

int main(){
	std::string line;
	std::getline(std::cin,line);
	std::istringstream stream(line);
	
	cout << fixed;
	cout << setprecision(3);
	vector<float> real_v=vector<float> (istream_iterator<float>(stream), istream_iterator<float>());
	copy(real_v.rbegin(), real_v.rend(), ostream_iterator<float>(cout, "\n"));
	
	return 0;
}
