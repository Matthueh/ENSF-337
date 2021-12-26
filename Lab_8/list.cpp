// File: list.cpp
// Exercise B
// Matthew Ho (30052684)
// Lab Section: B01 
// Date submitted:11/26/2020



#include "list.h"
#include "hydro.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>


FlowList::FlowList()
:headM(0)
{	
}

FlowList::FlowList(const FlowList& source) //this just copy's another source
{
	copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs) //this is an overloaded operator for equals so that we can use it later in the main function
{
	if (this != &rhs)
	{
		destroy();
		copy(rhs);
	}
	return *this;
}



FlowList::~FlowList()
{
	destroy();
}


void FlowList::save()
{
	ofstream out_file;
	out_file.open("flow.txt");
	
	if(!out_file)
	{
		cout << "The file has not been opened successfully\n";
	}
	if(headM !=0)
	{
		out_file  <<headM->item.year << "   " << headM->item.flow << "\n";
		for(const Node *save = headM->next; save != 0; save = save->next)
		{
			out_file  << save->item.year << "  " << save->item.flow <<   "\n";
		}
	}
	out_file.close();
}


void FlowList::display()
{
	Node *new_node = new Node;
	new_node = headM;
	while(new_node != 0)
	{
		cout << new_node->item.year << "   " << new_node->item.flow << "\n";
		new_node = new_node->next;
	}
	
}


void FlowList::insert(const int year, double flow)
{
	Node *new_node = new Node;
	new_node->item.year = year;
	new_node->item.flow = flow;
	
	if(headM == 0|| year < headM ->item.year)
	{
		new_node->next = headM;
		headM = new_node;
		
	}
	else{
		Node *before = headM;
		Node *after = headM->next;
		while(after != 0 && year > after->item.year)
		{
			before = after;
			after = after->next;
			
		}
		new_node->next = after;
		before->next = new_node;
	} 
	
}




void FlowList::remove(int Year)
{
    if (headM == 0 || Year < headM->item.year)
	{
        return;
	}
    
    Node *doomed_node = 0;
    if (Year == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
		delete doomed_node;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && Year > maybe_doomed->item.year) {
			before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
		if(Year == maybe_doomed->item.year)
		{
			before->next = maybe_doomed->next;
			delete maybe_doomed;
		}	
    }	
}




int FlowList::avg()
{
	double a = 0;
	double count = 0;
	Node *new_node = new Node;
	new_node = headM;
	while(new_node->next != 0)
	{
		a = a + new_node->item.flow;
		count++;
		new_node = new_node->next; 
	}
	a = a + new_node->item.flow;
	a = a/count;
	return a;
}






void FlowList::copy(const FlowList& source)
{
	Node *before = source.headM;
	Node *after = source.headM->next;
	Node *List_Nodes = new Node;
	headM = List_Nodes;
	
	if(source.headM != 0)
	{
		List_Nodes->item.year = before->item.year;
		List_Nodes->item.flow = before->item.flow;
	
		while(1)
		{
			Node *new_node = new Node;
			List_Nodes->next = new_node; 
			new_node->item.year = after->item.year;
			new_node->item.flow = after->item.flow;
			new_node->next = 0;
			before = after;
			if(after->next == 0)
			{
				break;
			}
			else
			{ 
				after = after->next;
			}
			List_Nodes = List_Nodes->next;
		}
	}
}




void FlowList::destroy ()
{
	if(headM != 0)	
	{
		Node *next_one = new Node;
		next_one = headM->next;
		Node *deletion = new Node;
		deletion = headM;
		delete deletion;
		while(1)
		{
			if(next_one->next != 0)
			{			
				deletion = next_one;
				next_one = next_one->next;
				delete deletion;

			}
			else
			{
				deletion = next_one;
				delete deletion;
				break;
			}
		}
		cout << "\n";
		cout << "\nThe list has been successfully destroyed\n";
	}
	else{
		cout << "The list has not been successfully destroyed\n";
	}
	
	headM = 0;
	
}


