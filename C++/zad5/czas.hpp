#ifndef CZAS
#define CZAS

#include <iostream>
#include <ctime>
#include <stdexcept> 

class Data {
	protected:
		//Zmienne
		int dzien = 15;
		int miesiac = 10;
		int rok = 1582;	
	
	public :
	//Tablice
	static int dniwmiesiacach[2][13];
	static int dniodpoczroku[2][13];
		
	//Gettery
	int get_dzien();
	int get_miesiac();
	int get_rok();
	
	//Konstruktory
	Data(int Dzien,int Miesiac, int Rok);
	Data();
	Data(Data &dat);
	Data& operator=(const Data& dat);
	
	//Metody
	protected :
	static bool czy_przestepny(int rok);
	
	private :
	bool poprawnosc(int dzien,int miesiac,int rok);
	int uplynelo(Data dat);
	
	public:
	virtual int& operator- ( Data& d2);
	void operator++ ();
	void operator-- ();
	void operator+= (int dni);
	void operator-= (int dni);
	
	
};
#endif
