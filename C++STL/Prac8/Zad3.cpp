#include <iostream>
#include <regex>

using namespace std;

int main(){
	
	string input;
	string result;
	cout << "Podaj miejscowosc: " << endl;
	getline(cin, input);	
	
	try
	{
								//Nazwa		// '-' i drugi cz³on 0-1	//dowolna ilosc spacji i kolejny cz³on dowolnie duzo
		regex data_regRaw(R"(^[A-Z][a-z]{2,}(?:[-][A-Z][a-z]{2,})?(?:[ ]*[A-Z][a-z]{2,})*$)"); 
		smatch match;
		
		if(regex_search(input,match,data_regRaw))
			result = match[0];
		else
			cout << "Niepoprawna miejscowosc!";
		
	}
	catch(regex_error &e)
	{
		
	}
	
	cout<< result;
	return 0;
}
