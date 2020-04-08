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

    // Wyznacz sumê/konkatenacjê wszystkich elementów.
	int int_sum = 0;
    double double_sum =0.0;
    std::string string_sum;
    
	std::for_each(v1.begin(), v1.end(), [&double_sum](double num){double_sum += num; }); std::cout << double_sum << "\n";
    std::for_each(l1.begin(), l1.end(), [&string_sum](std::string str){ string_sum +=str;}); std::cout << string_sum << "\n";
    std::for_each(s1.begin(), s1.end(), [&int_sum](int num){ int_sum += num;}); std::cout << int_sum << "\n"; 
    
	return 0;
}
