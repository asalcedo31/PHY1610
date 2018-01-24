#include <cmath>
void zero_array(int table_size, int **number_of_ants){
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
}
void place_ants_t0(int table_size, int **number_of_ants, int total_ants){
    int n =0;
    while (n < total_ants) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_ants[i][j] ++;
        n ++;
    }
}
