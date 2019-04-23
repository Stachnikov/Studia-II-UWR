#include "definitions.hpp"

Liczba :: Liczba(double liczb){
	priorytet=5;
	wartosc=liczb;
}

double Liczba :: oblicz(){
	return this->wartosc;
}

std::string Liczba :: opis(){
	std::ostringstream strs;
	strs << wartosc;
	std::string str = strs.str();
	return str;
}

Stala :: Stala(){
	priorytet=5;
	wartosc=0;
	nazwa="";
}

double Stala :: oblicz(){
	return wartosc;
}

std::string Stala :: opis(){
	return nazwa;
}

pi :: pi(){
	priorytet=5;
	wartosc=3.14159;
	nazwa="pi";
}

e :: e(){
	priorytet=5;
	wartosc=2.71828;
	nazwa="e";
}

fi :: fi(){
	priorytet=5;
	wartosc=1.61803;
	nazwa="fi";
}

std::vector<std::pair<std::string,double>> Zmienna :: zmienne;

Zmienna :: Zmienna(std::string klucz){
	int priorytet=5;
	nazwa= klucz;
	Zmienna :: zmienne.push_back(make_pair(klucz, 0));
}

Zmienna :: Zmienna(std::string klucz, double wart){
	int priorytet=5;
	nazwa= klucz;
	Zmienna :: zmienne.push_back(make_pair(klucz, wart));
}

void Zmienna :: nadaj_wartosc(std::string klucz, double wart){
	for(auto &k : zmienne){
		if(k.first == klucz)
			k.second = wart;
	}
}

double Zmienna :: czytaj(std::string klucz){
	for(auto &k : zmienne){
		if(k.first==klucz)
			return k.second;
		else
			return 1;
	}
}

double Zmienna :: oblicz(){
	return czytaj(this->nazwa);
}

std::string Zmienna :: opis(){
	return this->nazwa;
}

Operator1arg :: ~Operator1arg(){
	delete w1;
}

Operator2arg :: ~Operator2arg(){
	delete w2;
}

Dodaj :: Dodaj(Wyrazenie *a,Wyrazenie *b){
	priorytet=1;
	w1=a;
	w2=b;
}

double Dodaj :: oblicz(){
	return w1->oblicz() + w2->oblicz();
}

std::string Dodaj :: opis(){
	return w1->opis() + " + " + w2->opis();
}

Odejmij :: Odejmij(Wyrazenie *a,Wyrazenie *b){
	priorytet=1;
	w1=a;
	w2=b;
}

double Odejmij :: oblicz(){
	return w1->oblicz() - w2->oblicz();
}

std::string Odejmij :: opis(){
	if(this->priorytet < w1->priorytet && this->priorytet < w2->priorytet)
		return w1->opis() + " - " + w2->opis();
	else if(this->priorytet < w1->priorytet)
		return w1->opis() + " - (" + w2->opis() + ")";
	else if(this->priorytet < w2->priorytet)
		return w1->opis() + " - " + w2->opis();
	else
		return w1->opis() + " - (" + w2->opis() + ")";
}

Mnoz :: Mnoz(Wyrazenie *a,Wyrazenie *b){
	priorytet=2;
	w1=a;
	w2=b;
}

double Mnoz :: oblicz(){
	return w1->oblicz() * w2->oblicz();
}

std::string Mnoz :: opis(){
	if(this->priorytet < w2->priorytet && this->priorytet < w1->priorytet)
		return w1->opis() + " * " + w2->opis();
	else if(this->priorytet < w1->priorytet)
		return w1->opis() + " * (" + w2->opis() + ")";
	else if(this->priorytet < w2->priorytet)
		return "(" + w1->opis() + ") * " + w2->opis();
	else
		return "(" + w1->opis() + ") * (" + w2->opis() + ")";
}

Dziel :: Dziel(Wyrazenie *a,Wyrazenie *b){
	priorytet=2;
	w1=a;
	w2=b;
}

