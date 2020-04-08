#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

template<size_t SIZE, class T> size_t array_size(T (&arr)[SIZE]) { 
    return SIZE;
}

template<typename T> void swap (T *a, T *b)  
{  
    T temp = *a;  
    *a = *b;  
    *b = temp;  
}

template <typename T> void perm(T tab[], int n)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	
	std::default_random_engine dre(seed);
   
  
    for (int i = n - 1; i > 0; i--)  
    {  
		std::uniform_int_distribution<int> di(0,i);  
        int j = di(dre);  
  
        swap(&tab[i], &tab[j]);  
    }  
}

void printArray (auto arr[], int n)  
{  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << "\n";  
}

//Fisher–Yates shuffle Algorithm
int main() {
	
	int tablica[] = { 1, 2, 3, 4, 5 ,6 , 7 };
	int n = sizeof(tablica)/sizeof(tablica[0]);
	printArray(tablica,n);
	perm(tablica,n);
	printArray(tablica,n);
	
	cout << endl << endl;
	
	string str_tab[] = {"a","b","c","d","e","f","g"};
	n = array_size(str_tab);
	printArray(str_tab,n);
	perm(str_tab,n);
	printArray(str_tab,n);
	
	return 0;
}
