// Name: Matthew Ho 30052684
// Lab Section: B01
// Date submitted: 12/2/2020
// Course: ENSF 337
// Exercise E

#include "matrix.h"

Matrix::Matrix(int r, int c):rowsM(r), colsM(c)
{
    matrixM = new double* [rowsM];
    assert(matrixM != NULL);
    
    for(int i=0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
}


Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
    if(&rhs != this){
        destroy();
        copy(rhs);
    }
   
    return *this;
}

double Matrix::get_sum_col(int i) const
{
    assert(i >= 0 && i < colsM);
    return sum_colsM[i];
}

double Matrix::get_sum_row(int i) const
{
    assert(i >= 0 && i < rowsM);
    return sum_rowsM[i];
}


void Matrix::sum_of_rows()const //this works
{
   
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
	int i;
	int j;
	long double sum = 0;
	for( i = 0; i < rowsM; i++)
	{
		for( j = 0; j < colsM; j++)
		{
			sum = sum + matrixM[i][j];
		}
		sum_rowsM[i] = sum;
		sum = 0;
	}
    //cout << "\nSorry I don't know how to calculate sum of rowsM in a matrix. ";

}

void Matrix::sum_of_cols()const 
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
	int i; 
	int j;
	double sum = 0;
	for( i = 0; i < colsM; i++)
	{

		for( j = 0; j < rowsM; j++)
		{
			sum = sum + matrixM[j][i];
		}
		sum_colsM[i] = sum;
		sum = 0;
	}
    //cout << "\nSorry I don't know how to calculate sum of columns in a matrix. ";
    
}

void Matrix::copy(const Matrix& source)
{
    // THIS FUNCITON IS DEFECTIVE AND DOSEN'T PROPERLY MAKE THE COPY OF SROUCE
    if(source.matrixM == NULL){
        matrixM = NULL;
        sum_rowsM = NULL;
        sum_colsM = NULL;
        rowsM = 0;
        colsM = 0;
        return;
    }
    
    rowsM = source.rowsM; 
    colsM = source.colsM; 
    
    sum_rowsM = new double[rowsM];
    assert(sum_rowsM != NULL);
    
    
    sum_colsM = new double[colsM];
    assert(sum_colsM != NULL);
    
    matrixM = new double*[rowsM];
    assert(matrixM !=NULL);
    for(int i =0; i < rowsM; i++){
        matrixM[i] = new double[colsM];
        assert(matrixM[i] != NULL);
    }
	
	for( int i = 0; i < rowsM; i++)
	{
		for( int j = 0; j < colsM; j++)
		{
			matrixM[i][j] = source.matrixM[i][j];
			sum_colsM[j] = source.sum_colsM[j];
		}
		sum_rowsM[i] = source.sum_rowsM[i];
	}
	return;
	
    // STUDENTS MUST COMMENT OUT THE FOLLOWING LINE AND FIX THE FUNCTION'S PROBLEM
    //cout << "\nSorry copy fucntion is defective. ";
}

    

void Matrix::destroy() 
{
    // COMMENT OUT THE FOLLOWING LINE AND COMPLETE THE DEFINITION OF THIS FUNCTION
	int i;
	int j;
	
	double *deletion;
	double ** big_delete;
	
	for(i = 0 ; i < rowsM; i++) 
	{
		deletion = (*matrixM);
		*matrixM = NULL;
		matrixM++;
		delete [] deletion;
	}
	
	big_delete = matrixM;
	matrixM = NULL;
	delete big_delete;
	
	deletion = sum_colsM;
	sum_colsM = NULL;
	delete deletion;
	
	deletion = sum_rowsM;
	sum_rowsM = NULL;
	delete deletion;
	
	rowsM = 0;
	colsM = 0;
	
	cout << "\n This pointer of pointers has been successfully deleted! \n";
}
	
   // cout << "\nProgram ended without destroying matrices.\n";

