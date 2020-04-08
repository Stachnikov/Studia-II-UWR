#include <iostream>
#include <regex>

using namespace std;

int main(){
	
	string input;
	string result;
	cout << "Podaj input: " << endl;
	getline(cin, input);	
	
	try
	{
		regex data_regRaw(R"(([0-1][0-9]|2[0-3]):([0-5][0-9]))"); 
		smatch match;
		
		if(regex_search(input,match,data_regRaw)){
			result = match[0];
			cout<< result;
		}
		else
			cout << "Niepoprawna godzina!";
		
	}
	catch(regex_error &e)
	{
		
	}
	return 0;
}
