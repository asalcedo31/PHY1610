#include<cmath>
int count_ants(int table_size, int **number_of_ants ){
    float total_ants = 0.0;
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            total_ants += number_of_ants[i][j];
        }
    }
    return total_ants;
}

void move_ants(int table_size, float **crawl_direction, int **new_number_of_ants, int **number_of_ants){
    for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                int di = 1.9*sin(crawl_direction[i][j]);
                int dj = 1.9*cos(crawl_direction[i][j]);
                int i2 = i + di;
                int j2 = j + dj;
                // put onlu new table if not off table
                if (i2>=0 and i2<table_size and j2>=0 and j2<table_size) {
                    new_number_of_ants[i2][j2] += number_of_ants[i][j];
                } 
            }
        }
}

void update_ant_arrays(int table_size, int **new_number_of_ants, int **number_of_ants){
    for (int i=0;i<table_size;i++) {
            for (int j=0;j<table_size;j++) {
                number_of_ants[i][j] = new_number_of_ants[i][j];
            }
        }  
}