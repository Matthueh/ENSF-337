//  ENSF 337 Fall 2020 - Exercise B
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

const int size = 6;
using namespace std;
struct City {
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char* filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char* filename);
/* PROMISES: attaches an ifstream object to a binary file named "filename" and
 * reads the content of the file (one record at a time and displays it on the
 * screen.
 */

int main() {
    char bin_filename[] = "cities.bin";
    
    City cities[size] = {{100, 50, "Calgary"},
        {100, 150, "Edmonton"},
        {50, 50, "Vancouver"},
        {200, 50, "Regina"},
        {500, 50, "Toronto"},
        {200, 50, "Montreal"}};
    
    write_binary_file(cities, size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char* filename){
    ofstream stream(filename, ios::out | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }
    
    for(int i =0; i < size; i++)
        stream.write((char*)&cities[i], sizeof(City));
    stream.close();
}

// Name: Matthew Ho 30052684
// Lab Section: B01
// Date submitted: 12/2/2020
// Course: ENSF 337
// Exercise B

void print_from_binary(char* filename) {
    /* Studnets must complete the implementaiton of this file. */
	City city_array[100];
	int number_of_cities;
	ifstream in_file(filename, ios::in |ios::binary);
	if(!in_file)
	{
		cout << "The file cannot be open...\n";
		exit(1);
	}
	in_file.seekg(0L, ios::end);
	
	number_of_cities = in_file.tellg()/sizeof(City);
	
	in_file.seekg(0L, ios::beg);
	in_file.read((char*)city_array, sizeof(City)*number_of_cities);
	
	for(int i =0; i < number_of_cities; i++)
	{
		cout <<"\n"<<"Name: "<< city_array[i].name<< ", "
		<< "x coordinate: "<<city_array[i].x<< ", "
		<< "y coordinate: "<<city_array[i].y;
	}
	
}



