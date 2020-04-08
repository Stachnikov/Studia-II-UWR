#include <iostream>
#include <memory>
 
std::weak_ptr<int> wp;
 
void check()
{
    if (!wp.expired()) {
		std::cout << "wp wskazuje na obiekt\n";
    }
    else {
        std::cout << "wp jest wiszacy\n";
    }
}
 
int main()
{
	check();
	
    {
        auto sp = std::make_shared<int>(42);
		wp = sp;
 
		check();
    }
 
    check();
}
