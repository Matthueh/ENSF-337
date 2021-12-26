/* File: lab5exE.c
 * ENSF Fall 2020 - lab 5 - Exercise E
 */

#include "lab5exEPrac.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point alpha = { "A1", 2.3, 4.5} ;
    Point beta = { "B1", 25.9, 30.0 } ;
    printf ("Display the values in alpha, and beta: ");
    display_struct_point(alpha);
    display_struct_point(beta);
    
    Point *stp = &alpha;
    printf ("\n\nDisplay the values in *stp: ");
    display_struct_point(*stp);
    
    Point gamma = mid_point(stp, &beta, "M1");
    printf ("\n\nDisplay the values in gamma after calling mid_point function.");
    printf ("Expected result is: M1 <14.10, 17.25, 76.50>");
    
    printf("\n\nThe actual result of calling mid_point function is: ");
    display_struct_point(gamma);
    
    swap (stp, &beta);
    printf ("\n\nDisplay the values in *stp, and beta after calling swap function.");
    printf ("Expected to be:\nB1 <25.90, 30.00, 97.00>\nA1 <2.30, 4.50, 56.00>");
    
    
    printf("\n\nThe actual result of calling swap function is: ");
    display_struct_point(*stp);
    display_struct_point(beta);
    
    
    printf("\n\nThe distance between alpha and beta is: %.2f. ", distance(&alpha, &beta));
    printf ("(Expected to be: 53.74)");
    printf("\nThe distance between gamma and beta is: %.2f. ", distance(&gamma, &beta));
    printf ("(Expected to be: 26.87)");
    return 0;
}

void display_struct_point(const Point x)
{
    printf("\n%s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.y);
}


Point mid_point(const Point* p1, const Point* p2, const char* label)
{
    // This function is incomplete and must be completed by the students
    // YOU ARE NOT ALLOWED TO USE ANY STRING LIBRARY FUNCTIONS IN THIS FUNCTION
    
    Point middle = {"?", 0, 0};
    
    return middle;
}

void swap(Point* p1, Point *p2)
{
    // This function is incomplete and must be completed by the students
	Point copy = {strlen((*p1).label), 0, 0 ,0};
	
	while( (*p1).label != '\0' )
	{
		(*copy).label = (*p1).label;
		(*p1).label = (*p2).label;
		(*p2).label = (*copy).label;
		copy++;
		p1++;
		P2++;
	}
	
	(*copy).x = (*p1).x;
	(*p1).x = (*p2).x;
	(*p2).x = (*copy).x;
	(*copy).y = (*p1).y;
	(*p1).y = (*p2).y;
	(*p2).y = (*copy).y;
	(*copy).z = (*p1).z;
	(*p1).z = (*p2).z;
	(*p2).z = (*copy).z;
}

double distance(const Point* p1, const Point* p2)
{
    int dis;
	
	dis = sqrt( pow((*p2).x - (*p1).x, 2) + pow((*p2).y - (*p1).y, 2) + pow((*p2).z - (*p1).z, 2))

    return dis;
}

