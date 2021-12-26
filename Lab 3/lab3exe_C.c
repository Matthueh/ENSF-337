/*
 *  lab3exe_C.c
 *  ENSF 337, lab3 Exercise C
 *	Student Name: Matthew Ho(30052684)
 *  Lab Section: B01
 *  Date completed:10/5/2020
 */

#include <stdio.h>
#include <stdlib.h>

void pascal_triangle(int n);
/* REQUIRES: n > 0 and n <= 20
 PROMISES: displays a pascal_triangle. the first 5 line of the function's output
 should have the following format:
 row 0:  1
 row 1:  1   1
 row 2:  1   2   1
 row 3:  1   3   3   1
 row 4:  1   4   6   4   1
 */

int main() {
    int nrow;
    // These are ALL of the variables you need!
    printf("Enter the number of rows (Max 20): ");
    scanf("%d", &nrow);
    if(nrow <= 0 || nrow > 20) {
        printf("Error: the maximum number of rows can be 20.\n");
        exit(1);
    }
    
    pascal_triangle(nrow);
    return 0;
}

void pascal_triangle(int n) 
{
    int i = 0;
	int j = 0;
	int k = 0;	
	int next[n];
	int prev1[n];

	while(i < n)
	{
		j = 0;
		while( j <= i)
		{
			if( j == 0 || j == i)
			{
				prev1[j] = 1;
				next[j] = prev1[j];
				printf(" %d ", next[j]);		
			}
			
			else
			{
				next[j] = prev1[j] + prev1[j-1];
				printf(" %d ", next[j]);
			}
		
			j++;
		}
		i++;
		printf("\n");
		k = 0;
		while(k < n)
		{
			prev1[k] = next[k];
			k++;
		}
	}
}
