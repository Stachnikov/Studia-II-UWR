#include <iostream>
#include <regex>

using namespace std;

int main(){
	
	string input;
	string result;
	cout << "Podaj liczbe zespolona: " << endl;
	getline(cin, input);	
	
	try
	{
							//Spacje//Liczba Rzeczywista //Spacje //+ //Spacje //Liczba Rzeczywista //Spacje
		regex data_regRaw(R"(([ ]*\([ ]*[-]?\d+(?:\.\d+)*[ ]*\+[ ]*[-]?\d+(?:\.\d+)*[iI][ ]*\)[ ]*))"); 
		smatch match;
		
		if(regex_search(input,match,data_regRaw))
			result = match[0];
		else
			cout << "Niepoprawna liczba zespolona!";
		
	}
	catch(regex_error &e)
	{
		
	}
	
	cout<< result;
	return 0;
}
