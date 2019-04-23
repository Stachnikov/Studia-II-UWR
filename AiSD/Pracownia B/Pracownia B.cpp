#include <iostream>
#include <cmath>
#include <cstdio>
#include <cinttypes>

using namespace std;

struct Liczba
{
	unsigned int pozioma;
	unsigned int pionowa;

	long long unsigned int val() const{
	    return static_cast<long long unsigned int>(pozioma) * pionowa;
    }
};

bool operator> (const Liczba &o, const Liczba &p) {return o.val() > p.val();};
bool operator< (const Liczba &o, const Liczba &p) {return o.val() < p.val();};


class kopczyk
{
	public:
		Liczba tablica[1000000+1];
		long long unsigned int rozmiar;
		kopczyk();
		void push(Liczba v);
		void pop();
		Liczba  max();
};

	kopczyk::kopczyk(){
		rozmiar = 0;
	}

	void kopczyk::pop(){
		tablica[1] = tablica[rozmiar];
		rozmiar--;
		long long unsigned int tmp = 1;
		while(tmp*2 <= rozmiar){
			if(tablica[tmp] < tablica[tmp*2] || tablica[tmp] < tablica[tmp*2+1]) {
				if(tablica[tmp*2] > tablica[tmp*2+1] || tmp*2+1 > rozmiar) {
					swap(tablica[tmp],tablica[tmp*2]);tmp=tmp*2;}
				else {
					swap(tablica[tmp],tablica[tmp*2+1]);tmp=tmp*2+1;
				}
			}
			else
			break;
		}
	}

	void kopczyk::push(Liczba v){
		long long unsigned int s = rozmiar+1;
		tablica[s] = v;
		while(s!=1) {
			if(tablica[s/2] < tablica[s]) {
				swap(tablica[s/2],tablica[s]);s/=2;
			}
			else
				break;
		}
		rozmiar++;
	}

	Liczba kopczyk::max(){
		return tablica[1];
	}


int main(){
	long long unsigned int M,k,counter=0;
	kopczyk *kopiec = new kopczyk();
	cin >> M >> k;
	Liczba liczba;

	for(long long int i = M-1; i>=0;i--){
		liczba.pionowa=M;
		liczba.pozioma=i+1;
		kopiec->push(liczba);
	}

	long long unsigned int poprzednia=0;
	long long unsigned int iloczyn=0;

	while(counter!=k){
		Liczba tmp = kopiec->max();
		iloczyn = tmp.val();

		if(tmp.pionowa>tmp.pozioma){
			tmp.pionowa=tmp.pionowa-1;
			kopiec->push(tmp);
		}

		kopiec->pop();
		if(iloczyn != poprzednia){
			printf("%llu\n", iloczyn);
			counter++;
			poprzednia = iloczyn;
		}
	}

	delete kopiec;
	
	return 0;
}