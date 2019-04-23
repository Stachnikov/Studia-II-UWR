#include "Strumien.hpp"
#include <vector>
#include <algorithm>

using namespace std;
using namespace strumienie;

int main(int argc, char** argv) {
	string test="TEST";
	//TEST DLA COMMA I COLON
	//cout << "5" << comma << test << colon << "OK";
	
	//TEST DLA INDEKSU
	//cout << index(123,9);
	
	//TEST DLA CLEARLINE
	/*string a, b;
	cin >> clearline >> a >> b;
	cout << a << b;*/

	//TEST DLAIGNORE
	/*cin >> ignore(2) >> test;
	cout << test;*/
	
	
	//VECTOR TEST
	std::vector <pair<string,int>> kontener;
	string s;
	int counter=0;
	while(!cin.eof())
	{
		if(cin.peek() == EOF){
			cout << "PUSTY PLIK";		
			break;	
		}
		else{
			getline(cin,s);
			kontener.push_back(make_pair(s,counter+1));
			counter++;
		}
	}
	
	sort(kontener.begin(), kontener.end());
	
	for(int i=0; i<counter;i++){
		cout << index(kontener[i].second,3) << colon << kontener[i].first <<endl;
	}
	
	return 0;
}
