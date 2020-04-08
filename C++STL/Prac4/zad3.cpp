#include <iostream>
#include <vector>
#include <string> 
#include <list>
#include <set>
#include <algorithm>

int main(){
    std::vector<double> v1 = {1.2 , 0.7, 0.1, 12.3, 31.1, 5.3, 9.4, 8.1, 1.8, 1.0};
    std::set<int> s1 = {1, 2, 0, 4, -2, 42, 12, 8, 321, -123};

    // Wyznacz œredni¹ arytmetyczn¹ (dotyczy kolekcji z liczbami).
    double sum =0.0;
    auto it = s1.begin();

	std::for_each(v1.begin(), v1.end(), [&sum,&v1](double num){sum += num/v1.size(); }); std::cout << sum << "\n"; sum=0.0;
    std::for_each(s1.begin(), s1.end(), [&sum,&s1,&it](int num){ sum += num; ++it; if(it == s1.end()) sum = (int)(sum/s1.size());}); std::cout << sum << "\n"; 
    
	return 0;
}
