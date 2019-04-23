#ifndef EXCEPT
#define EXCEPT

class wyjatek_wymierny : public std::exception {
	public:
	const char *what() const throw(){
		return "Exception";
	}
	
};

class dzielenie_przez_0 : public wyjatek_wymierny{
	public : 
	const char *what() const throw(){
		return "DZIELENIE PRZEZ 0...";
	}
};

class przekroczenie_zakresu : public wyjatek_wymierny{
	public:
	const char *what() const throw(){
		return "PRZEKROCZENIE ZAKRESU INT...";
	}
};

















#endif
