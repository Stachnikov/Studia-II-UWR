#include <iostream>

using namespace std;

	template <typename T1, typename T2>
	void foo_impl (const T1 &val, true_type, T2 &cel) {
		cout << "Przed przeniesieniem : wskaznik do " << *cel << endl;
		*cel = *val;
		cout << "Po przeniesieniu : wskaznik do " << *cel << endl;
	}
	
	template <typename T1, typename T2>
	void foo_impl (const T1 &val, false_type, T2 &cel) {
		cout << "Przed przeniesieniem :  wartosc " << *cel << endl;
		*cel=val;
		cout << "Po przeniesieniu : wartosc " << *cel << endl;
	}
	
	template <typename T1, typename T2>
	void foo (T1 val, T2 cel) {
		if (is_convertible<T1, T2>())
 			foo_impl (val, std::is_pointer<T1>(),cel);
 		else
 			cout<< "Not convertible"<<endl;
	}

int main()
{
	int a = 42;
	int aa = 53;
	//float b = 2.0f;
	auto ptra = &a;
	auto ptraa = &aa;
	//auto ptrb = &b;
	foo(ptraa,&a);
	
	return 0;
}
