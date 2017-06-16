//112 - Tree Summing
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 100 //runtime 0.00, size->1000 : runtime : 0.020

typedef struct node {
	int val;
	int sum;
	node *left;
	node *right;
	node *parent;
	bool left_processed;
}node;

node* make_node(int val)
{
	node *n = (node *)malloc(sizeof(node));
	n->val = val;
	n->sum = val;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	n->left_processed = false;
	return n;
}

void skip_whitespace(char *str, int &pos)
{
	while (str[pos] == ' ')
		++pos;
}

int get_num(char *str, int &pos)
{
	int i = pos;
	int sum = 0;
	bool neg = false;
	if (str[i] == '-') {
		neg = true;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		sum = sum * 10 + (str[i] - '0');
		++i;
	}
	pos = i;
	if (neg)
		sum = -sum;
	return sum;
}

node* stack[MAX];
int top = 0;

void init_stack()
{
	top = 0;
}

void push(node *val)
{
	stack[top++] = val;
}

node* pop()
{
	node* tmp = stack[--top];
	return tmp;
}

bool is_emplty()
{
	return (top == 0);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int num, i, sum = 0, target;
	char inp[MAX];
	bool possible = false;
	int brace_count;
	int level, found_level;
	node *root = NULL, *tmp = NULL, *prev = NULL;
	int back_brace = 0;
	bool is_number = false;
	while (scanf("%d", &target) == 1) {
		possible = false;
		root = NULL;
		sum = 0;
		level = 0;
		found_level = -1;
		brace_count = 0;
		init_stack();
		gets(inp);
		i = 0;
		prev = NULL;
		root = NULL;
		do {
			skip_whitespace(inp, i);
			if (inp[i] == '(') {
				++brace_count;
				++i;
			}
			
			skip_whitespace(inp, i);
			if (!inp[i]) {
				gets(inp);
				i = 0;
				skip_whitespace(inp, i);
			}
			is_number = (inp[i] == '-' || (inp[i] >= '0' && inp[i] <= '9'));
			num = get_num(inp, i);
			tmp = NULL;
			if (is_number) {
				tmp = make_node(num);
				if (root == NULL)
					root = tmp;
				if (prev) {
					if (prev->left_processed) {
						prev->right = tmp;
						tmp->parent = prev;
					}
					else {
						prev->left = tmp;
						prev->left_processed = true;
						tmp->parent = prev;
					}
				}
				sum += num;
				tmp->sum = sum;
				push(tmp);
			}
			else if (prev)
				prev->left_processed = true;
			back_brace = 0;
			while (1) {
				skip_whitespace(inp, i);
				if (inp[i] == ')') {
					++back_brace;
					if (back_brace > 1) {
						tmp = pop();
						prev = tmp->parent;
						sum -= tmp->val;
						--level;
						if (tmp->sum == target) {
							if (tmp->left == NULL && tmp->right == NULL)
								possible = true;
						}
						free(tmp);
						tmp = NULL;
					}
					tmp = NULL;
					++i;
					--brace_count;
				}
				else if (!inp[i] && brace_count > 0) {
					gets(inp);
					i = 0;
				}
				else
					break;
			}
			skip_whitespace(inp, i);
			if (!inp[i] && brace_count > 0) {
				gets(inp);
				i = 0;
			}
			if (tmp)
				prev = tmp;
		} while (brace_count > 0);

		if (possible)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}