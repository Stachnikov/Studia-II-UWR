#include "definitions.hpp"

	//wektor::wektor() = default;
	wektor::wektor(const double x, const double y) : dx(x) , dy(y) {};
	wektor::wektor(const wektor &v) : dx(v.dx) , dy(v.dy) {};
	//wektor::wektor &operator = (const wektor&)=delete;
	
	//punkt::punkt() = default;
	punkt::punkt(const double xp, const double yp) : x(xp) , y(yp) {};
	punkt::punkt(const punkt &p, const wektor &v) : x(p.x + v.dx) , y(p.y + v.dy) {};
	punkt::punkt(const punkt &p) : x(p.x) , y(p.y) {};
	//punkt::punkt &operator = (const punkt&)=delete;

	prosta::prosta(const punkt &p1, const punkt &p2) : 	a(-(p2.y-p1.y))		,		b(p2.x-p1.x)		,		c(((p2.x-p1.x)*(-p1.y))-((p2.y-p1.y)*(-p1.x))) 
	{
		if (p1.x==p2.x && p1.y==p2.y)
			throw std::invalid_argument("Nie mo¿na jednoznacznie utworzyæ prostej");
	};
	
	prosta::prosta(const wektor &v) :		a(-1/(-(v.dy)))		,		b(1)			,		c(v.dy - (a * v.dx)) {};
	
	prosta::prosta(double A, double B, double C) :	 a(A) 	,	b(B)	,	c(C)	
	{	if (A==0 || B==0)
			throw std::invalid_argument("Wspolczynniki A i B nie moga byc jednoczesnie rowne 0");		
	} ;
	
	prosta::prosta(const prosta &p,const wektor &v) :		a(p.a)			,		b(1)				,		c(p.c + v.dy - (p.a*v.dx))		{};
	//prosta::prosta();
	//prosta::prosta &operator = (const prosta&) = delete;
	//prosta::prosta (const prosta&) = delete;




	double prosta::getA() const{
        return this->a;
    }
        
    double prosta::getB() const{
        return this->b;
    }
    
    double prosta::getC() const{
        return this->c;
    }
    bool prosta::czy_prostopadla(const wektor &w){
    	if(this->a == w.dx && this->b == w.dy)
    	return 1;
    	else
    	return 0;
	}
    
	bool prosta::czy_rownolegla(const wektor &w){
    	if(w.dx == 1 && w.dy== this->a)
    	return 1;
    	else
    	return 0;
	}

	bool prosta::czy_lezy(const punkt &p){
    	if(this->b*p.y == this->a*p.x + this->c)
    	return 1;
    	else
    	return 0;
	}


	wektor* dodajwektory(const wektor &v1, const wektor &v2){
		wektor* v = new wektor(		v1.dx+v2.dx		,	 v1.dy+v2.dy	);
		return v;
	}
	
	bool czyPprost (const prosta &p1, const prosta &p2){
		if(p1.getA() == (-1/(p2.getA())))
		return 1;
		else
		return 0;
	}
	
	bool czyProwno (const prosta &p1, const prosta &p2){
		if(p1.getA() == p2.getA())
		return 1;
		else
		return 0;
	}
	
	punkt *przeciecie(const prosta &p1, const prosta &p2){
		
		double p1a=p1.getA(),	p1b=p1.getB(),	p1c=p1.getC(),	p2a=p2.getA(),	p2b=p2.getB(),	p2c=p2.getC();
		double x,y;
		
		x=(((p2c/p2b)-(p1c/p1b))/((p1a/p1b)-(p2a/p2b)));
		y=-((p1a/p1b) * (x) + (p1c/p1b));
		punkt* p = new punkt( x, y);
		
		return p;
	}

