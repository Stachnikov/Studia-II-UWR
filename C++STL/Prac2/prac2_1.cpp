#include <iostream>
#include <memory>
#include <ctime>

using namespace std;

int l_pierwsze[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

class MojaKlasa
{
    public : uint64_t licznik = 1;
    
    ~MojaKlasa()
    {
        cout<<"Obiekt klasy zostal usuniety"<<endl;
    }
};

void rekfun(int n,int m, MojaKlasa tab[])
{
	//<random>
    if(m>0)
    {	
        srand(time(NULL));
        rekfun(n,--m,tab);
        int random = rand() % n;
        tab[random].licznik *= l_pierwsze[m];
    }
}

int main()
{
    int m = 7;
    int n = 20;
    
    unique_ptr<MojaKlasa[], void(*)(MojaKlasa *)> wskaznik{new MojaKlasa[n],[](MojaKlasa *mk){delete[] mk;}};
    
    rekfun(n,m,&wskaznik[0]);
    for(int i=0; i <n; i++)
    {
        cout << wskaznik[i].licznik << "\n";
    }    
    cout << "\n";
}
