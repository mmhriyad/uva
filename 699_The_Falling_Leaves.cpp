//699 - The Falling Leaves
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int val;
	node* left;
	node* right;
	node* parent;
	int index;
	bool left_processed;
} node;

node* make_node(int val)
{
	node *tmp = (node*)malloc(sizeof(node));

	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->left_processed = false;
	tmp->index = 0;
	
	return tmp;
}

node* stack[100];
int stack_size = 0;

void init_stack()
{
	stack_size = 0;
}

void push(node* n)
{
	stack[stack_size++] = n;
}

node* pop()
{
	return stack[--stack_size];
}

bool is_empty_stack()
{
	return (stack_size == 0);
}

int arr[100];
int min, max;

void traverse(node* root)
{
	if (root == NULL)
		return;
	traverse(root->left);
	arr[root->index - min] += root->val;
	traverse(root->right);
}

void init_arr()
{
	int i = 0;
	int len = max - min;

	for (i = 0; i <= len; ++i)
		arr[i] = 0;
}

void print_arr()
{
	int i = 0;
	int len = max - min;

	printf("%d", arr[i]);
	for (i = 1; i <= len; ++i)
		printf(" %d", arr[i]);
	printf("\n");
	printf("\n");
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int a;
	node* root = NULL;
	node* current = NULL;
	node* tmp = NULL;
	int case_no = 0;

	bool left_processed = false;
	while (scanf("%d", &a) == 1) {
		if (a == -1)
			break;
		root = NULL;
		current = NULL;
		init_stack();
		min = 0;
		max = 0;
		do {
			if (root == NULL) {
				root = make_node(a);
				current = root;
				current->parent = NULL;
				push(current);
			}
			else {
				tmp = NULL;
				if (a == -1) {
					while (1) {
						tmp = NULL;
						if (current->left_processed) {
							tmp = pop();
						}
						current->left_processed = true;
						if (tmp)
							current = tmp->parent;
						else
							break;
						if (current == NULL || current->right == NULL)
							break;
					}
				}
				else {
					tmp = make_node(a);
					if (current->left_processed) {
						current->right = tmp;
						tmp->index = current->index + 1;
						if (max < tmp->index)
							max = tmp->index;
					}
					else {
						current->left = tmp;
						current->left_processed = true;
						tmp->index = current->index - 1;
						if (min > tmp->index)
							min = tmp->index;
					}
					tmp->parent = current;
					current = tmp;
					push(current);
				}
			}
			
			if (is_empty_stack())
				break;
		} while (scanf("%d", &a) == 1);
		// process tree;
		init_arr();
		traverse(root);
		printf("Case %d:\n", ++case_no);
		print_arr();
	}

	return 0;
}