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
int is_sorted(struct node_t* head);
struct node_t* join_lists(struct node_t* head1, struct node_t* head2);
struct node_t* create(int value);
struct node_t* push_normal(struct node_t* head, int value);
struct node_t* push_sorted(struct node_t* head, int value);
