// lab4exA.c

// ENSF 337 Fall 2020 Lab 4 Exercise A

#include <stdio.h>


int main(void)
{
    int i;
    int a[ ] = { 1000, 1200, 300, 1400, 1500, 30 };
    int *z;
	int j = 0;
    
    *a = 99;
    *(a + 2) = 55;
    a[1] = 11;
	
	printf("The point at which a is, is: %d\n", *a);
    
    z = a + 2;
    
    i = 2;
    
    *(z-1) = *(z-i) + z[0];
	printf("The next value is: %ld\n", a[1]);
	printf("the pointer of z is now pointing to: %d\n", *z);
    z[1] = *z * i;
	printf("The value of z[1] is: %d\n", z[1]);
	printf("the pointer of z is now pointing to: %d\n", *z);
    *(z+2) = *(&a[2] - i);
	printf("the pointer of z is now pointing to: %d\n", *z);
    z + 3;
	printf("the pointer of z is now pointing to: %d\n", *z);
    z[3] = -9;
	
    printf("the pointer of z is now pointing to: %d\n", *z);
    i = a - &a[6];
	
	printf("The value of a is: %d\n", a);
	printf("The value of &a[6] is: %ld\n", &a[6]);
	printf("the value of  a[5] is: %d\n", a[5]);
    // point one
    
    return 0;
}

