#include "czas.hpp"
#include "DataGodz.hpp"
#include <vector>


int main(int argc, char** argv) {	
	
	/*std::vector<Wydarzenie> wydarzenia;
	
	wydarzenia[0]=Wydarzenie("Rano",1,1,1,7,30,0);
	wydarzenia[1]=Wydarzenie("Poludnie",1,1,1,12,00,0);
	wydarzenia[2]=Wydarzenie("Popoludnie",1,1,1,16,22,43);
	wydarzenia[3]=Wydarzenie("Wieczor",1,1,1,20,45,12);
	*/
	
	
	Data dat(1,1,2008);
	Data datt(6,1,2008);

	DataGodz dat2(1,1,1,1,1,1);
	DataGodz dat22(1,1,1,1,1,1);
	DataGodz dat3(2,1,1,0,0,0);
	DataGodz dat4(2001,1,31,23,59,50);
	DataGodz dat44(2001,2,1,0,0,50);

	//std::cout<< "ROZNICA MIEDZY DATT I DAT: " << datt-dat <<"\n";
	//std::cout<< "ROZNICA MIEDZY DAT44 I DAT4: " << dat44-dat4 <<"\n";
	dat4+=60;
	dat44-=60;
	int dzien = dat.get_dzien();
	int miesiac =dat.get_miesiac();
	int rok = dat.get_rok();
	int sekund = dat44.get_sek();
	int minut =dat44.get_min();
	int godzi = dat44.get_godz();
	std::cout  << godzi << "   " << minut << "   " << sekund;
	//std::cout << dat2.operator<(dat3);
	
	dat2.operator--();
	dat.operator--();
	//int dzien = dat.get_dzien();
	//int miesiac =dat.get_miesiac();
	//int rok = dat.get_rok();
	//std::cout << dzien << "  " << miesiac << "   " << rok;
	//std::cout<< dat2.get_sek();
	return 0;
}
