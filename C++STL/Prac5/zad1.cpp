#include <iostream>
#include <vector>

using namespace std;

void split(string in, vector<string> &vec)
{
	string temp;
	for(unsigned int i =0; i<in.length(); i++)
	{
		if(in[i] != ' ')
		{
			temp +=in[i];
		}
		else if(temp.length()>0)
		{
			vec.push_back(temp);
			temp="";
		}
	}
	vec.push_back(temp);
}

bool isNum(string symbol){
	if(symbol[0] >= '0' && symbol[0] <= '9')
		return true;
	if(symbol[0] == '-' && symbol.length() > 1 && symbol[1] >= '0' && symbol[1] <= '9')
		return true;
	return false;
}

string ONP(vector<string> &vec)
{
	vector<string> stack;
	string result;
	
	for(unsigned int i=0; i<vec.size(); i++)
	{
		if(isNum(vec[i]))
		{
			result += vec[i] + " ";
		}
		else
		{
			if(vec[i] == "(")
			{
				stack.push_back(vec[i]);
			}
			else if(vec[i] == ")")
			{
				while(stack.back() != "(")
				{
					result += stack.back() + " ";
					stack.pop_back();
				}
				stack.pop_back();
			}
			else
			{
				if(vec[i] == "+" || vec[i] == "-")
				{
					while(!stack.empty() && stack.back() != "(")
					{
						result += stack.back() + " ";
						stack.pop_back();
					}
					stack.push_back(vec[i]);
				}
				else if(vec[i] == "*" || vec[i] == "/")
				{
					while(!stack.empty() && (stack.back() == "/" || stack.back() == "*" || stack.back() == "^"))
					{
						result += stack.back() + " ";
						stack.pop_back();
					}
					stack.push_back(vec[i]);
				}
				else if(vec[i] == "^")
				{
					stack.push_back(vec[i]);
				}
			}
		}
	}
	while(!stack.empty())
	{
		result += stack.back();
		stack.pop_back();
	}
	
	return result;
}



int main(){
	//string input = "( 1 + 2 * 3 - 4 ) / ( 5 + 6 )";
	//string input = "( ( 2 + 7 ) / 3 + ( 14 - 3 ) * 4 ) / 2 ";
	//string input = "( 7 + 3 ) * ( 5 - 2 ) ^ 2";
	//string input = "4 / ( 3 - 1 ) ^ ( 2 * 3 )";
	string input = " ( 15 - 3 ) ^ ( 3 + 2 ) * 6 /  3 ";
	//string input = "-4 + 5 * 2";
	
    vector<string> v;
    split(input, v);

	for( string i : v){
		cout << i;
	}

    string res;
    res = ONP(v);

    cout << endl << res;
	
	
	
	return 0;
}
