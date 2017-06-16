//10701 - Pre, in and post
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 53

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

void print_post_order(node* root)
{
	if (root == NULL)
		return;
	print_post_order(root->left);
	print_post_order(root->right);
	printf("%c", root->val);
}

node* make_tree(char pre[], char in[], int min, int max, int& start)
{
	if (min > max) {
		--start;
		return NULL;
	}
	node* tmp = make_node(pre[start]);
	int index = 0;
	while (in[index] != pre[start])
		++index;
	++start;
	tmp->left = make_tree(pre, in, min, index - 1, start);
	++start;
	tmp->right = make_tree(pre, in, index + 1, max, start);

	return tmp;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char pre[MAX], in[MAX];
	int N;
	int size;
	int start;

	node* root = NULL;
	scanf("%d", &N);

	while (N--) {
		scanf("%d %s %s", &size, pre, in);
		start = 0;
		root = make_tree(pre, in, 0, size-1, start);
		print_post_order(root);
		printf("\n");
	}
}