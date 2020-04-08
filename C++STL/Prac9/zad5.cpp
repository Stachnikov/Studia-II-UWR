#include <iostream>
#include <iterator>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;


std::size_t size_of_files_in_directory(fs::path path)
{
    std::size_t size_of_files = 0u;
    for (auto const & file : fs::directory_iterator(path))
    {
    	if(is_directory(file))
    		size_of_files += size_of_files_in_directory(file);
        else
			size_of_files += file_size(file);
   	}
   	return size_of_files;
}

int main(){
	fs::path directory = "C:\\Users\\asmik\\Desktop\\4,5 SEMESTR\\C++STL\\Prac9";
	if(fs::exists(directory))
		std::cout << "Size of files in " << directory.string() << " is " << size_of_files_in_directory(directory) << " bytes\n";
	else
		std::cout << directory.string() << " DO NOT EXIST";
	return 0;
}
