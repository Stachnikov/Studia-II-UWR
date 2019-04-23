#ifndef DEFIN
#define DEFIN

#include <iostream>
#include <stdexcept>
#include <cmath>


class wektor{
	public:
		const double dx=0;
		const double dy=0;
		
	wektor() = default;
	wektor(const double x, const double y);// : dx(x) , dy(y) {};
	wektor(const wektor &v); // : dx(v.dx) , dy(v.dy) {};
	wektor &operator = (const wektor&)=delete;
};

class punkt{
	public:
		const double x=0;
		const double y=0;
		
	punkt() = default;
	punkt(const double xp, const double yp);// : x(xp) , y(yp) {};
	punkt(const punkt &p, const wektor &v);// : x(p.x + v.dx) , y(p.y + v.dy) {};
	punkt(const punkt &p);// : x(p.x) , y(p.y) {};
	punkt &operator = (const punkt&)=delete;
};

class prosta{
	private :
		double a;
		double b;
		double c;
		
	public:
	double getA() const;/*{
        return this->a;
    }*/
        
    double getB() const;/*{
        return this->b;
    }*/
    
    double getC() const;/*{
        return this->c;
    }*/
    
    bool czy_prostopadla(const wektor &w);/*{
    	if(this->a == w.dx && this->b == w.dy)
    	return 1;
    	else
    	return 0;
	}*/
    
	bool czy_rownolegla(const wektor &w);/*{
    	if(w.dx == 1 && w.dy== this->a)
    	return 1;
    	else
    	return 0;
	}*/

	bool czy_lezy(const punkt &p);/*{
    	if(this->b*p.y == this->a*p.x + this->c)
    	return 1;
    	else
    	return 0;
	}*/
		
	public:
	
	prosta(const punkt &p1, const punkt &p2);/* : 	a(-(p2.y-p1.y))		,		b(p2.x-p1.x)		,		c(((p2.x-p1.x)*(-p1.y))-((p2.y-p1.y)*(-p1.x))) 
	{
		if (p1.x==p2.x && p1.y==p2.y)
			throw std::invalid_argument("Nie mo¿na jednoznacznie utworzyæ prostej");
	};*/
	
	prosta(const wektor &v);// :		a(-1/(-(v.dy)))		,		b(1)			,		c(v.dy - (a * v.dx)) {};
	
	prosta(double A, double B, double C);/* :	 a(A) 	,	b(B)	,	c(C)	
	{	if (A==0 || B==0)
			throw std::invalid_argument("Wspolczynniki A i B nie moga byc jednoczesnie rowne 0");		
	} ;*/
	
	prosta(const prosta &p,const wektor &v);// :		a(p.a)			,		b(1)				,		c(p.c + v.dy - (p.a*v.dx))		{};
	prosta();
	prosta &operator = (const prosta&) = delete;
	prosta (const prosta&) = delete;
    
};

	wektor* dodajwektory(const wektor &v1, const wektor &v2);
	bool czyPprost (const prosta &p1, const prosta &p2);
	bool czyProwno (const prosta &p1, const prosta &p2);
	punkt *przeciecie(const prosta &p1, const prosta &p2);
	
#endif
