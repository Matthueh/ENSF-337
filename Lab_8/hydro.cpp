// File: hydro.cpp
// Exercise B
// Matthew Ho (30052684)
// Lab Section: B01 
// Date submitted:11/26/2020

#include <iostream> 
#include <fstream>
#include "list.h"
#include "hydro.h"

using namespace std;


int main()
{
	displayHeader();
	FlowList x;
	int Years = 0;
	double Flows = 0;
	int quit = 0;
	readData(x);
	pressEnter();


	while(quit != 1)
	{
		switch(menu()){
			case 1:
					Display(x);
					pressEnter();
					break;
			case 2:
					cout << "Please Enter a Year and a Flow, respectively...\n";
					cin >> Years;
					cin >> Flows;
					addData(x, Years, Flows );
					pressEnter();
					break;

			case 3:
					saveData(x);
					pressEnter();
					break;
			case 4:
					cout << "Please Enter a Year that you would like to remove\n";
					cin >> Years;
					removeData(x, Years);
					pressEnter();
					break;
			case 5:
					cout << "\nProgram terminated!\n\n";
					quit = 1;
					pressEnter();
					break;

				
			default:
				cout << "\nNot a valid input.\n";
				
		}
		if(quit == 1) 
		{
			break;
		}
	}
	return 0;
}

void displayHeader()
{	
	cout << "Program: Flow Studies - Fall 2020\n";
	cout << "Version: 1.0\n";
	cout << "Lab Section: B01\n";
	cout << "Produced by: Matthew Ho (30052684)\n";
}

void Display(FlowList &flow_list)
{							
	flow_list.display();
	cout << "\n" << "The average value contained in this list is:   " << average(flow_list) << "\n"; //make sure we have whatever we want for average
}


void saveData(FlowList &flow_list)
{
	flow_list.save();
	cout << "The file has been saved\n";
}


void removeData(FlowList &flow_list, int year)
{
	flow_list.remove(year);
	cout << "The year has been removed\n";
}

int average(FlowList& flow_list)
{
	return flow_list.avg();
}


void addData(FlowList& flow_list, int Years, double Flows)
{
	flow_list.insert(Years, Flows);
}


void pressEnter()
{
	cout<<"\n" << "<<<Please Press Enter to Continue>>>" << "\n";
	
	while(cin.get() == 0)
	{
		cout<<"\n" << "<<<Please Press Enter to Continue>>>" << "\n";
	}
}


int readData(FlowList &flow_list) //recieves two arguements where one arguement is the txt file name, and the other arguement is an object of type FlowList that the data will be inserted into
{										      
	int count = 0;
	
	ifstream t_file;
	t_file.open("flow.txt");
	
	int Year;
	double Flow;
	
	t_file >> Year >> Flow;
	addData(flow_list, Year, Flow);
	
	while(!t_file.eof())
	{
		t_file >> Year >> Flow;
		addData(flow_list, Year, Flow);
		count++;
	}
	t_file.close();
	cout << "Data has been read correctly\n";
	return count;
}


int menu() 
{
	int option = 0;
	cout << "\nPlease select one of the following operations\n";
	cout << "	1. Display flow list, and the average.\n";
	cout << "	2. Add data.\n";
	cout << "	3. Save data into the file.\n";
	cout << "	4. Remove data.\n";
	cout << "	5. Quit.\n";
	cout << "	Enter your choice (1, 2, 3, 4, 5):\n";

	cin >> option;

	return option;
}



