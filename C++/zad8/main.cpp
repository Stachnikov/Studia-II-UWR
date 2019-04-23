#include "rational.hpp"
#include "exception.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
    
int main(int argc, char** argv) {
	
	using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using namespace obliczenia;
	
	try{		
		Wymierna ulamek = Wymierna(8,-6);
		Wymierna liczba = Wymierna(4);
		
		Wymierna ulamek1 = Wymierna(2,1);
		Wymierna ulamek2 = Wymierna(10,1);
		
		Wymierna ulamek3 = ulamek1 + ulamek2;
		cout << ulamek1 << " + " << ulamek2 << " = " << ulamek3 << endl;
		
		ulamek3 = ulamek1 - ulamek2;
		cout << ulamek1 << " - " << ulamek2 << " = " << ulamek3 << endl;
		
		ulamek3 = ulamek1 * ulamek2;
		cout << ulamek1 << " * " << ulamek2 << " = " << ulamek3 << endl;
		
		ulamek3 = ulamek1 / ulamek2;
		cout << ulamek1 << " / " << ulamek2 << " = " << ulamek3 << endl;
		
		cout<< "Przeciwny znak: " << ulamek3 << " = > " << -ulamek3 << endl;
		
		cout<< "Odwrotnosc: " << ulamek3 << " = > " << !ulamek3 << endl;
		
		cout << "Double: " << (double)ulamek << endl;
		cout << "Int: " << (int)ulamek << endl;
		
		Wymierna okres = Wymierna(29,30);
		cout << okres << endl; 
		
		cout << Wymierna(1,0);
		
	}
	catch (dzielenie_przez_0 &e){
		cout << e.what();
	}
	catch (przekroczenie_zakresu &e){
		cout << e.what();
	}
	//cout << liczba ;
	
	
	
	
	return 0;
}
