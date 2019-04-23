#include "definitions.hpp"

using namespace std;

int main()
{
	punkt p1(2,4);
	wektor v1(0,3);
	
	punkt p2(p1,v1);
	punkt p3;
		
	wektor v2(4,1);
	wektor v3(v2);

	prosta pr1(p1, p2);
	prosta pr2(v1);
	prosta pr3(1,1,1);
	prosta pr3p(-1,4,7);
	prosta pr3r(1,2,5);
	prosta pr4(pr3, v2);
	
	cout << "Punkt p1 = (" << p1.x << ", " << p1.y << ")\n"; 
	cout << "Punkt p2 = (" << p2.x << ", " << p2.y << ")\n"; 
	cout << "Punkt p3 = (" << p3.x << ", " << p3.y << ")\n\n\n"; 
	
	cout << "Wektor v1 = (" << v1.dx << ", " << v1.dy << ")\n";
	cout << "Wektor v2 = (" << v2.dx << ", " << v2.dy << ")\n";
	cout << "Wektor v3 = (" << v3.dx << ", " << v3.dy << ")\n\n\n";
	
	cout << "Prosta pr1 = (" << pr1.getA() << ", " << pr1.getB() << ", " << pr1.getC() << ")\n";
	cout << "Prosta pr2 = (" << pr2.getA() << ", " << pr2.getB() << ", " << pr2.getC() << ")\n";	
	cout << "Prosta pr3 = (" << pr3.getA() << ", " << pr3.getB() << ", " << pr3.getC() << ")\n";
	cout << "Prosta pr3p = (" << pr3p.getA() << ", " << pr3p.getB() << ", " << pr3p.getC() << ")\n";
	cout << "Prosta pr3r = (" << pr3r.getA() << ", " << pr3r.getB() << ", " << pr3r.getC() << ")\n";
	cout << "Prosta pr4 = (" << pr4.getA() << ", " << pr4.getB() << ", " << pr4.getC() << ")\n\n\n";
	
	cout << "Czy proste pr3 i pr3r sa rownolegle ? 0-nie 1-tak : " << czyProwno(pr3, pr3r)<< "\n\n";
	cout << "Czy proste pr3 i pr3p sa prostopadle ? 0-nie 1-tak : " << czyPprost(pr3, pr3p)<< "\n\n";

	cout << "Czy proste pr3 i pr1 sa rownolegle ? 0-nie 1-tak : " << czyProwno(pr3, pr1)<< "\n\n";
	cout << "Czy proste pr3 i pr1 sa prostopadle ? 0-nie 1-tak : " << czyPprost(pr3, pr1)<< "\n\n";	
	
	wektor* vv;
	vv=dodajwektory(v1,v2);
	
	cout << "Dodawanie wektorow v1 i v2 = (" << vv->dx << ", " << vv->dy << ")\n\n";
	
	prosta t1(-2,1,4);
	prosta t2(-3,1,-1);
	
	punkt * pt = przeciecie(t1,t2);


	cout << "Punkt przeciecia t1 i t2  = (" << pt->x << ", " << pt->y << ")\n"; 

	
	return 0;
}
