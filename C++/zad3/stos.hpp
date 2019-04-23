#ifndef STOS
#define STOS

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <initializer_list>

class stos{
	private:
		int pojemnosc=1;
		int ile=-1;
		std::string* stos_napisow=nullptr;
	
	public:
		
		void wloz(std::string napis);
				
		std::string sciagnij();
		
		std::string sprawdz();
		
		int rozmiar();
		
		void usun();
		
		void wypisz_stos();
		
		int jaka_pojemnosc() const;
		
		stos(int pojemnosc);
		
		~stos();
		
		stos();
		
		stos(const std::initializer_list<std::string> &lst);
		
		stos(const stos &s );
		
		stos& operator=(const stos& s);
		
		stos(stos &&s);
		
		stos& operator=(stos&& s);
};

#endif
