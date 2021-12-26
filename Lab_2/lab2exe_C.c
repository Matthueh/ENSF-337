/* Student Name: Matthew Ho (30052684)
 * Exercise C
 * Lab Section: B01
 * lab2exe_C.c
 * ENSF 337 - Lab 2 - Execise C
 * Date completed: 9/28/2020 
 */

#include <stdio.h>
#include <stdlib.h>

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr);


int main(void)
{
  int millisec;
  int minutes;
  double seconds;   
  int nscan;

  printf("Enter a time interval as an integer number of milliseconds: ");
  nscan = scanf("%d", &millisec);
  
  if (nscan != 1) {
    printf("Unable to convert your input to an int.\n");
    exit(1);
  }
  
  printf("Doing conversion for input of %d ms ... \n", millisec);

  time_convert(millisec, &minutes, &seconds);

  printf("That is equivalent to %d minute(s) and %f second(s).\n", minutes,
	 seconds);

  return 0;
}

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr)
{
	const int MilToMin = 60000; 
	const double MilToSec = 1000;

	if(ms_time < 0)
	{
		printf("Invalid Number, Try again \n");
		exit(1);
	}
	
	*minutes_ptr = ms_time/MilToMin;
	*seconds_ptr = (ms_time%MilToMin)/MilToSec; 

}


