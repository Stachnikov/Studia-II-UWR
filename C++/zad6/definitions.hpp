#ifndef WYRAZENIE
#define WYRAZENIE

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

class Wyrazenie {
    public:
    int priorytet=0;
	virtual double oblicz()=0;
    virtual std::string opis()=0;
};

class Liczba : public Wyrazenie {
    private:
	double wartosc=0;
    
    public:
    Liczba(double liczb);
    double oblicz() override;
    std::string opis() override;
};

class Stala : public Wyrazenie {
	protected:
    	double wartosc=0;
    	std::string nazwa="";
    public:
    	Stala();
    	double oblicz() override;
    	std::string opis() override;
};

class pi : public Stala  {
	public:
		pi();
};

class e : public Stala {
	public:
		e();
};

class fi : public Stala {
	public:
		fi();
};

class Zmienna : public Wyrazenie {
    private : 
		static std::vector<std::pair<std::string,double>> zmienne;
		std::string nazwa;
    public : 
    	Zmienna (std::string klucz);
    	Zmienna (std::string klucz,double wart);
		static void nadaj_wartosc(std::string klucz, double wartosc);
		static double czytaj(std::string klucz);
    	double oblicz() override;
    	std::string opis() override;
};

class Operator1arg : public Wyrazenie{
	public:
	Wyrazenie *w1;
	~Operator1arg();
};

class Operator2arg : public Operator1arg{
	public:
	Wyrazenie *w2;
	~Operator2arg();
};

class Dodaj : public Operator2arg {
  //  private:
	//	Wyrazenie *w1;
    //	Wyrazenie *w2;
    public:
    	Dodaj(Wyrazenie *w1,Wyrazenie *w2);
    	double oblicz() override;
    	std::string opis() override;
};

class Odejmij : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
    public:
	    Odejmij(Wyrazenie *w1,Wyrazenie *w2);
	    double oblicz() override;
	    std::string opis() override;
};

class Mnoz : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
	public:
	    Mnoz(Wyrazenie *w1,Wyrazenie *w2);    
		double oblicz() override;
	    std::string opis() override;
};

class Dziel : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
	public:
	    Dziel(Wyrazenie *w1,Wyrazenie *w2);  
	    double oblicz() override;
	    std::string opis() override;
};

class Potega : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
	public:
	    Potega(Wyrazenie *w1,Wyrazenie *w2);  
	    double oblicz() override;
	    std::string opis() override;
};

class Modulo : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
	public:
	    Modulo(Wyrazenie *w1,Wyrazenie *w2);  
	    double oblicz() override;
	    std::string opis() override;
};

class Logarytm : public Operator2arg {
//	private:
//	    Wyrazenie *w1;
//	    Wyrazenie *w2;
	public:
	    Logarytm(Wyrazenie *w1,Wyrazenie *w2);  
	    double oblicz() override;
	    std::string opis() override;
};

class Przeciwny_znak : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public: 
	    Przeciwny_znak(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Wartosc_bezw : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public:   
	    Wartosc_bezw(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Odwrotnosc : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public:  
	    Odwrotnosc(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Sinus : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public:   
	    Sinus(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Cosinus : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public:   
	    Cosinus(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Ln : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public:   
	    Ln(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};

class Exp : public Operator1arg {
//	private:
//	    Wyrazenie *w1;
	public: 
	    Exp(Wyrazenie *w1);  
	    double oblicz() override;
	    std::string opis() override;
};


#endif
