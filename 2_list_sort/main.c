#include <stdio.h>
#include "double_list_sort.h"

int main(){
	struct node_t* head = create(1);
	struct node_t* head2 = create(69);

	head = add(head, -1);
	head = add(head, 0);
	head = add(head, 2);
	head = add(head, 1);
	head2 = add(head2, -42);

	printf("\nREGULAR:\n");
	print_regular(head);

	printf("\nSORTED:\n");
	print_sorted(head);

	printf("\niSorted: %d\n", is_sorted(head));

	printf("\nREGULAR head2:\n");
	print_regular(head2);

	printf("\nSORTED head2:\n");
	print_sorted(head2);

	head = join_lists(head, head2);

	printf("\nREGULAR joined:\n");
	print_regular(head);

	printf("\nSORTED joined:\n");
	print_sorted(head);

	return 0;
}