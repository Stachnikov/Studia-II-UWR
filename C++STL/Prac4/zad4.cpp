#include <iostream>
#include <vector>
#include <string> 
#include <list>
#include <set>
#include <algorithm>
#include <limits>

int main(){
    std::vector<double> v1 = {1.2 , 0.7, 0.1, 12.3, 31.1, 5.3, 9.4, 8.1, 1.8, 1.0};
    std::list<std::string> l1 = {"asd", "zxc", "a", "qwe", "qaz", "cxz", "s", "x", "123", "d42"};
    std::set<int> s1 = {1, 2, 0, 4, -2, 42, 12, 8, 321, -123};

    // Wyznacz element minimalny i maksymalny (zwróæ parê iteratorów).
    int iter,iter1,iter2;
    int imin,imax;
    std::string smin,smax;
    double dmin,dmax;
    
    //INT
    iter = iter1 = iter2 = 0;
    imin = std::numeric_limits<int>::max();
    imax = std::numeric_limits<int>::min();
	std::for_each(s1.begin(), s1.end(), [&imin,&imax,&iter,&iter1,&iter2](int num){
		if(num < imin)
		{
			imin = num;
			iter1 = iter;
		}
		else if(num > imax)
		{
			imax = num;
			iter2 = iter;
		}
		iter++;
		}); 
	std:: cout << "min: " << *std::next(s1.begin(), iter1) << " max: " << *std::next(s1.begin(), iter2) << "\n\n";
    
    
    //STRING
    iter = iter1 = iter2 = 0;
    smin = std::numeric_limits<std::string>::max();
    smax = std::numeric_limits<std::string>::min();
	std::for_each(l1.begin(), l1.end(), [&smin,&smax,&iter,&iter1,&iter2](std::string str){
		if(str < smin)
		{
			smin = str;
			iter1 = iter;
		}
		else if(str > smax)
		{
			smax = str;
			iter2 = iter;
		}
		iter++;
		}); 
	std:: cout << "min: " << *std::next(l1.begin(), iter1) << " max: " << *std::next(l1.begin(), iter2) << "\n\n";
    
    
    //DOUBLE
    iter = iter1 = iter2 = 0;
    dmin = std::numeric_limits<double>::max();
    dmax = std::numeric_limits<double>::min();
    std::for_each(v1.begin(), v1.end(), [&dmin,&dmax,&iter,&iter1,&iter2](double num){
		if(num < dmin)
		{
			dmin = num;
			iter1 = iter;
		}
		else if(num > dmax)
		{
			dmax = num;
			iter2 = iter;
		}
		iter++;
		}); 
	std:: cout << "min: " << *std::next(v1.begin(), iter1) << " max: " << *std::next(v1.begin(), iter2) << "\n\n";
    
	return 0;
}
