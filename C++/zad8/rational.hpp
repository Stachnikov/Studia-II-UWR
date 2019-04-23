#ifndef RATIONAL
#define RATIONAL

#include <iostream>
#include <limits>
#include "exception.hpp"
namespace obliczenia{
	using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
    using std::ostream;
	class Wymierna{
		private:
		int licz;
		int mian;
		void popraw(int l, int m);   // #
		
		public :
		Wymierna(int l,int m);		// #
		Wymierna(int liczba);	// #
		int get_licz() const;		// #
		int get_mian() const;		// #
		
		Wymierna operator+(Wymierna &p);	// #
		Wymierna operator-(Wymierna &p);	// #
		Wymierna operator*(Wymierna &p);	// #
		Wymierna operator/(Wymierna &p);	// #
		Wymierna operator-();	// #
		Wymierna operator!();	// #
		
		operator double() const;		//OPERATOR KONWERSJI	//#
		explicit operator int() const;		//OPERATOR JAWNEGO RZUTOWANIA	//#
		
		friend ostream& operator<< (ostream &wyj, const Wymierna &w);		// #
		
	};
	
}













#endif
