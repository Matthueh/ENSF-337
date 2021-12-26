// ENSF 337 Fall 2020 - Lab 7 exercise A
// M. Moussavi 
#include "cplx.h"

void global_print(const Cplx& n);


int main(void)
{
    Cplx num1;
    
    num1.setRealPart(666);
    
    Cplx num2(34, 5);

    num1.setImaginaryPart(500);
    
    return 0;
}

