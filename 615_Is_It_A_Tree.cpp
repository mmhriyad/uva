//615 - Is It A Tree
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 10000

typedef struct node{
	int val;
	node *parent;
	node *childs[MAX];
	int child_count;
	bool visited;
} node;

node* nodes[MAX];
int N, total_visited;
bool is_tree = true;

void init()
{
	N = 0;
	total_visited = 0;
	is_tree = true;
}

node* make_node(int val)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->val = val;
	tmp->visited = false;
	tmp->parent = NULL;
	tmp->child_count = 0;
	return tmp;
}

node* find_node(int val)
{
	int i;
	for (i = 0; i < N; ++i) {
		if (nodes[i]->val == val)
			return nodes[i];
	}
	nodes[N++] = make_node(val);
	return nodes[N - 1];
}

void add_nodes(int val1, int val2)
{
	node *node1 = find_node(val1);
	node *node2 = find_node(val2);
	if (node2->parent) {
		is_tree = false;
		return;
	}
	node1->childs[node1->child_count++] = node2;
	node2->parent = node1;
}

node* find_root()
{
	int i;
	node *root = NULL;
	int root_found = 0;
	for (i = 0; i < N; ++i) {
		if (nodes[i]->parent == NULL) {
			++root_found;
			if (root_found > 1) {
				is_tree = false;
				return NULL;
			}
			root = nodes[i];
		}
	}

	if (root == NULL)
		is_tree = false;
	return root;
}

void visit(node *root)
{
	int i;
	int len = root->child_count;
	if (root->visited) {
		is_tree = false;
		return;
	}
	++total_visited;
	root->visited = true;
	for (i = 0; i < len && is_tree; ++i) {
		visit(root->childs[i]);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a = 1234567890, b;
	int case_no = 0;
	node *root = NULL;
	while (scanf("%d %d", &a, &b) == 2)
	{
		if (a < 0 && b < 0)
			break;
		init();
		do {
			if (a == 0 && b == 0)
				break;
			if (is_tree)
				add_nodes(a, b);
		} while (scanf("%d %d", &a, &b));

		if (is_tree && N > 0)
			root = find_root();

		printf("Case %d is ", ++case_no);
		if (is_tree && N > 0) {
			visit(root);
			if (is_tree)
				is_tree = (total_visited == N);
		}
			
		if (is_tree) {
			printf("a tree.\n");
		}
		else {
			printf("not a tree.\n");
		}

	}
	return 0;
}