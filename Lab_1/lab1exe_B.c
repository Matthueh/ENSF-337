/*
*  lab1exe_B.c
*  ENSF 337 - Fall 2020 Lab 1, exercise B
*  Lab Section B01
*  Completed by: Matthew Ho(30052684)
*  Submission Date: 9/17/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* G is a constant: gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654  /* PI is constant */

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);


int main(void)
{
    int n;
    double velocity;
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    
    return 0;
}


double Projectile_travel_time(double a, double v)
{
	double t;
	double rad;
	
	rad = degree_to_radian(a);
	t = 2*v*sin(rad)/G;
	
	return t;
}

double Projectile_travel_distance(double a, double v)
{
	double d;
	double rad;
	
	rad = degree_to_radian(a);
	d = pow(v, 2)*sin(2*rad)/G;
	
	return d;
	
}

double degree_to_radian(double deg)
{
	double rad;
	rad = deg*PI/180;
	
	return rad;
}


void create_table(double v)
{
	double angle;
	double time;
	double distance;
	
	
	printf("Angle                           t                         d\n");
	printf("(deg)                         (sec)                      (m) \n"); 
	
	while(angle < 95)
	{
		time = Projectile_travel_time(angle, v);
		distance = Projectile_travel_distance(angle, v);
		printf("%lf                    %lf                    %lf \n", angle, time, distance);
		angle = angle + 5;
	}
	
}



/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */






