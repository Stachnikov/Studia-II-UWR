#include <iostream>
#include <vector>
#include <string> 
#include <list>
#include <set>
#include <algorithm>

int main(){
    std::vector<double> v1 = {1.2 , 0.7, 0.1, 12.3, 31.1, 5.3, 9.4, 8.1, 1.8, 1.0};
    std::list<std::string> l1 = {"asd", "zxc", "a", "qwe", "qaz", "cxz", "s", "x", "123", "d42"};
    std::set<int> s1 = {1, 2, 0, 4, -2, 42, 12, 8, 321, -123};

    // Wypisanie co k-tej wartosci od p-tej pozycji
    int k = 2, p = 3, iter = 0;
    std::for_each(std::next(v1.begin(), p), v1.end(), [&k,&p,&iter](double num){ if(iter % k == 0) std::cout << num << " "; iter++; }); std::cout << "\n"; iter = 0;
    std::for_each(std::next(l1.begin(), p), l1.end(), [&k,&p,&iter](std::string str){ if(iter % k == 0) std::cout << str << " "; iter++; }); std::cout << "\n"; iter = 0;
    std::for_each(std::next(s1.begin(), p), s1.end(), [&k,&p,&iter](int num){ if(iter % k == 0) std::cout << num << " "; iter++; }); std::cout << "\n"; iter = 0;
	return 0;
}
