// Completed By: Matthew Ho(30052684)
// prog_two.c
// ENSF 337 Fall 2020 Lab 4 Exercise  E
// Lab Section: B01
// Completion date: 10/12/2020

#include <stdio.h>
#include <limits.h>
#include "read_input.h"

#define SIZE 50

int main(void)
{
  double n = 0;
  char digits[SIZE];  

  int y = EOF;
  
  while (1)
    {
      printf("\n\nEnter an double or press Ctrl-D to quit: ");
      y = read_real(digits, SIZE, &n);
  
      if(y == 1)
	printf("\nYour double value is: %lf", n);
      else if(y == EOF){
	printf("\nGood Bye.\n");
	break;
      }
      else
	printf("\n%s is an invalid double.", digits);
    }
    
  return 0;
}