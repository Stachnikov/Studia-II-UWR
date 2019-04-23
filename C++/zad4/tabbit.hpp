#ifndef TABBIT
#define TABBIT
#include <iostream>

class tab_bit
{
		typedef uint64_t slowo; // komorka w tablicy
		static const int rozmiarSlowa; // rozmiar slowa w bitach
		class ref{ // klasa pomocnicza do adresowania bit�w
			public:
			slowo* wskSlowo;
			int numer_bitu;
			bool operator = (bool x);
			
			ref() : wskSlowo(0), numer_bitu(0){};
		};
	protected:
		int dl=0; // liczba bit�w
		slowo *tab=0; // tablica bit�w
	public:
		explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
		explicit tab_bit (slowo tb); // tablica bit�w [0...rozmiarSlowa]
									// zainicjalizowana wzorcem
		tab_bit (const tab_bit &tb); // konstruktor kopiuj�cy
		tab_bit (tab_bit &&tb); // konstruktor przenosz�cy
		tab_bit & operator = (const tab_bit &tb); // przypisanie kopiuj�ce
		tab_bit & operator = (tab_bit &&tb); // przypisanie przenosz�ce
		~tab_bit (); // destruktor
	private:
		bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu
		bool pisz (int i, bool b); // metoda pomocnicza do zapisu bitu
	public:
		bool operator[] (int i) const; // indeksowanie dla sta�ych tablic bitowych
		ref operator[] (int i); // indeksowanie dla zwyk�ych tablic bitowych
		inline int rozmiar () const; // rozmiar tablicy w bitach
	public:
		// operatory bitowe: | i |=, & i &=, ^ i ^= oraz !
		slowo operator| (tab_bit f2);
		void operator|= (tab_bit f2);
		slowo operator& (tab_bit f2);
		void operator&= (tab_bit f2);
		slowo operator^ (tab_bit f2);
		void operator^= (tab_bit f2);
		slowo operator! ();
	public:
		friend std::istream & operator >> (std::istream &we, tab_bit &tb);
		friend std::ostream & operator << (std::ostream &wy, const tab_bit &tb);
};



#endif
