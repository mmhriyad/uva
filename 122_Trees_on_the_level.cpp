//122 - Trees on the level 
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 257

typedef struct node {
	int val;
	node *left;
	node *right;
}node;


typedef struct input {
	int val;
	char path[100];
	int level;
}input;

input inputs[MAX];

int n, max_level;

node* make_node(int val)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->val = val;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

node* insert_node(node *root, int index)
{
	if (inputs[index].level == 0)
		return make_node(inputs[index].val);

	if (root == NULL)
		return NULL;

	node *tmp = root;
	int i = 0;
	char ch;

	while (i < (inputs[index].level - 1) && tmp) {
		ch = inputs[index].path[i];
		if (ch == 'L')
			tmp = tmp->left;
		else
			tmp = tmp->right;
		++i;
	}

	if (tmp == NULL)
		return NULL;

	ch = inputs[index].path[i];
	if (ch == 'L') {
		if (tmp->left == NULL)
			tmp->left = make_node(inputs[index].val);
		else return NULL;
	}
	else {
		if (tmp->right == NULL)
			tmp->right = make_node(inputs[index].val);
		else return NULL;
	}

	return root;
}

node* make_tree(node *root)
{
	int i, current_level = 0;
	node *tmp = NULL;

	while (current_level <= max_level) {
		tmp = NULL;
		for (i = 0; i < n; ++i) {
			if (inputs[i].level == current_level) {
				tmp = insert_node(root, i);
				if (tmp == NULL) {
					return NULL;
				}
				if (root == NULL)
					root = tmp;
			}
		}
		if (tmp == NULL)
			return NULL;
		++current_level;
	}
	return root;
}

node *Q[MAX];
int q_front = 0, q_rear = 0;

void init_Q()
{
	q_front = q_rear = 0;
}

void enQ(node *n)
{
	Q[q_rear++] = n;
}

node* deQ()
{
	node *tmp = Q[q_front++];
	if (q_front == q_rear)
		init_Q();
	return tmp;
}

bool is_empty_Q()
{
	return (q_front == q_rear);
}

void print_all_level_node(node *root)
{
	init_Q();
	enQ(root);
	int n = 0;

	while (is_empty_Q() == false) {
		node *tmp = deQ();
		if (tmp->left)
			enQ(tmp->left);
		if (tmp->right)
			enQ(tmp->right);
		if (n == 0)
			printf("%d", tmp->val);
		else
			printf(" %d", tmp->val);
		++n;
	}
	printf("\n");
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char inp[5000], ch;
	int i, num, level;
	bool empty_node;

	node *root;

	while (gets(inp)) {
		n = 0;
		max_level = 0;
		root = NULL;
		empty_node = false;
		do {
			i = 0;
			while (inp[i]) {
				ch = inp[i];
				switch (ch)
				{
				case '(':
					num = 0;
					level = 0;
					empty_node = true;
					break;
				case ')':
					if (empty_node == false) {
						inputs[n].path[level] = 0x00;
						inputs[n].val = num;
						inputs[n].level = level;
						++n;
						if (max_level < level)
							max_level = level;
						//root = make_tree(root);
					}
					break;
				case ' ':
					break;
				default:
					if (ch >= '0' && ch <= '9') {
						num = num * 10 + (ch - '0');
						empty_node = false;
					}
					else if (ch == 'L' || ch == 'R')
						inputs[n].path[level++] = ch;
					break;
				}
				++i;
			} // end while

			if (empty_node) {
				root = make_tree(root);
				if (root == NULL)
					printf("not complete\n");
				else
					print_all_level_node(root);
				break;
			}
		} while (gets(inp));

	}

	return 0;
}