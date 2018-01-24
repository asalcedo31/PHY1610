#ifndef TIME_STEP_H
#define TIME_STEP_H
int count_ants(int table_size, int **number_of_ants );
void move_ants(int table_size, float **crawl_direction, int **new_number_of_ants, int **number_of_ants);
void update_ant_arrays(int table_size, int **new_number_of_ants, int **number_of_ants);
#endif