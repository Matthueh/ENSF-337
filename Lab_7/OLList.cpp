// File: OLList.cpp
// Matthew Ho (30052684)
// ENSF 337  Lab 8 Exercise A
// Date submitted: 11/26/2020
// Lab Section: B01 

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    //this is the checking the first node
    if (itemA == headM->item) {
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
			before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
		if(itemA == maybe_doomed->item)
		{
			before->next = maybe_doomed->next;
			delete maybe_doomed;
		}	
    }	
}

void OLList::destroy()
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
		cout << "The list has been successfully destroyed\n";
	}
	else{
		cout << "The list has not been successfully destroyed\n";
	}
	
	headM = 0;
	
}

void OLList::copy(const OLList& source)
{
	Node *before = source.headM;
	Node *after = source.headM->next;
	Node *List_Nodes = new Node;
	headM = List_Nodes;
	
	if(source.headM != 0)
	{
		List_Nodes->item = before->item;
	
		while(1)
		{
			Node *new_node = new Node;
			List_Nodes->next = new_node; 
			new_node->item = after->item;
			new_node->next = 0;
			before = after;
			if( after->next == 0)
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











