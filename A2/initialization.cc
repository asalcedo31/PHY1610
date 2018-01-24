#include <cmath>
const double pi = 3.14159265358979323846264338327950288;
void initialize( int &table_size, int &time_steps, int &total_ants){   
    table_size = 70;
    time_steps = 100;
    total_ants = 10000;
    }

int **init_number_of_ants(int table_size){
    int **a = new int *[table_size];
    a[0] = new int[table_size*table_size];
    for (int i = 1; i < table_size; i++){
        a[i] = &a[0][i*table_size];
    }

    return a;
}

float **init_crawl_direction(int table_size){
    float **a = new float *[table_size];
    a[0] = new float [table_size*table_size];
    for (int i = 1; i < table_size; i++){
        a[i] = &a[0][i*table_size];
    }

    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            a[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    return a;
}