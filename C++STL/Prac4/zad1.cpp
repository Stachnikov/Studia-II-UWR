#include <iostream>
#include <vector>
#include <string> 
#include <list>
#include <set>
#include <algorithm>
#include <limits>

//Zadanie 1 (1 pkt).
	//Wypisz wszystkie wartoœci z zadanego zakresu (wiêksze od a i mniejsze od b).
int main(){
    std::vector<double> v1 = {1.2 , 0.7, 0.1, 12.3, 31.1, 5.3, 9.4, 8.1, 1.8, 1.0};
    std::list<std::string> l1 = {"asd", "zxc", "a", "qwe", "qaz", "cxz", "s", "x", "123", "d42"};
    std::set<int> s1 = {1, 2, 0, 4, -2, 42, 12, 8, 321, -123};
    
    
    
	double adob=0.7, bdob =10.2;
	//vector<double>
	std::for_each(v1.begin(), v1.end(), [&adob,&bdob](double num){ if(num < bdob && adob < num) std::cout << num << " "; });
	std::cout<< std::endl;
	
	std::string astr = "cud",bstr="sub";
	//list<string>
	std::for_each(l1.begin(), l1.end(), [&astr,&bstr](std::string str){ if(str < bstr && astr<str) std::cout << str << " "; });
	std::cout<< std::endl;
	
	int aint=-12, bint =10;
	//set<int>
	std::for_each(s1.begin(), s1.end(), [&aint,&bint](int num){ if(num < bint && aint < num) std::cout << num << " "; });
	std::cout<< std::endl;
	
	return 0;
}
