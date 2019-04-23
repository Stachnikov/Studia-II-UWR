#ifndef STRUM
#define STRUM

#include <iostream>
#include <iomanip>
#include <fstream>

namespace strumienie
{

	inline std :: istream& clearline(std ::istream &imp){
		char c;
	
		do{
			c = imp.peek();
			
			if(c == EOF){
				return imp;
			}
				
			if(c == '\n'){
				imp.get();
				return imp;
			}
			imp.get();
		} while(1);
	}
	
	class ignore {
		int x;
			friend std::istream& operator >>
				(std::istream &inputed, const ignore &ign)
			{ 
				char c;
				int ignor = ign.x; 
				
				c = inputed.peek();
				
				while(ignor >0){
					c = inputed.peek();
					if(c == EOF)
						break;
					if(c == '\n'){
						inputed.get();
						break;
					}
					inputed.get();
					ignor--;
				}
				return inputed;	
			}			
			public:
				ignore (int ignor) : x(ignor){}
		};
	
		std :: ostream &comma(std ::ostream &outputed);
	
		std :: ostream &colon(std ::ostream &outputed);
		
		class index {
			int widt, valu;
				friend std::ostream& operator <<
					(std::ostream &outputed, const index &ind)
					{
						outputed << "[";
						outputed.width(ind.widt);
						outputed << std::right << ind.valu << "]";	
						return outputed;
					}
				public:
					index(int x, int w) : widt(w),valu(x) {};
		};
		
		class wejscie{
			std::ifstream in;
			int read() throw (std::ios_base::failure);
			
			public:
				wejscie() = delete;
				wejscie(char a) throw (std::ios_base::failure);
				wejscie(std::string a) throw(std::ios_base::failure);
				~wejscie() throw(std::ios_base::failure);
				friend std::ifstream& operator>> (std::ifstream &inp, int x);
		};
		
		class wyjscie{
			std::ofstream out;
			void write(int sav) throw (std::ios_base::failure);
			
			public:
				wyjscie() =delete;
				wyjscie(char a) throw (std::ios_base::failure);
				wyjscie(std::string a) throw (std::ios_base::failure);
				~wyjscie() throw (std::ios_base::failure);
				friend std::ofstream& operator<< (std::ofstream &outp, int x);
		};
		
}
#endif
