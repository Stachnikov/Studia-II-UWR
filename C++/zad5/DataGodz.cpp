#include "DataGodz.hpp"

//GETTERY
	int DataGodz::get_godz(){
		return this->godz;
	}
	
	int DataGodz::get_min(){
		return this->min;
	}
	
	int DataGodz::get_sek(){
		return this->sek;
	}
	
//KONSTRUKTORY
	DataGodz::DataGodz(int Rok, int Miesiac, int Dzien, int Godz, int Min, int Sek){
		rok=Rok;
		miesiac=Miesiac;
		dzien=Dzien;
		godz=Godz;
		min=Min;
		sek=Sek;
	}
	DataGodz::DataGodz(){
		time_t czas;
		struct tm * data;		
		time( &czas );
		data = localtime(&czas);
		
		this->sek=data->tm_sec;
		this->sek=data->tm_min;
		this->sek=data->tm_hour;
		this->dzien=data->tm_mday;
		this->miesiac=data->tm_mon + 1;
		this->rok=data->tm_year + 1900;
	}
	
	DataGodz::DataGodz( DataGodz &datgodz) = default;
	DataGodz& DataGodz::operator=(const DataGodz &datgodz) = default;
	
	int DataGodz::uplynelo(DataGodz dat){
		//WIRTUALNA DATA 1.01.0r.
		int Rok=dat.get_rok();
		int Miesiac=dat.get_miesiac();
		int Dzien=dat.get_dzien();
		int Godz=dat.get_godz();
		int Min=dat.get_min();
		int Sek=dat.get_sek();
		
		bool przest=this->czy_przestepny(Rok);
		
		return (Rok * dniodpoczroku[0][12] + dniodpoczroku[przest][Miesiac-1] + Dzien + Rok/4) * 86400 + Godz*3600 + Min*60 + Sek;
	}
	
	int& DataGodz::operator- ( DataGodz& d2){
		int *wynik = new int;
		*wynik = (int)(uplynelo(*this)) - (int)(uplynelo(d2));
		return *wynik;
	}
	
	void DataGodz::operator++ (){
		if(sek==59)
		{	
			sek=0;
			if(min==59)
			{
				min=0;
				if(godz==23)
				{
					godz=0;
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
				else
					godz++;
			}
			else
				min++;
		}
		else
			sek++;
	}
	
	void DataGodz::operator-- (){
		if(sek==0)
		{	
			sek=59;
			if(min==0)
			{
				min=59;
				if(godz==0)
				{
					godz=23;
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
				else
					godz--;
			}
			else
				min--;
		}
		else
			sek--;
	}
	
	void DataGodz::operator+= (int sekun){
		while(sekun>0)
		{
			if(sekun <= 60-sek)
			{
				sek=sek+sekun;
				break;
			}
			else
			{
				sekun -= 60-sek;
				sek=0;
				if(min==59)
				{
					min=0;
					if(godz==23)
					{
						godz=0;
						if(dzien==dniwmiesiacach[czy_przestepny(rok)][miesiac])
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
					else
						godz++;
				}
				else
					min++;
			}
		}
	}
	
	void DataGodz::operator-= (int sekun){
		while(sekun>0)
		{
			if(sekun < 60-sek)
			{
				sek=sek-sekun;
				break;
			}
			else
			{
				sekun -= sek;
				if(min==0)
				{
					min=60;
					if(godz==0)
					{
						godz=23;
						if(dzien==dniwmiesiacach[czy_przestepny(rok)][miesiac])
						{
							if(miesiac==1)
							{
								miesiac=12;
								rok--;
								dzien=dniwmiesiacach[czy_przestepny(rok)][miesiac];
							}
							else
							{
								miesiac--;
								dzien=dniwmiesiacach[czy_przestepny(rok)][miesiac];
							}
						}
						else
							dzien--;
					}
					else
						godz--;
				}
				else
					min--;
			}
		}
	}
	
	bool DataGodz::operator< (DataGodz& d2){
		
		if(rok < d2.rok)
		{
			return 1;
		}
		else if(rok == d2.rok && miesiac < d2.miesiac)
		{
			return 1;
		}
		else if(rok == d2.rok && miesiac == d2.miesiac && dzien < d2.dzien)
		{
			return 1;
		}
		else if(rok == d2.rok && miesiac == d2.miesiac && dzien == d2.dzien && godz < d2.godz)
		{
			return 1;
		}
		else if(rok == d2.rok && miesiac == d2.miesiac && dzien == d2.dzien && godz == d2.godz && min < d2.min)
		{
			return 1;
		}
		else if(rok == d2.rok && miesiac == d2.miesiac && dzien == d2.dzien && godz == d2.godz && min == d2.min && sek < d2.sek)
		{
			return 1;
		}
		else
			return 0;
	}
	
	bool DataGodz::operator== (DataGodz& d2){
		if((sek==d2.get_sek()) && (min==d2.get_min()) && (godz==d2.get_godz()) && (dzien==d2.get_dzien()) && (miesiac==d2.get_miesiac()) && (rok==d2.get_rok()))
			return true;
		else
			return false;
	}
	
	
	Wydarzenie::Wydarzenie(std::string wyd,int r, int mie, int d, int g, int min, int s){
		this->wydarz = wyd;
		this->DG = DataGodz(r,mie,d,g,min,s);
	}

