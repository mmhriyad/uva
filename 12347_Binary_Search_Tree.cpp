// 12347 - Binary Search Tree
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int val;
	node* left;
	node* right;
}node;

node* make_node(int val)
{
	node* tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

node* insert_node(node* root, int val)
{
	if (root == NULL)
		return make_node(val);
	if (val < root->val)
		root->left = insert_node(root->left, val);
	else
		root->right = insert_node(root->right, val);

	return root;
}

void print_post_order(node* root)
{
	if (root == NULL)
		return;
	print_post_order(root->left);
	print_post_order(root->right);
	printf("%d\n", root->val);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	node* root = NULL;
	int val = 10000000;
	while (scanf("%d", &val) == 1) {
		root = insert_node(root, val);
	}
	print_post_order(root);
	return 0;
}