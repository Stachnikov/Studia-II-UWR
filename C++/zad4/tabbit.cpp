#include "tabbit.hpp"

	
	
	const int tab_bit::rozmiarSlowa = sizeof(slowo);

	tab_bit::tab_bit(int rozm) {  // wyzerowana tablica bitow [0...rozm]
		if(rozm == 0)
		 throw "Rozmiar rowny 0";
		this->dl=rozm;
		int roz;
		roz=rozm/sizeof(slowo);
		this->tab = new slowo[roz];
		for(int i=0; i<roz; i++)
		{
			this->tab[i]=0;
		}
	}
	
	tab_bit::tab_bit (slowo tb){ // tablica bitów [0...rozmiarSlowa]  zainicjalizowana wzorcem
		
		this->dl=sizeof(tb);
		this->tab[0]=tb;
	}
									
	tab_bit::tab_bit (const tab_bit &tb){   // konstruktor kopiuj¹cy
		dl=tb.dl;
		tab=tb.tab;
	}
	
	tab_bit::tab_bit (tab_bit &&tb){ // konstruktor przenosz¹cy
		
		dl=tb.dl;
		tab=tb.tab;
		
		tb.dl=0;
		tb.tab=0;
		
	}
	
	tab_bit & tab_bit::operator = (const tab_bit &tb){ // przypisanie kopiuj¹ce
				
		if (this != &tb)  
	   {  
			delete[] tab;
	  
	      	tab = new slowo[tb.rozmiar()]; 
			
			dl=tb.dl;
			for(int i=0; i<tb.rozmiar(); i++)
			{
				this->tab[i]=tb.tab[i];
			}
	  
	   }  
	   return *this;  
	}
	
	tab_bit & tab_bit::operator = (tab_bit &&tb){ // przypisanie przenosz¹ce
		if (this != &tb)  
	   {  
	   		delete[] tab;
	  
	  		
			dl=tb.dl;
	      	tab = tb.tab;  
	  
	  		tb.dl=0;
		    tb.tab=0;
	   }  
	   return *this;  
	}	
	
	
	
	tab_bit::~tab_bit (){ // destruktor
		delete[] tab;
	}
	
	
	
		bool tab_bit::czytaj (int i) const{ // metoda pomocnicza do odczytu bitu
			int numer_indeksu=i/(sizeof(slowo));
			int bit = i%(sizeof(slowo));
			
			return (tab[numer_indeksu] >> bit)%2;
		}
		
		bool tab_bit::pisz (int i, bool b){ // metoda pomocnicza do zapisu bitu
			tab_bit::operator[](i)=b; 
		}
		
		bool tab_bit::operator[] (int i) const{ // indeksowanie dla sta³ych tablic bitowych
			return czytaj(i);
		}
		
		tab_bit::ref tab_bit::operator[] (int i){ // indeksowanie dla zwyk³ych tablic bitowych
			ref *pom = new ref;
			pom->numer_bitu=i;
			pom->wskSlowo = tab;
			
			return *pom;
		}
		
		bool tab_bit::ref::operator= (bool b){ // przypisanie
			int bit = numer_bitu%sizeof(slowo);
			int mask = 1;
			wskSlowo[numer_bitu/sizeof(slowo)] = wskSlowo[numer_bitu/sizeof(slowo)] & ~(mask << bit);
			wskSlowo[numer_bitu/sizeof(slowo)] = wskSlowo[numer_bitu/sizeof(slowo)] | (b << bit);
			return b;
		}
		
		inline int tab_bit::rozmiar () const{ // rozmiar tablicy w bitach
			return dl;
		}
		
		
		
	// operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
	tab_bit::slowo tab_bit::operator| (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			slowo *nowe = new slowo[wieksze];
			for(int i=0; i<wieksze; i++)
				nowe[i]= this->tab[i] | f2.tab[i];
			return *nowe;
		}
		
	void tab_bit::operator|= (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			for(int i=0; i<wieksze; i++)
				this->tab[i]= this->tab[i] | f2.tab[i];
		}
		
	tab_bit::slowo tab_bit::operator& (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			slowo *nowe = new slowo[wieksze];
			for(int i=0; i<wieksze; i++)
				nowe[i]= this->tab[i] & f2.tab[i];
			return *nowe;
		}
		
	void tab_bit::operator&= (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			for(int i=0; i<wieksze; i++)
				this->tab[i]= this->tab[i] & f2.tab[i];
		}
		
	tab_bit::slowo tab_bit::operator^ (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			slowo *nowe = new slowo[wieksze];
			for(int i=0; i<wieksze; i++)
				nowe[i]= this->tab[i] ^ f2.tab[i];
			return *nowe;
		}
		
	void tab_bit::operator^= (tab_bit f2) { // operatory bitowe
			int wieksze=0;
			if(this->rozmiar() > f2.rozmiar())
			wieksze=this->rozmiar();
			else
			wieksze=f2.rozmiar();
			
			for(int i=0; i<wieksze; i++)
				this->tab[i]= this->tab[i] ^ f2.tab[i];
		}
		
	tab_bit::slowo tab_bit::operator! () { // operatory bitowe
			slowo *nowe = new slowo[this->rozmiar()];
			for(int i=0; i<this->rozmiar(); i++)
				nowe[i]= ~this->tab[i];
			return *nowe;
		}
		
		
	std::istream & operator >> (std::istream &we, tab_bit &tb){
		
		
	}
	
	std::ostream & operator << (std::ostream &wy, const tab_bit &tb){
		
		
	}
