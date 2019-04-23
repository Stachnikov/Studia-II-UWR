#include "definitions.hpp"

//using namespace Obliczenia;

//--//KONSTRUKTORY------------------------------------------------------------------------------------------------------------------------------------------------
	Macierz::Macierz(int A){
		tab2d = new float *[A];
		
		for(int i=0;i<A;i++)
		{
			tab2d[i]= new float [A];
		}
		this->a=A;
		this->b=A;
		
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<A;j++)
			{
				if(i == j)
					tab2d[i][j] = 1;
				else
					tab2d[i][j] = 0;
			}
		}
	}
	
	Macierz::Macierz(int A,int B){
		tab2d = new float *[A];
		
		for(int i=0;i<A;i++)
		{
			tab2d[i]= new float [B];
		}
		this->a=A;
		this->b=B;
		
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				tab2d[i][j] = 0;
			}
		}
	}
	
	Macierz::Macierz( Macierz &m)
	: Macierz(m.a,m.b)
	{			
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				this->tab2d[i][j] = m.tab2d[i][j];
			}
		}
	}
	
	Macierz::Macierz( Macierz &&m)
	: Macierz(m.a,m.b)
	{
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				this->tab2d[i][j] = m.tab2d[i][j];
			}
		}
		delete m.tab2d;
		m.a=0;
		m.b=0;
	}
	
	Macierz& Macierz::operator= ( Macierz &m){
		
		if (&m == this)
   	        return *this;
		Macierz *wynik = new Macierz(m);
			return *wynik;
	}
	
	Macierz&& Macierz::operator= ( Macierz &&m){
		
		
	}
	
	Macierz::~Macierz(){
		delete tab2d;
		a=0;
		b=0;
	}
	
//--//OPERATORY------------------------------------------------------------------------------------------------------------------------------------------------
	/*Macierz operator+ (const Macierz &x, const Macierz &y){
		
		if((x.a != y.a || x.b != y.b) || (x.a != x.b) || (y.a != y.b))
		{
			throw ("ROZMIAR NIE PASUJE");
		}
		else
		{
			int rozmiar = x.a;
			Macierz *nowa = new Macierz(rozmiar);
			for(int i=0; i<x.a; i++)
				for(int j=0;j<x.a;j++)
					nowa->tab2d[i][j] = x.tab2d[i][j] + y.tab2d[i][j];
			return *nowa;
		}
	}*/
	
	Macierz& Macierz::operator+= (const Macierz &x){
		if((x.a != this->a || x.b != this->b) || (x.a != x.b) || (this->a != this->b))
		{
			throw ("ROZMIAR NIE PASUJE");
		}
		else
		{
			for(int i=0; i<this->a; i++)
				for(int j=0;j<this->a;j++)
					this->tab2d[i][j] += x.tab2d[i][j];
		}
	}
			
	//Macierz operator- (const Macierz &x, const Macierz &y);
		//throw (rozmiary_nie_pasuja);
	Macierz & Macierz::operator-= (const Macierz &x){
		
		if((x.a != this->a || x.b != this->b) || (x.a != x.b) || (this->a != this->b))
		{
			throw ("ROZMIAR NIE PASUJE");
		}
		else
		{
			for(int i=0; i<this->a; i++)
				for(int j=0;j<this->a;j++)
					this->tab2d[i][j] -= x.tab2d[i][j];
		}
	}
			
	//Macierz operator* (const Macierz &x, const Macierz &y);
		//throw (rozmiary_nie_pasuja);
	Macierz & Macierz::operator*= (const Macierz &x){
		
		Macierz *pom = new Macierz(a,x.b);
		
		if(this->a != x.b)
		{
			throw ("ROZMIAR NIE PASUJE");
		}
		else
		{
			int pole=0;
			for(int i=0; i<this->a; i++)
			{
				for(int j=0;j<x.b;j++)
				{
					pole += this->tab2d[i][j] * x.tab2d[j][i];			
					pom->tab2d[i][j] = pole;
					pole=0;	
				}
			}
			
			this->tab2d = pom->tab2d;
			this->a=pom->a;
			this->b=pom->b;
		}
	}
				
	//Macierz operator* (const Macierz &x, float alfa);
		//throw (rozmiary_nie_pasuja);
	Macierz & Macierz::operator*= (float alfa){
		for(int i=0; i<this->a; i++)
			for(int j=0;j<this->b;j++)
				this->tab2d[i][j] *= alfa;
	}
				
	Macierz & Macierz::operator~(){
		Macierz *pom = new Macierz(b,a);
		
		for(int i=0;i<a;i++)
			for(int j=0; j<b;j++)
				pom->tab2d[j][i]=this->tab2d[i][j];
		
		this->tab2d = pom->tab2d;
		this->a=pom->a;
		this->b=pom->b;
	}
