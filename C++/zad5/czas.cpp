#include "czas.hpp"


	//Gettery
	int Data::get_dzien(){
		return this->dzien;
	}
	int Data::get_miesiac(){
		return this->miesiac;
	}	
	int Data::get_rok(){
		return this->rok;
	}
	
	
	//konstruktory
	Data::Data(int Dzien,int Miesiac, int Rok){
		if(poprawnosc(Dzien,Miesiac,Rok) == 1)
		{
			this->dzien=Dzien;
			this->miesiac = Miesiac;
			this->rok = Rok;
		}
		else
			throw std::invalid_argument("Bledne dane...");
	}
	Data::Data(){
		time_t czas;
		struct tm * data;		
		time( &czas );
		data = localtime(&czas);
		
		this->dzien=data->tm_mday;
		this->miesiac=data->tm_mon + 1;
		this->rok=data->tm_year + 1900;
	}
	Data::Data( Data &dat) = default;
	Data& Data::operator=(const Data &dat) = default;

	
	
	
	

	//tablice
	int Data::dniwmiesiacach[2][13] = {
		{0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
		{0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
	};
	int Data::dniodpoczroku[2][13] = {
		{0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
		{0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
	};
	
	
	//metody
	bool Data::czy_przestepny(int rok){				//ZWRACA 1 JEZELI PRZESTEPNY
		if (rok%400 == 0)
		return 1;
		else if ((rok%4 == 0) && (rok%100 !=0))
		return 1;
		else
		return 0;
	}

	bool Data::poprawnosc(int dzien, int miesiac, int rok){					//ZWRACA 1 JEZELI POPRAWNE
		if(czy_przestepny(rok) == 1)
		{
			return dniwmiesiacach[1][miesiac] >= dzien;
		}
		else
		{
			return dniwmiesiacach[0][miesiac] >= dzien;
		}	
	}

	int Data::uplynelo(Data dat){
		//WIRTUALNA DATA 1.01.0r.
		int Rok=dat.get_rok();
		int Miesiac=dat.get_miesiac();
		int Dzien=dat.get_dzien();
		
		bool przest=this->czy_przestepny(Rok);
		
		return Rok * dniodpoczroku[0][12] + dniodpoczroku[przest][Miesiac-1] + Dzien + Rok/4;
	}
	
	int& Data::operator- ( Data& d2){
		int *wynik = new int;
		*wynik = (int)(uplynelo(*this)) - (int)(uplynelo(d2));
		return *wynik;
	}
	
	void Data::operator++ (){
		
		if(dzien == dniwmiesiacach[czy_przestepny(rok)][miesiac])
		{
			dzien=1;
			if(miesiac==12)
			{
				miesiac=1;
				rok++;
			}
			else
				miesiac++;
		}
		else
			dzien++;
	}
	
	void Data::operator-- (){
		
		if(dzien == 1)
		{
			if (miesiac==1)
			{
				miesiac=12;
				rok--;
				dzien=dniwmiesiacach[czy_przestepny(rok)][miesiac];
			}
			else
				miesiac--;
		}
		else
			dzien--;
			
	}
	
	void Data::operator+= (int dni){	// 11.  3.  2008.		+ 99 dni
										// 1.   4.  2008.       + 79 dni
										// 1.   5.  2008.		+ 49 dni
										// 1.   6.  2008.		+ 18 dni
										// 18.  6.  2008.		+ 0 dni
		
		while(dni>0)
		{
			if(dni <= dniwmiesiacach[czy_przestepny(rok)][miesiac]-dzien)
				{
					dzien=dzien+dni;
					break;
				}
			else
			{
				dni -= dniwmiesiacach[czy_przestepny(rok)][miesiac]-dzien;
				dzien = 0;
				
				if(miesiac==12)
				{
					miesiac=1;
					rok++;
				}
				else
					miesiac++;
			}
		}
	}
	
	void Data::operator-= (int dni){
		while(dni>0)
		{
			if(dni < dzien)
				{
					dzien=dzien-dni;
					break;
				}
			else
			{
				dni -= dzien;
				if(miesiac==1)
				{
					miesiac=12;
					rok--;
					dzien = dniwmiesiacach[czy_przestepny(rok)][miesiac];
				}
				else
					dzien = dniwmiesiacach[czy_przestepny(rok)][--miesiac];
			}
		}
	}



