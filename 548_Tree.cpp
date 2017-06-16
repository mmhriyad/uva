//548 - Tree
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 10000

typedef struct node {
	int val;
	int sum;
	node *left;
	node *right;
}node;

node* make_node(int val)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->val = val;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

int get_index(int *arr, int val, int min, int max)
{
	int i = min;
	while (i <= max) {
		if (val == arr[i])
			return i;
		++i;
	}

	return i;
}

int min_sum = 1 << 30;
int min_node = 1 << 30;

void init()
{
	min_sum = 1 << 30;
	min_node = 1 << 30;
}

node* make_tree(node *root, int *post, int *in, int min, int max, int &start, int sum)
{
	if (min > max) {
		++start;
		return NULL;
	}
	int val = post[start];
	int ind = get_index(in, val, min, max);
	root = make_node(post[start]);
	sum += val;
	root->sum = sum;
	--start;
	root->right = make_tree(root->right, post, in, ind + 1, max, start, sum);
	--start;
	root->left = make_tree(root->left, post, in, min, ind - 1, start, sum);

	if (root->left == NULL && root->right == NULL) {
		if (root->sum <= min_sum) {
			if (root->sum == min_sum) {
				if (root->val < min_node)
					min_node = root->val;
			}
			else {
				min_sum = root->sum;
				min_node = root->val;
			}
		}
	}

	return root;
}

int make_arr(char *inp, int *out)
{
	int i = 0;
	int num = 0;
	char ch;
	int len = 0;
	while (inp[i]) {
		ch = inp[i];
		switch (ch)
		{
		case ' ':
			if (num > 0)
				out[len++] = num;
			num = 0;
			break;
		default:
			if (ch >= '0' && ch <= '9')
				num = num * 10 + (ch - '0');
			break;
		}
		++i;
	}
	out[len++] = num;
	return len;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int post[MAX], in[MAX];
	char inp[50000];
	int len;
	node *root;
	int start;

	while (gets(inp)) {
		init();
		len = make_arr(inp, in);
		gets(inp);
		len = make_arr(inp, post);
		start = len - 1;
		root = NULL;
		root = make_tree(root, post, in, 0, len - 1, start, 0);
		
		printf("%d\n", min_node);
	}
	return 0;
}