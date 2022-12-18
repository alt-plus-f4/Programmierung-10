// IMPLEMENTATION OF MERGE SORT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge.h"

void kombain(int array[], int left_index, int mid, int right_index){ // btw left index means what is LEFT (NOT NOT RIGHT!!) left numbers
    int bottom_left = mid - left_index + 1, bottom_right = right_index - mid; // bikini bottom counter is the index of the end of the left and right arrays.
    int counter_left = 0, counter_right = 0;

    int* left_array = (int*)malloc(sizeof(int) * bottom_right);
	int* right_array = (int*)malloc(sizeof(int) * bottom_right);
	left_array = copy_arr_index(array, left_index, bottom_left); // lEFT SIDE ARR4Y copy (left index is start point of leftest array)
	right_array = copy_arr_index(array, mid + 1, bottom_right); // RIGHT side array copy from index of mid + 1 (0-first)

    puts("\nLEFT ARRAY:\n");
    print_array(left_array, bottom_right); //
    puts("\nRIGHT ARRAY:\n");
    print_array(right_array, bottom_right); // Both these prints are for the arrays left and right after BEFORE being aranged

	while(counter_left < bottom_left && counter_right < bottom_right) // Arrange the two halves.
		left_array[counter_left] <= right_array[counter_right] ? (array[left_index++] = left_array[counter_left++]) : (array[left_index++] = right_array[counter_right++]);
    
    puts("\nARRANGED LEFT ARRAY:\n");
    print_array(left_array, bottom_right); //
    puts("\nARRANGED RIGHT ARRAY:\n");
    print_array(right_array, bottom_right); // Both these prints are for the arrays left and right AFTER being aranged

    while (counter_left < bottom_left) // Put the left half into the original array.
        array[left_index++] = left_array[counter_left++];

    while (counter_right < bottom_right) // Put the right half into the original array.
        array[left_index++] = right_array[counter_right++];

    puts("\nARRAY:\n");
    print_array(array, bottom_right); // array after being put into
}
void merge_sort(int array[], int left_index, int right_index){
    if (left_index < right_index) {
        int left_over = left_index + (right_index - left_index) / 2; // left over to split.

        merge_sort(array, left_index, left_over); // First recursion to split the left side.
        merge_sort(array, left_over + 1, right_index); // Split the right side.
 
        kombain(array, left_index, left_over, right_index); // Mix them toghether.
    }
}
int* copy_arr_index(int* array, unsigned int start, unsigned int counter){
	int* result = (int*)malloc(sizeof(int) * counter);
	for (int i = 0; i < counter; i++)
        result[i] = array[start + i];

	return result;
}
void print_array(int* array, unsigned int len){
	for (int i = 0; i < len; i++)
    	printf("[%d] %d\n", i, array[i]);
}


// End of code..