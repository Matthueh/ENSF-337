// Completed By: Matthew Ho(30052684)
// read_double.c
// ENSF 337 Fall 2020 Lab 4 Exercise E
// Lab Section: B01
// Completion date: 10/12/2020
#include "read_input.h"

int read_real(char* digits, int n, double * num)
{
	if(get_string(digits, n)== EOF)
	{	
		return EOF;
	}
	
	if(is_valid_double(digits))
	{
		if(digits[0] == '-')
		{
			(*num) = -convert_to_double(digits);
		}
		else 
		{
			(*num) = convert_to_double(digits);
		}
		return 1;
	}
	
	return 0;
	
}

int is_valid_double(const char* digits) 
{
	int deci = 0;
	int valid = 1;
	
	if((*digits) == '-' ||(*digits) == '+'|| ((*digits) > 48 && (*digits) < 57))
	{
		digits++;
	}
	while(*digits != '\0')
	{
		if((*digits) < 48 ||(*digits) > 57)
		{
			if(*digits == '.')
			{
				deci++;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		digits++;
	}
	
	if(deci == 2)
	{
		valid = 0;
		return valid;
	}
	else
	{
		return valid;
	}
}
double convert_to_double(const char *digits) 
{	
	int decimal = 0;
	long double sum = 0;
	double n = 10;
	const double d = 48;
	
	if(*digits == '-' || *digits == '+')
	{
		digits++;
	}
	
	while(*digits != '\0')
	{
		if(*digits == '.')
		{
			digits++;
			decimal = 1;
		}
				
		else
		{			
			if(decimal == 0)
			{
				sum = sum*(10) + ((*digits) - d); 
			}
			else
			{
				sum = sum +((*digits) - d)/(n);
				n = n*10;
			}

			digits++;
		}
	}
	return sum;
}