#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <limits>
#include <stdexcept>
//MIKOLAJ STACHNIK ZADANIE 1 PRACOWNIA C++



using namespace std;

bool pierw(int64_t un)
{
	int g = sqrt(un); 
    for(int i = 2; i <= g; i++)
    {
        if(un % i == 0)
		{
			return false;
		}
    }	
    return true;
}

vector<string> to_str(int argc, char* argv[])
{
	vector<string> AllArg;
	for (int i=1; i<argc;i++)
	{
		AllArg.push_back(argv[i]);
	}
	return AllArg;
}

uint64_t str_to_int(string number)
{
	string::iterator ptr = number.begin();
	int64_t value = 0;
	int sign=1;
	if( *ptr == '-')
	{
		sign=-1;
		ptr++;
	}
	
	while ( ptr != number.end())
	{
		value *=10;
		if(*ptr-'0' < 0 || *ptr-'0' > 9)
		{
			throw invalid_argument("Nie jest liczba lub poza zakresem");
		}
		else
		{
			value += *ptr -'0';
			ptr++;
		}
	}
	return value*sign;
}

void wypisz(int64_t liczba, vector<int64_t> rozklad)
{
	cout << liczba << "=";
	for (int i=0; i<rozklad.size()-1;i++)
		cout << rozklad[i] <<"*";
	int i=rozklad.size()-1;
	cout <<rozklad[i] << endl <<endl;
}

vector<int64_t> rozklad (int64_t n)
{
	vector<int64_t> liczba;
    unsigned g;
	uint64_t un;
	   
   	if( n < 0 && n!= -1)
   	{
		liczba.push_back(-1);
		if(n == numeric_limits<int64_t>::min())
			un=-numeric_limits<int64_t>::min();
		else
			un=-n;
	}	
	else
		un=n;
		
	g = sqrt(un); 
    for(int i = 2; i <= g; i++)
    {
        while(un % i == 0)
        {
            liczba.push_back(i);
            un /= i;
        }

        if(un == 1)
            return liczba;
    }

    liczba.push_back(un);
    return liczba;
}

int main(int argc, char * argv[])
{
    if( argc>1){
    	vector<string> list=to_str(argc,argv);
        for(int i=0; i<argc-1; i++)
        {
        	vector<int64_t> czynniki;
            int64_t n;
			n=str_to_int(list[i]);
            czynniki=rozklad(n);
            wypisz(n, czynniki);
        }
    }
    else{
        cerr << "Liczby do rozkladu na czynniki pierwsze nalezy przekazywac do programu poprzez argumety wywolania...\n";
    }
	
    return 0;
}
