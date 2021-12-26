// File: list.h
// Exercise B
// Matthew Ho (30052684)
// Lab Section: B01 
// Date submitted:11/26/2020
#ifndef FLOWLIST_H
#define FlOWLIST_H

struct ListItem{
	int year;
	double flow;	
};

struct Node{
	ListItem item;
	Node *next;
};


class FlowList
{
public:	
	FlowList(); //these are the constructors
	FlowList(const FlowList& source); // this constructor copies 
	FlowList& operator=(const FlowList& rhs);
	~FlowList(); //this is the destructor
	
	void insert(const int year, const double flow);
	//this will take itemA and it will insert it in the list of structures contained

	void remove(const int year);
	//this will take look through the list and take out itemA
	int avg();

	void save();
	
	void display();
	
private:
	Node *headM;
	void destroy();
	void copy(const FlowList& source);
	//this function becomes a copy of the source
};
#endif