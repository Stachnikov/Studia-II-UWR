#include <iostream>
#include <limits>
using namespace std;

int main(){

	cout << "Long long int\n";
	cout << "Max = " << numeric_limits<long long int>::max() << endl;
	cout << "Min = " << numeric_limits<long long int>::lowest() << endl;
	cout << numeric_limits<long long int>::digits << "bity " <<endl;
	cout << "Ilosc miejsc dziesietnych = " << numeric_limits<long long int>::digits10 << endl;
	
	cout << "\nFloat\n";
	cout << "Max = " << numeric_limits<float>::max() << endl;
	cout << "Min = " << numeric_limits<float>::lowest() << endl;
	cout << "Closest to zero = " << numeric_limits<float>::min() << endl;
	cout << "Float Epsilon = " << numeric_limits<float>::epsilon() << endl;
	
	cout << "\nDouble\n";
	cout << "Max = " << numeric_limits<double>::max() << endl;
	cout << "Min = " << numeric_limits<double>::lowest() << endl;
	cout << "Closest to zero = " << numeric_limits<double>::min() << endl;
	cout << "Double Epsilon = " << numeric_limits<double>::epsilon() << endl;
	
	
	
	return 0;
}
