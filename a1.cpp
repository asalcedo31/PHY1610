#include "computing_func.h"

int main()
{   int array_size = 10.0/0.0005; // calculate the size of the arrays
	// initialize arrays
	double *store_t = new double [array_size];
	double *store_x = new double [array_size];
	double *store_y = new double [array_size];
	// populate arrays
	int index = 0;
	for (double t=-5; t<=5; t+=0.0005){
		store_t[index] = t;
		store_x[index] = f(t);
		store_y[index] = g(t);
		index++;

	}
	// print arrays in a table to lissajous.txt
	printToFile(store_t,store_x,store_y,array_size);
	//clean memory allocated for arrays
	delete [] store_t;
	delete [] store_x;
	delete [] store_y;
	
	//return 1 to indicate successful completion
	return(1);
}