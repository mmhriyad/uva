//11234 - Expressions
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

typedef struct node {
	char val;
	node* left;
	node* right;
}node;

node* make_node(char val)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

#define MAX 10001

node* Q[MAX];
int q_front = 0;
int q_rear = 0;

void init_Q()
{
	q_front = q_rear = 0;
}

bool is_empty_Q()
{
	return (q_front == q_rear);
}

void enQ(node* n)
{
	Q[q_rear++] = n;
	if (q_rear >= MAX)
		q_rear = 0;
}

node* deQ()
{
	node* tmp = Q[q_front++];
	if (q_front == q_rear)
		init_Q();
	else if (q_front >= MAX)
		q_front = 0;

	return tmp;
}

char arr[MAX];

void print_q(node* root, int size)
{
	if (root == NULL)
		return;
	init_Q();
	enQ(root);
	arr[size--] = 0x00;
	while (is_empty_Q() == false) {
		node* tmp = deQ();
		arr[size--] = tmp->val;
		if (tmp->left)
			enQ(tmp->left);
		if (tmp->right)
			enQ(tmp->right);
	}
	puts(arr);
}

node* stack[MAX];

int size;

void init_stack()
{
	size = 0;
}

void push(node* n)
{
	stack[size++] = n;
}

node* pop()
{
	return stack[--size];
}

char post[MAX];

node* make_tree()
{
	int i = 0;
	node* left = NULL;
	node* right = NULL;
	node* root = NULL;
	while (post[i]) {
		char c = post[i];
		if (c >= 'A' && c <= 'Z') {
			root = make_node(c);
			right = pop();
			left = pop();
			root->left = left;
			root->right = right;
			push(root);
		}
		else {
			push(make_node(c));
		}
		++i;
	}

	return pop();
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N;
	int l;
	node* root = NULL;

	scanf("%d", &N);
	gets(post);
	while (N--) {
		gets(post);
		l = 0;
		while (post[l])
			l++;
		root = make_tree();
		print_q(root, l);
	}

	return 0;
}