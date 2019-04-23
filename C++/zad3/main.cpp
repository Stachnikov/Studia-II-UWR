#include "stos.hpp"

int main(int argc, char** argv) {

	stos* stosik= new stos({"mama","tata","brat"});
	//stos* stosik= new stos(5);
	//stos* stosik= new stos();
	
	int zadanie = 1;

	while(zadanie != 0){
		
		std::cout << "Co chcesz zrobic?\n\
1. Wloz napis na stos\n\
2. Sciagnij napis ze stosu\n\
3. Sprawdz jaki napis jest na wierzcholku\n\
4. Wypisz liczbe elementow na stosie\n\
5. Wypisz pojemnosc stosu\n\
6. Usun element ze szczytu\n\
7. Wypisz stos\n\
0. Nic, zakoncz... \n\n\n";
		std::cin >> zadanie;
				
		switch( zadanie )
		{
			case 1:{
				std::string napis;
				std::cout << "Podaj napis...\n";
				std::cin >> napis;
			    stosik->wloz(napis);
			    std::cout << std::endl;
			 break;
			}
						    
			case 2:{
				std::string napis;
			    napis=stosik->sciagnij();
			    std::cout << "Zdjeto napis: " << napis << std::endl << std::endl;
			 break;
			}
						    
			case 3:{
				std::cout << "W wierzcholku znajduje sie napis: " << stosik->sprawdz() << std::endl << std::endl;
			 break;
			}
			case 4:{
				std::cout << "Liczba elementow na stosie: " << stosik->rozmiar() << std::endl << std::endl;
			 break; 
			} 
			case 5:{
			    std::cout << "Pojemnosc stosu: " << stosik->jaka_pojemnosc() << std::endl << std::endl;
			 break; 					
			}     
			case 6:{
				stosik->usun();
			    std::cout << "Usunieto element..."  << std::endl << std::endl;
			 break; 					
			}     
			case 7:{
			    std::cout << "Stos: ";
				stosik->wypisz_stos();
				std::cout << std::endl << std::endl;
			 break; 					
			}     
			case 0:
				return 0;
			 break;
						    
			default:
			    std::cout << "Podales niepoprawny numer opcji\n\n";
			  break;
		}
	}
	delete stosik;

	return 0;
}
