#include <iostream>
#include <iterator>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;


void write_down(fs::path path)
{
	auto ftime = fs::last_write_time(path);
    std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
    
	std::cout << "Name : " << path.filename().string() << std::endl;
	std::cout << "Path : " << path.string() << std::endl;
	if(is_regular_file(path))
		std::cout << "Size of file : " << file_size(path) << std::endl;
    std::cout << "Last time modified : " << std::asctime(std::localtime(&cftime));
}

int main(int argc, char *argv[]){
	for (int i = 1; i < argc; ++i) {
		fs::path path(argv[i]);
		if(fs::exists(path))
		{
			std::cout << "\n- - - - - - - - - - - - - - - - - - - -\n";
			write_down(path);
			std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n";
		}
		else
			std::cout << path.string() << " DO NOT EXIST";
	}
	return 0;
}
