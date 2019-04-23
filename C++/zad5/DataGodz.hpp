#ifndef GODZ
#define GODZ

#include "czas.hpp"
#include <string>

class DataGodz final : Data {
	
	protected:
		//zmienne
		int godz;
		int min;
		int sek;
	
	public:
		//gettery
		int get_godz();
		int get_min();
		int get_sek();
	
	//KONSTRUKTORY
	DataGodz(int rok, int miesiac=1, int dzien=1, int godz=0, int min=0, int sek=0);
	DataGodz();
	DataGodz( DataGodz &datgodz);
	DataGodz& operator=(const DataGodz &datgodz);
	
	
	int& operator- ( DataGodz& d2);
	void operator++ ();
	void operator-- ();
	void operator+= (int dni);
	void operator-= (int dni);
	bool operator< (DataGodz& d2);
	bool operator== (DataGodz& d2);
	private:
	int uplynelo(DataGodz dat);


	
};

class Wydarzenie{
	public:
	std::string wydarz;
	DataGodz DG;	
	
	Wydarzenie(std::string wyd,int r, int mie, int d, int g, int min, int s);
};

#endif
