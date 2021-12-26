// ENSF 337 - fall 2020 - lab 5 - exercise D
// Matthew Ho(30052684) Alexander Sembrat (30089188)
// M. Moussavi
// lab5exe_D.c
// Date Submitted 10/19/2020

#include <stdio.h>
#include <stdlib.h>
#include "lab5exe_D.h"

int main(void) {
    char input_filename[30] = "lab5exe_D.txt";
    char output_filename[30]= "lab5exe_D_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;
    
    read_text_file(&intVec, input_filename);
    
    display_single_column(&intVec);
    
    display_multiple_column(&intVec, 4, output_filename);
    
    return 0;
}

void read_text_file (IntVector* vec, const char* input_filename){
    int nscan;
    FILE *fp = fopen (input_filename, "r");
    
    if(fp == NULL){
        fprintf(stdout, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }
    
    do{
        nscan = fscanf(fp,"%d", &vec->storage[vec->number_of_data]); //this looks first at which file you want, then it looks at what type it is looking for, and then the location of the object is determined
        if(nscan == 1)// this checks if the value that was checked matches the one that is determined
            (vec->number_of_data)++; 
        else if (nscan != EOF){
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    }while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));
    
    fclose(fp);
}

void display_single_column(const IntVector* intV){
    int i;
    for (i = 0; i < intV ->number_of_data; i++ )
        printf("%10d\n", intV ->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char* output_filename)
{		
	FILE* Output = fopen(output_filename, "w");
	int i = 0;
	
	while(i < (*intV).number_of_data)
	{
		for(int j = 0; j < col && i < (*intV).number_of_data; j++, i++)
		{		
			fprintf(Output,"%10d  ", intV -> storage[i]);
		}
		
		fprintf(Output, "\n");
		
	}
}
