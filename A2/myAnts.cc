
#include <iostream>
#include "initialization.h"
#include "time_0.h"
#include "time_step.h"



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
