#include "rational.hpp"
#include "exception.hpp"

	int nwd(int a,int b){
		int l = abs(a);
		int m = abs(b);
	
		while(l!=m)
	    {
	        if(l>m) l=l-m;
	        else m=m-l;
	    }
	    return l;
	}
	
	int nww(int aa,int bb)
	{
		int a=abs(aa);
		int b=abs(bb);
		int iloczyn = a*b;
		while(a!=b)
	    {
	        if(a>b) a=a-b;
	        else b=b-a;
	    }
	    return iloczyn/a;
	}
	
	int sum25(int a){
		int i=0;
		while((a % 2 == 0) || (a % 5 == 0)){
			if(a%2 == 0)
			{
				a /=2;
				i++;
			}
			else
			{
				a /=5;
				i++;
			}
		}
		return i;
	}

using namespace obliczenia;
	
	void Wymierna::popraw(int li, int mi){
		
		
		if(mi == 0)
		{
			throw dzielenie_przez_0();
		}
		else
		{
			int NWD = nwd(li,mi);
	
			if(mi<0)
			{
				licz=-(li/NWD);
				mian=-(mi/NWD);	
			}
			else
			{
				licz=(li/NWD);
				mian=(mi/NWD);
			}	
		}
	}
	
	
	Wymierna::Wymierna(int l, int m){
		popraw(l,m);	
	}
	
	Wymierna::Wymierna(int liczba) : Wymierna(liczba,1) {}
	
	int Wymierna::get_licz() const{
		return licz;
	}
	
	int Wymierna::get_mian() const{
		return mian;
	}
	
	Wymierna Wymierna::operator+(Wymierna &p){
		
		long licznik;
		long mianownik;
		int NWW = nww(this->get_mian(),p.get_mian());
				
		licznik = (this->get_licz() * (NWW/this->get_mian())) + (p.get_licz() * (NWW/p.get_mian()));
		mianownik = NWW;
		
		if(licznik > INT_MAX || mianownik > INT_MAX)
			throw przekroczenie_zakresu();
			
		Wymierna dodane = Wymierna( (int)licznik,(int)mianownik);
		return dodane;
	}
	
	Wymierna Wymierna::operator-(Wymierna &p){
		int licznik;
		int mianownik;
		int NWW = nww(this->get_mian(),p.get_mian());
		
		licznik = (this->get_licz() * (NWW/this->get_mian())) - (p.get_licz() * (NWW/p.get_mian()));
		mianownik = NWW;
		
		if(licznik > INT_MAX || mianownik > INT_MAX)
			throw przekroczenie_zakresu();
		
		Wymierna odjete = Wymierna(licznik,mianownik);
		return odjete;
	}
	
	Wymierna Wymierna::operator*(Wymierna &p){
		int licznik=get_licz()*p.get_licz();
		int mianownik=get_mian()*p.get_mian();
		
		if(licznik > INT_MAX || mianownik > INT_MAX)
			throw przekroczenie_zakresu();
			
		
		Wymierna mnozone = Wymierna(licznik,mianownik);
		return mnozone;
	}
	
	Wymierna Wymierna::operator/(Wymierna &p){
		int licznik=get_licz()*p.get_mian();
		int mianownik=get_mian()*p.get_licz();
		
		if(licznik > INT_MAX || mianownik > INT_MAX)
			throw przekroczenie_zakresu();
			
		
		Wymierna dzielone = Wymierna(licznik,mianownik);
		return dzielone;
	}
	
	Wymierna Wymierna::operator-(){
		if(-licz > INT_MAX)
			throw przekroczenie_zakresu();
		Wymierna przeciw = Wymierna(-licz,mian);
		return przeciw;
	}
	
	Wymierna Wymierna::operator!(){
		if(licz == 0)
			throw dzielenie_przez_0();
		Wymierna odwrot = Wymierna(mian, licz);
		return odwrot;
	}
	
	namespace obliczenia{
		std::ostream& operator<< (std::ostream &wyj, const Wymierna &w){
		int ile = sum25(w.get_mian());
		int calk = w;
		double liczba = w;
		if(liczba == 0)
			return wyj << "0";
		if(liczba<0 && calk ==0)
		{
			wyj << "-" << calk;
			liczba *= -1;
		}
		else
			wyj << calk;
		wyj << ".";
		for(int i=0; i<ile; i++)
		{
			int pom = abs((int)(liczba * 10) % 10);
			wyj << pom;
			liczba = liczba * 10 - pom;
		}
		wyj << "(";
		int pop=-1;
		while(true)
		{
			int pom = abs((int)(liczba * 10) % 10);
			if(pom != pop)
			{
				wyj << pom;
				pop = pom;
			}
			else
			{
				break;
			}
			liczba = liczba * 10 - pom;			
		}
		wyj << ")";
			return wyj;
		}
	}
	
	Wymierna::operator double() const{
		return (double)licz/mian;
	}
	Wymierna::operator int() const{
		return licz/mian;
	}
	
	
	
	
	
