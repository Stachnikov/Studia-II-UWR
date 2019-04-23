#include "definitions.hpp"


int main(int argc, char** argv) {
	Wyrazenie *w = new Dodaj(new Liczba(5), new Liczba(4)); 
	std::cout<<w->opis()<< " = " << w->oblicz() << std::endl;
	w = new Odejmij(new Liczba(5), new Liczba(4));
	std::cout<<w->opis()<< " = " << w->oblicz() << std::endl;
	w = new Mnoz(new Liczba(5), new Liczba(4)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Dziel(new Liczba(5), new Liczba(10)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Potega(new Liczba(2), new Liczba(3)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Modulo(new Liczba(6) ,new Liczba(2)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Logarytm(new Liczba(3) ,new Liczba(81)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Przeciwny_znak(new Odejmij( new Liczba(3) ,new Liczba(6) )); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Wartosc_bezw(new Odejmij(new Liczba(2), new Liczba(3))); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Odwrotnosc(new Liczba(0.5)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Sinus(new Dziel(new pi(),new Liczba(2))); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Cosinus(new Liczba(0)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Ln(new e()); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Exp(new Liczba(1)); 
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w=  new Odejmij(new pi(), new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))));
	Zmienna :: nadaj_wartosc("x",5);
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;
	w = new Zmienna("x");
	std::cout<<w->opis()<< " = " << w->oblicz()<< std::endl;

	Wyrazenie *w1 = new Dziel(new Mnoz(new Odejmij(new Zmienna("x"),new Liczba(1)),new Zmienna("x")),new Liczba(2));

	Wyrazenie *w2 = new Dziel(new Dodaj(new Liczba(3),new Liczba(5)),new Dodaj(new Liczba (2),new Mnoz(new Zmienna("x"),new Liczba(7)))); 

	Wyrazenie *w3 = new Odejmij(new Dodaj(new Liczba(2),new Mnoz(new Zmienna("x"),new Liczba(7))),new Dodaj(new Mnoz(new Zmienna("y"),new Liczba(3)),new Liczba(5)));
	
	Wyrazenie *w4 = new Dziel(new Cosinus(new Mnoz(new Dodaj(new Zmienna("x"),new Liczba(1)),new Zmienna("x"))),new Exp(new Potega(new Zmienna("x"),new Liczba(2))));
	std::cout<<w4->opis()<< " = " << w4->oblicz()<< std::endl;
	
		for(double i=0.0; i<=1.0; i+=0.01)
	{
		std::cout << "Dla x = " << i << std::endl << std::endl<< std::endl;
		Zmienna :: nadaj_wartosc("x",i);
		std::cout<< "w1 : " << w1->opis()<< " = " << w1->oblicz()<< std::endl;	
		std::cout<< "w2 : " << w2->opis()<< " = " << w2->oblicz()<< std::endl;	
		std::cout<< "w3 : " << w3->opis()<< " = " << w3->oblicz()<< std::endl;	
		std::cout<< "w4 : " << w4->opis()<< " = " << w4->oblicz()<< std::endl;	
	
		std::cout<< "\n******************************************************************\n\n" << std::endl;
	}

	return 0;
}
