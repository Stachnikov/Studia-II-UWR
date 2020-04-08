#include <random>
#include <iostream>
#include <chrono>
#include <fstream>

int main() {
    std::ofstream file1("ZAD - uniform.csv"), file2("ZAD - binomial.csv"), file3("ZAD - normal.csv");
    
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
    std::mt19937_64 rng(seed);
    
    std::uniform_real_distribution<double> uni(0,1000);
    std::binomial_distribution<> bio(10, 0.5);
    std::normal_distribution<> norm{10,4};
    for(int i=0; i<1000; i++){
        file1 << uni(rng) << "\n";
        file2 << bio(rng) << "\n";
        file3 << norm(rng) << "\n";
    }
    file1.close();
    file2.close();
    file3.close();
    return 0;
}
