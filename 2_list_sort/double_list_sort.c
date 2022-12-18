#include <stdio.h>
#include <stdlib.h>
#include "double_list_sort.h"

// Function to create new node
// Initialises all pointers and gives falue
// O(1)
struct node_t* create(int value) {
	struct node_t* new_node = malloc(sizeof(struct node_t));

	new_node->prev = new_node->next = new_node->prev_sort = new_node->next_sort = NULL;
	new_node->value = value;

	return new_node;
}
// Function to combine two inserting methods
// Inserts all elements normal and sorted
// 2*O(N)
struct node_t* add(struct node_t* head, int value){

	head = push_normal(head, value); // Normal push
	head = push_sorted(head, value); // Sorted push bruh

	return head;
}
// Trivial pushing
// Just puts a new element in the end of the list
// O(N)
struct node_t* push_normal(struct node_t* head, int value){
	if(head == NULL) return create(value);

	if(head->next == NULL) { // Trivialno nz
		struct node_t* new_node = create(value);
		head->next = new_node;
		new_node->prev = head;
	}
	else // To get to the end of the list
		add(head->next, value);

	return head;
}
// Function to push sorted elements
// Like binary tree push sorted
// O(log(N))
struct node_t* push_sorted(struct node_t* head, int value){
	if(head == NULL) return create(value);

	struct node_t* new_node = create(value);
	struct node_t* temp = head; // used to prevent losing head pointer

	if(head->value > value){ // If you have number lower than the head go left <---
		while(1){ // :0
			if(temp->value <= value){ // If the current element is larger insert after the number
				new_node->next_sort = temp->next_sort;
				temp->next_sort->prev_sort = new_node;
				new_node->prev_sort = temp;
				temp->next_sort = new_node;
				return head;
			}
			if(temp->prev_sort == NULL){ // If its the lowest then insert in the end
				new_node->next_sort = temp;
				temp->prev_sort = new_node;
				return head;
			}
			temp = temp->prev_sort;
		}
	}
	else{  // If you have number higher than the head go right --->
		while(1){ // Just iterating till it finds it's place
			if(temp->next_sort == NULL){ // If its the highest then insert ins the end
				new_node->prev_sort = temp;
				temp->next_sort = new_node;
				return head;
			}
			if(temp->value >= value){  // If the current element is lower or equal insert before the number
				new_node->next_sort= temp;
				temp->prev_sort->next_sort = new_node;
				new_node->prev_sort = temp->prev_sort;
				temp->prev_sort = new_node;
				return head;
			}
			temp = temp->next_sort;
		}
	}
	return head;
}
// Function to combine two lists
// Adds the elements of two lists toghether and returns them
// O(2N)
struct node_t* join_lists(struct node_t* head1, struct node_t* head2){
	struct node_t* result = NULL; // Result list
	for(;head1 != NULL || head2 != NULL;){ // If both of them are at the end they are empty
		if(head1 != NULL){ // If head1 exists then add its element to the result
			result = add(result, head1->value);
			head1 = head1->next; // Go next
		}
		if(head2 != NULL){ // Then add the second one ofc if it exists
			result = add(result, head2->value);
			head2 = head2->next; // Next element
		}
	}
	return result;
}
// Function to check if my program's working
// If sorted - 1 if ! - 0
// O(N)
int is_sorted(struct node_t* head){
	while(head->prev_sort != NULL) head = head->prev_sort; // Going to the start of the list

	while(head->next_sort != NULL) {
		if(head->value > head->next_sort->value)
			return 0;
		head = head->next_sort;
	}
	return 1;
}
// Function to print regular
// Prints by the way of adding
// O(N)
void print_regular(struct node_t* head) {
	while(head != NULL) { // Trivialno printirane nz 
		printf("%p <- %p[%d] -> %p\n", head->prev, head, head->value, head->next);
		head = head->next;
	}
}
// Function to print sorted 
// Prints sorted elements
// O(2log(N))
void print_sorted(struct node_t* head) {
	while(head->prev_sort != NULL) head = head->prev_sort; // Start of the list

	while(head != NULL) { // Trivialno printirane
		printf("%p <- %p[%d] -> %p\n", head->prev_sort, head, head->value, head->next_sort);
		head = head->next_sort;
	}
}

// End of code..