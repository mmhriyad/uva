//536 - Tree Recovery
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 30

typedef struct node {
	char val;
	node *left;
	node *right;
}node;

node* make_node(char val)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

int get_index(char *str, char ch, int min, int max)
{
	int i = min;
	while (i <= max) {
		if (ch == str[i])
			return i;
		++i;
	}

	return i;
}


node* make_tree(node *root, char *pre, char *in, int min, int max, int &start)
{
	if (min > max) {
		--start;
		return NULL;
	}
	char ch = pre[start];
	int ind = get_index(in, ch, min, max);
	root = make_node(pre[start]);
	++start;
	root->left = make_tree(root->left, pre, in, min, ind - 1, start);
	++start;
	root->right = make_tree(root->right, pre, in, ind + 1, max, start);

	return root;
}

void print_post_order(node *root)
{
	if (root == NULL)
		return;
	print_post_order(root->left);
	print_post_order(root->right);
	printf("%c", root->val);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char pre[MAX], in[MAX];
	int len;
	node *root;
	int start;

	while (scanf("%s %s", pre, in) == 2) {
		len = 0;
		while (pre[len])
			++len;
		start = 0;
		root = NULL;
		root = make_tree(root, pre, in, 0, len - 1, start);
		print_post_order(root);
		printf("\n");
	}
	return 0;
}