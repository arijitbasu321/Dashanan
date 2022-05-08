#ifndef DASHANAN_SEARCH_H
#define DASHANAN_SEARCH_H

int linear_search(int arr[], int arr_size, int search_val);

int binary_search(int arr[], int search_val, int left_index, 
                  int right_index, char* method);

int binary_search_recursive(int arr[], int search_val, int left_index,
                            int right_index);
                            
int binary_search_iterative(int arr[], int search_val, int left_index, 
                            int right_index);

#endif