#include "stos.hpp"

	
	void stos::wloz(std::string napis){
			if(ile<pojemnosc-1){
				ile++;
				stos_napisow[ile]=napis;
			}
			else
				throw std::invalid_argument ("Stos jest pelen"); 
		
	}
			
			
	std::string stos::sciagnij(){
		if(ile==-1)
			throw std::invalid_argument ("Stos jest pusty"); 
		std::string napis;
		napis=stos_napisow[ile];
		stos_napisow[ile]="";
		ile--;
		
		return napis;
	}
		
	std::string stos::sprawdz(){
			
		if(ile==-1)
			throw std::invalid_argument ("Stos jest pusty");
		return stos_napisow[ile];
	}
	
	int stos::rozmiar() {
		return ile+1;
	}
	
	void stos::usun(){
		if(ile==-1)
			throw std::invalid_argument ("Stos jest pusty");
		stos_napisow[ile]="";
		ile--;
	}
	
	void stos::wypisz_stos(){
		int rozmiar=this->rozmiar();
		
		for(int i=0; i<rozmiar; i++){
			std::cout << sciagnij() << "  ";
		}
		std::cout << "\n\nStos jest teraz pusty...";
	}
	
 	int stos::jaka_pojemnosc() const{
 		return pojemnosc;
	 }
	
	stos::stos(int pojemnosc){
		if(pojemnosc <= 0)
			throw std::invalid_argument ("Pojemnosc mniejsza badz rowna 0");
		
		this->pojemnosc=pojemnosc;
		ile=-1;
		stos_napisow = new std::string[pojemnosc];
	}
	
	stos::~stos(){
		delete[] stos_napisow;
	}
	
	stos::stos() : stos(1) {}
	
	stos::stos(const std::initializer_list<std::string> &lst) : stos(lst.size()) {
		std::cout << lst.size();
		for( const std::string &napis : lst)
			wloz(napis);		
	}
		
	stos::stos(const stos &s ){
		ile=s.ile;
		pojemnosc=s.pojemnosc;
		stos_napisow=s.stos_napisow;
	}
	
	stos& stos::operator=(const stos& s) {
		
		if (this != &s)  
	   {  
			delete[] stos_napisow;
	  
	      	stos_napisow = new std::string[s.jaka_pojemnosc()]; 
			
			pojemnosc=s.pojemnosc;
			ile=-1;
			for(int i=0; i<s.jaka_pojemnosc();i++)
			{
				this->wloz(s.stos_napisow[i]);
			}
	  
	   }  
	   return *this;  
	}
	
	
	stos::stos(stos &&s) : ile(-1) , pojemnosc(1) , stos_napisow(nullptr) {
		
		ile=s.ile;
		pojemnosc=s.pojemnosc;
		stos_napisow=s.stos_napisow;
		
		s.ile=-1;
		s.pojemnosc=1;
		s.stos_napisow=nullptr;
	}
	
	stos& stos::operator=(stos&& s) {
		
		if (this != &s)  
	   {  
	   		delete[] stos_napisow;
	  
			pojemnosc=s.pojemnosc; 
	      	stos_napisow = s.stos_napisow;  	//swap
	      	ile = s.ile; 
	  
		    s.stos_napisow = nullptr;  
	    	s.ile = -1;
			s.pojemnosc=1;  
	   }  
	   return *this;  
	}
