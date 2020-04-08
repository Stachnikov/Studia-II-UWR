#include <iostream>
#include <regex>

using namespace std;

int main(){
		
	string input;
	string result;
	cout << "Podaj date YYYY*-MM-DD : " << endl;
	getline(cin, input);	
	
	try
	{
								//ROK				//MIESIACE Z 31							//MIESIACE Z 30							//LUTY
		regex data_regRaw(R"((([0-9]{4,})-(((01|03|05|07|08|10|12)-([0-2][0-9]|3[0-1]))|((04|06|09|11)-([0-2][0-9]|3[0-1])|(02-([0-1][0-9]|2[0-8]))))))"); 
		smatch match;
		
		if(regex_search(input,match,data_regRaw)){
			result = match[0];
		}
		else
			cout << "Niepoprawna data!";
		
	}
	catch(regex_error &e)
	{
		
	}
	
	cout << result;
	return 0;
}
