#include <iostream>
#include "../include/dsnsearch.h"

using namespace std;

int linear_search(int arr[], int arr_size, int search_val) {
    int i;
    for (i=0; i<arr_size; i++) {
        if(arr[i] == search_val) {
            return i;
        }
    }

    return -1;
}

int binary_search(int arr[], int search_val, int left_index, 
                  int right_index, char* method) {

    int value_index;
    if (method == "recursive") {
        value_index = binary_search_recursive(arr, search_val, 
                                             left_index, right_index);
    }

    if (method == "iterative") {
        value_index = binary_search_iterative(arr, search_val, 
                                             left_index, right_index);
    }
    
    return -1;
}

int binary_search_recursive(int arr[], int search_val, int left_index,
                            int right_index) {

    if (right_index >= left_index){
        int mid = (left_index + right_index) / 2;

        if (arr[mid] == search_val) {
            return mid;
        }

        if (arr[mid] > search_val) {
            return binary_search_recursive(arr, search_val, left_index, mid -1);
        }
        else {
            return binary_search_iterative(arr, search_val, mid + 1, right_index);
        }
    }

    return -1;
}

int binary_search_iterative(int arr[], int search_val, int left_index, 
                            int right_index) {

    while (left_index <= right_index) {
        int mid = (left_index + right_index) / 2;

        if (arr[mid] == search_val) {
            return mid;
        }

        if (arr[mid] > search_val) {
            left_index = mid + 1;
        }
        else {
            right_index = mid - 1;
        }
    }

    return -1;
}