#include <iostream>
#include "../include/dsnutilities.h"

using namespace std;

int * load_array(char file_path[]) {

    int * input_array = new int[100];

    FILE* ptr;
    ptr = fopen(file_path, "r");

    if (NULL == ptr) {
        puts("File cannot be read!");
        exit(1);
    }

    // int i = 0;
    // char* element;
    // while (NULL != fgets(element, 30, ptr)) {
    //     input_array[i] = element;
    // }    

    fclose(ptr);

    return input_array;    
}

void print_array(int arr[], int arr_size) {
    int i;
    for(i=0; i<arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}