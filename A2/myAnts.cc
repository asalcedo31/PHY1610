#include <cmath>
#include <iostream>

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
int main()
{
    // ants walk on a table
    int table_size = 0;
    int time_steps = 0;
    int total_ants = 0;
    int n = 0;
    initialize(table_size, time_steps,total_ants);
    int **number_of_ants = init_number_of_ants(table_size);
   // int number_of_ants[table_size][table_size];
    int **new_number_of_ants = init_number_of_ants(table_size);
    float **crawl_direction = init_crawl_direction(table_size);
    
    std::cout << table_size << " " << time_steps << " " << total_ants << std::endl;
    
    
    srand(13);
    
    // step 0 
    zero_array(table_size,number_of_ants);
    place_ants_t0(table_size,number_of_ants,total_ants);
    total_ants = count_ants(table_size, number_of_ants); 

    // report
    std::cout << 0 << " " << total_ants << std::endl;
    // run time steps
    for (int t = 0; t < time_steps; t++) {
        // ants move 
        zero_array(table_size,new_number_of_ants);
        move_ants(table_size, crawl_direction, new_number_of_ants, number_of_ants);
        update_ant_arrays(table_size, new_number_of_ants, number_of_ants);
        // update
        total_ants = count_ants(table_size,number_of_ants);
              
        // count ants
        // report
        std::cout << t+1 << " " << total_ants << std::endl;
    }
    return 0;
}             