double Dziel :: oblicz(){
	return  w1->oblicz() / w2->oblicz();
}

std::string Dziel :: opis(){
	if(this->priorytet < w2->priorytet && this->priorytet < w1->priorytet)
		return w1->opis() + " / " + w2->opis();
	else if(this->priorytet < w1->priorytet)
		return w1->opis() + " / (" + w2->opis() + ")";
	else if(this->priorytet < w2->priorytet)
		return "(" + w1->opis() + ") / " + w2->opis();
	else
		return "(" + w1->opis() + ") / (" + w2->opis() + ")";
}

Potega :: Potega(Wyrazenie *a,Wyrazenie *b){
	priorytet=3;
	w1=a;
	w2=b;
}

double Potega :: oblicz(){
	return pow(w1->oblicz(), w2->oblicz());
}

std::string Potega :: opis(){
	if(this->priorytet < w2->priorytet && this->priorytet < w1->priorytet)
		return w1->opis() + " ^ " + w2->opis();
	else if(this->priorytet < w1->priorytet)
		return w1->opis() + " ^ (" + w2->opis() + ")";
	else if(this->priorytet < w2->priorytet)
		return "(" + w1->opis() + ") ^ " + w2->opis();
	else
		return "(" + w1->opis() + ") ^ (" + w2->opis() + ")";	
}

Modulo :: Modulo(Wyrazenie *a,Wyrazenie *b){
	priorytet=3;
	w1=a;
	w2=b;
}

double Modulo :: oblicz(){
	return fmod(w1->oblicz(),w2->oblicz());
}

std::string Modulo :: opis(){
	if(this->priorytet < w2->priorytet && this->priorytet < w1->priorytet)
		return w1->opis() + " % " + w2->opis();
	else if(this->priorytet < w1->priorytet)
		return w1->opis() + " % (" + w2->opis() + ")";
	else if(this->priorytet < w2->priorytet)
		return "(" + w1->opis() + ") % " + w2->opis();
	else
		return "(" + w1->opis() + ") % (" + w2->opis() + ")";
}

Logarytm :: Logarytm(Wyrazenie *a,Wyrazenie *b){
	priorytet=3;
	w1=a;
	w2=b;
}

double Logarytm :: oblicz(){
	return log(w2->oblicz()) / log(w1->oblicz());
}

std::string Logarytm :: opis(){
	return  "log_(" + w1->opis() + ")(" + w2->opis() + ")";
}

Przeciwny_znak :: Przeciwny_znak(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Przeciwny_znak :: oblicz(){
	return -(w1->oblicz());
}

std::string Przeciwny_znak :: opis(){
	return "-" + w1->opis();
}

Wartosc_bezw :: Wartosc_bezw(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Wartosc_bezw :: oblicz(){
	return abs(w1->oblicz());
}

std::string Wartosc_bezw :: opis(){
	return "|" + w1->opis() +"|";
}

Odwrotnosc :: Odwrotnosc(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Odwrotnosc :: oblicz(){
	return 1/(w1->oblicz());
}

std::string Odwrotnosc :: opis(){
	return "(1/" + w1->opis() + ")";
}

Sinus :: Sinus(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Sinus :: oblicz(){
	return sin(w1->oblicz());
}

std::string Sinus :: opis(){
	return "sin(" + w1->opis() + ")";
}

Cosinus :: Cosinus(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Cosinus :: oblicz(){
	return cos(w1->oblicz());
}

std::string Cosinus :: opis(){
	return "cos(" + w1->opis() + ")";
}

Ln :: Ln(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Ln :: oblicz(){
	return log(w1->oblicz());
}

std::string Ln :: opis(){
	return "Ln(" + w1->opis() + ")";
}

Exp :: Exp(Wyrazenie *a){
	priorytet=5;
	w1=a;
}

double Exp :: oblicz(){
	return exp(w1->oblicz());
}

std::string Exp :: opis(){
	return "(e^" +w1->opis() + ")";
}
