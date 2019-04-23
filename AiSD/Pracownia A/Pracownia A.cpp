#include <iostream>

using namespace std;

int main(){
	//Zmienna n - ilosc wierzch, maks - maksymalna sciezka
	uint64_t n,pocz=0,kon=0;
	long long suma=0,calosc=0,maks=0,granica;
	
	//Czytaj n
	cin >> n;
	
	granica = n/2;
	
	uint64_t tab[n];
	//Wczytanie do tab
	for(uint64_t i=0; i<n;i++){
		cin >> tab[i];
		calosc += tab[i];
	}
	
	while(pocz<n){
		while(suma<=calosc-suma){
			if(maks < suma)
				maks = suma;
			suma+=tab[kon];
			kon++;
			kon = kon % n;
		}
		
		if(calosc - maks <= granica){
			maks = calosc-maks;
		}
		suma-=tab[pocz];
		pocz++;
	}
	
	cout << maks;
	
	return 0;
}