#include <iostream>
#include <ratio>

using namespace std;

//template z funckcja 

int main(){

	typedef std::ratio<1,1> one;
	typedef std::ratio_add<one,ratio<1,2>> two;
	typedef std::ratio_add<two,ratio<1,3>> three;
	typedef std::ratio_add<three,ratio<1,4>> four;
	typedef std::ratio_add<four,ratio<1,5>> five;
	typedef std::ratio_add<five,ratio<1,6>> six;
	typedef std::ratio_add<six,ratio<1,7>> seven;
	typedef std::ratio_add<seven,ratio<1,8>> eight;
	typedef std::ratio_add<eight,ratio<1,9>> nine;
	typedef std::ratio_add<nine,ratio<1,10>> ten;
	typedef std::ratio_add<ten,ratio<1,11>> elev;
	typedef std::ratio_add<elev,ratio<1,12>> t;
	
	cout << "one = " << one::num << "/" << one::den <<endl;
	cout << "two = " << two::num << "/" << two::den <<endl;
	cout << "three = " << three::num << "/" << three::den <<endl;
	cout << "four = " << four::num << "/" << four::den <<endl;
	cout << "five = " << five::num << "/" << five::den <<endl;
	cout << "six = " << six::num << "/" << six::den <<endl;
	cout << "seven = " << seven::num << "/" << seven::den <<endl;
	cout << "eight = " << eight::num << "/" << eight::den <<endl;
	cout << "nine = " << nine::num << "/" << nine::den <<endl;
	cout << "ten = " << ten::num << "/" << ten::den <<endl;
	cout << "elev = " << elev::num << "/" << elev::den <<endl;
	cout << "t = " << t::num << "/" << t::den <<endl;
	
	return 0;
}
