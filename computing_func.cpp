#include <cmath>
#include<fstream>
int compute_denom(int i){
	int out = 1+i*i;
	return(out);
}
double f(double in_t){
	double numerator = sin(2*in_t);
	double denominator = compute_denom(in_t); // declaring the denominator a double to prevent rounding
	double output = numerator/denominator;
	return(output);
}
double g(double in_t){
	double numerator = cos(3*in_t);
	double denominator = compute_denom(in_t);
	double output = numerator/denominator;
	return(output);
}
void printToFile(double *in_store_t, double *in_store_x, double *in_store_y, int in_arraysize){
	std::ofstream fout("lissadjous.txt"); // opening file
	for (int i=0; i <= in_arraysize; i++){  // iterate through all indices in the array
		fout << in_store_t[i] << " " << in_store_x[i] << " " << in_store_y[i] << std::endl;
	}
	fout.close();
}