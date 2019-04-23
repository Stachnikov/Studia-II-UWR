#ifndef DEFINIT
#define DEFINIT

#include <iostream>



//namespace Obliczenia{
	
	class Macierz{
		public:
	 	float** tab2d;
	 	int a;
	 	int b;
		
		Macierz(int A);
		Macierz(int A,int B);
		Macierz( Macierz &m);
		Macierz( Macierz &&m);
		Macierz& operator= ( Macierz &m);
		Macierz&& operator= ( Macierz &&m);
		~Macierz();
		
		Macierz & operator+= (const Macierz &x);
			//throw (rozmiary_nie_pasuja);
		Macierz & operator-= (const Macierz &x);	
			//throw (rozmiary_nie_pasuja);
		Macierz & operator*= (const Macierz &x);
			//throw (rozmiary_nie_pasuja);
		Macierz & operator*= (float alfa);
			//throw (rozmiary_nie_pasuja);
		Macierz & operator~ ();
				//throw (rozmiary_nie_pasuja);
		
		/*
		friend Macierz operator+ (const Macierz &x, const Macierz &y);
				//throw (rozmiary_nie_pasuja);
			
		friend Macierz operator- (const Macierz &x, const Macierz &y);
				//throw (rozmiary_nie_pasuja);
			
		friend Macierz operator* (const Macierz &x, const Macierz &y);
				//throw (rozmiary_nie_pasuja);
				
		friend Macierz operator* (const Macierz &x, float alfa);
				//throw (rozmiary_nie_pasuja);
		*/
	};
//}

class  Except : std::exception{
	
	
};














#endif
