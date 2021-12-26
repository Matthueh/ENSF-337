// ENSF 337- Fall 2020, Exercise F
// File: lab5exF.c
// ENSF Fall 2020 - lab 5 - Exercise F
// Matthew Ho(30052684) Alexander Sembrat (30089188)
// M. Moussavi
// Date Submitted 10/19/2020

#include "lab5exF.h"
#include <stdio.h>
#include <math.h>
#include<string.h>

int main(void)
{
    Point struct_array[10];
    int i;
    int position;
    
    populate_struct_array(struct_array, 10);
    
    printf("\nArray of Points contains: \n");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    
    printf("\nTest the search function");
    
    position = search(struct_array, "v0", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "v0");
    
    position = search(struct_array, "E1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E1");
    
    position = search(struct_array, "C5", 10);
    
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "C5");
    
    position = search(struct_array, "B7", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "B7");
    position = search(struct_array, "A9", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "A9");
    position = search(struct_array, "E11", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "E11");
    
    position = search(struct_array, "M1", 10);
    if(position != -1)
        printf("\nFound: struct_array[%d] contains %s", position,
               struct_array[position].label);
    else
        printf("\nstruct_array doesn't have label: %s.", "M1");
    
    printf("\n\nTesting the reverse function:");
    
    reverse(struct_array, 10);
    
    printf("\nThe reversed array is:");
    
    for(i=0; i < 10; i++)
        display_struct_point(struct_array[i], i);
    
    return 0;
}


void display_struct_point(const Point x , int i)
{
    printf("\nstruct_array[%d]: %s <%.2lf, %.2lf, %.2lf>\n",
           i, x.label, x.x, x.y, x.z);
}

void populate_struct_array(Point* array, int n)
{
    int i;
    char ch1 = 'A';
    char ch2 = '9';
    char ch3 = 'z';
    
    for( i = 0; i < 10; i++)
    {
        /* generating some random values to fill them elements of the array: */
        array[i].x = (7 * (i + 1) % 11) * 100 - i /2;
        array[i].y = (7 * (i + 1) % 11) * 120 - i / 3;
        array[i].z = (7 * (i + 1) % 11) * 150 - i /4;
        
        if(i % 2 == 0)
            array[i].label[0] = ch1++;
        else
            array[i].label[0] = ch3--;
        array[i].label[1] = ch2--;
        array[i].label[2] = '\0';
    }
}

int search(const Point* struct_array, const char* label, int n)
{
	int i = 0;
	int count;
	int true = 0;
	int j;
	
	while(i < n)
	{
		j = 0;
		count = 0;
		while(label[j] != '\0')
		{
			if(struct_array[i].label[j] == (*label))
			{
				label++;
				count++;
			}
			j++;
		}
		i++;
		if(count == j)
		{
			count = i - 1;
			true = 1;
			i = n;
		}
	
	}
	
	if(true == 0)
	{
		return -1;
	}
	else 
	{
		return count;
	}
	
    // Students should complete the definiton of this function
    // NOTE: YOU ARE NOT ALLOWED TO USE ANY C LIBRARY FUNCTION IN YOUR SOLUTION
}

void reverse (Point *a, int n)
{
    Point store[n];
	int j = 0;
	int i = 0;
	
	for(i = 0; i < n; i++)
	{	
		for(j = 0; j < n; j++)
		{
			store[i].label[j] = (*a).label[j];
		}
		store[i].x = (*a).x;
		store[i].y = (*a).y;
		store[i].z = (*a).z;
		a++;
	}
	
	for(i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
		{
			(*(a-n)).label[j] = store[n-i-1].label[j];
		}
		(*(a-n)).x = store[n-i-1].x;
		(*(a-n)).y = store[n-i-1].y;
		(*(a-n)).z = store[n-i-1].z;
		a++;	
	}
	
	// Students should complete the definiton of this function
}






