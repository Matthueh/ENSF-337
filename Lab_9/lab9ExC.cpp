// ENSF 337 - Lab 9 - exercise C
// lab9ExC.cpp

#include<vector>
#include<string>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

typedef vector<string> String_Vector;

String_Vector transpose(const String_Vector& sv);
// REQUIRES:
//    sv.size() >= 1
//    All the strings in sv are the same length, and that length is >= 1.
// PROMISES:
//    Return value is the "transpose" of sv, as defined in the Exercise B
//    instructions.

int main() {
    
    const int ROWS = 7;
    const int COLS = 8;
    
    char c = 'A';
    String_Vector sv;
    sv.resize(ROWS);
    
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++) {
            sv.at(i).push_back(c);
            c++;
            if(c == 'Z' + 1)
                c = 'a';
            else if (c == 'z' + 1)
                c = 'A';
        }
    
    
    for(int i = 0; i < ROWS; i++) {
        cout<< sv.at(i);
        cout << endl;
    }
    
    String_Vector vs = transpose(sv);
    for(int i = 0; i < (int)vs.size(); i++)
        cout << vs.at(i) << endl;
    
    return 0;
}

// Name: Matthew Ho 30052684
// Lab Section: B01
// Date submitted: 12/2/2020
// Course: ENSF 337
// Exercise C


String_Vector transpose (const String_Vector& sv) {
    
    // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FUNCTION.
    String_Vector vs; 
	
	int i = 0;
	int j;
	int Row = sv.at(i).size(); //this has to do with type so a long unsigned int is not the same as an int it may have the potential to wrap around
	int Column = sv.size();
	
	vs.resize(sv.at(i).size());
	
	for(i = 0; i < Row; i++) 
	{
		vs.at(i).resize(sv.size()); 
	}
	
	cout << "\nThe Transpose of this matrix is as follows: \n\n";
	
	for(i = 0; i < Row; i++)
	{
		for( j = 0; j < Column; j++)
		{
			vs.at(i).push_back(sv.at(j).at(i));  
		}
	}
	
    return vs;
    
}










