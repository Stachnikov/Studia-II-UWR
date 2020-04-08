#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

class line_writer { //shared_ptr
    public:
        ofstream &outfile;

    line_writer(ofstream &name): outfile(name){}

    void write(string line){
        outfile << line << endl;
    }

    ~line_writer(){
        outfile.close();
        cout << "File Closed" << endl;
    }
};

int main(){

    ofstream outfile("Test.txt");
        
	shared_ptr<line_writer> data1 = make_shared<line_writer>(outfile);
    shared_ptr<line_writer> data2 = data1;
    shared_ptr<line_writer> data3 = data1;
    shared_ptr<line_writer> data4 = data1;
        
	vector<shared_ptr<line_writer>> files;
        
    files.push_back(data1);
    files.push_back(data2);
    files.push_back(data3);
    files.push_back(data4);
        
        
    int counter = 1;
    for(auto ptr : files){
        ptr->write(to_string(counter));
        counter++;
    }
        
}
