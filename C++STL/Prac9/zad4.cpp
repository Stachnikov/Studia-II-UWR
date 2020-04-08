#include <iostream>
#include <iterator>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;


void write_down(fs::path path)
{
    for (auto const & file : fs::directory_iterator(path))
    {
    	std::cout << file.path().filename().string() << std::endl;
   	}
}

int main(){
	fs::path directory = fs::current_path();
	if(fs::exists(directory))
	{
		std::cout << directory.string() << " CONTAINS:\n";
		write_down(directory);
	}
	else
		std::cout << directory.string() << " DO NOT EXIST";
	return 0;
}
