#include <stdio.h>
#include <stdlib.h>

struct node_t{
	int value;
	struct node_t* prev;
	struct node_t* next;
	struct node_t* prev_sort;
	struct node_t* next_sort;
};

struct node_t* add(struct node_t* head, int value);
void print_regular(struct node_t* head);
void print_sorted(struct node_t* head);
int is_sorted(struct node_t* head); // 1 if sorted 0 if not
struct node_t* join_lists(struct node_t* head1, struct node_t* head2);
struct node_t* create(int value);
struct node_t* push_normal(struct node_t* head, int value);
struct node_t* push_sorted(struct node_t* head, int value);


int main(){
	struct node_t* head = create(5);

	head = add(head, -10);
	head = add(head, -12);
	head = add(head, -3);


	printf("\nREGULAR:\n");
	print_regular(head);

	printf("\nSORTED:\n");
	print_sorted(head);

	printf("\niSorted: %d\n", is_sorted(head));

	return 0;
}

void swap_nodes(struct node_t* left,struct node_t* right) {
  if(left == NULL || right == NULL) return;

  if(left->prev != NULL) left->prev->next = right;

  left->next = right->next;
  right->next = left;

  if(left->next != NULL) left->next->prev = left;

  right->prev = left->prev;
  left->prev = right;
}
struct node_t* create(int value) {
	struct node_t* new_node = malloc(sizeof(struct node_t));

	new_node->prev = new_node->next = new_node->prev_sort = new_node->next_sort = NULL;
	new_node->value = value;

	return new_node;
}
struct node_t* add(struct node_t* head, int value){

	head = push_normal(head, value);
	head = push_sorted(head, value);

	return head;
}
struct node_t* push_normal(struct node_t* head, int value){
	if(head == NULL) return create(value);

	if(head->next == NULL) {
		struct node_t* new_node = create(value);
		head->next = new_node;
		new_node->prev = head;
	}

	else 
		add(head->next, value);

	return head;
}
struct node_t* push_sorted(struct node_t* head, int value){
	if(head == NULL) return create(value);

	if(head->value > value){
		struct node_t* temp = head;

		while(temp->prev_sort != NULL && temp->prev_sort->value < temp->value)
			temp = temp->prev_sort;

		temp->prev_sort = create(value);
		temp->prev_sort->next_sort = temp;	

		// else{
		// 	struct node_t* insert_node = create(value);
				
		// 	insert_node->prev = next_node->prev;
		// 	insert_node->next = next_node;
		// 	next_node->prev = insert_node;

		// 	if(insert_node->prev!=NULL) 
		// 		insert_node->prev->next = insert_node;
		// 	else
		// 		*head = insert_node;
		// }
	}

	else{
		if(head->next_sort != NULL){

		}
		else{
			head->next_sort = create(value);
			head->next_sort->prev_sort = head;
		}
	}

	return head;
}
struct node_t* join_lists(struct node_t* head1, struct node_t* head2){

}
int is_sorted(struct node_t* head){
	while(head->prev_sort != NULL) head = head->prev_sort;

	while(head->next_sort != NULL) {
		if(head->value > head->next_sort->value)
			return 0;
		head = head->next_sort;
	}
	return 1;

}
void print_regular(struct node_t* head) {
	while(head != NULL) {
		printf("%p <- %p[%d] -> %p\n", head->prev, head, head->value, head->next);
		head = head->next;
	}
}
void print_sorted(struct node_t* head) {

	while(head->prev_sort != NULL) head = head->prev_sort;

	while(head != NULL) {
		printf("%p <- %p[%d] -> %p\n", head->prev_sort, head, head->value, head->next_sort);
		head = head->next_sort;
	}
}

	// struct node_t* newNode = create(value);

	// newNode->next_sort = head->prev_sort->next_sort;
	// head->prev_sort->next = newNode;
	// newNode->prev_sort = head->prev_sort;

	// if (newNode->next_sort != NULL)
	// 	newNode->next->prev_sort = newNode;