#include <stdio.h>

#define MAXN 1000000

#define INT(x) (x - 'a')

typedef struct
{
	int id;
	int count;
	char ch;
	int parent_id;
	int nchild;
	int childs[26];
}t_node;

t_node nodes[MAXN];

int NNODES, max_count, max_index;

int init_node()
{
	int i;
	int index = ++NNODES;
	nodes[index].id = index;
	nodes[index].nchild = 0;
	nodes[index].parent_id = -1;
	nodes[index].count = 0;
	for (i = 0; i < 26; ++i)
		nodes[index].childs[i] = 0;
	return index;
}

void init()
{
	NNODES = -1;
	max_count = 0;
	max_index = 1;
	init_node();
}

void insert_str(char *str)
{
	int i, index, child;
	i = index = 0;
	while (str[i])
	{
		if (!nodes[index].childs[INT(str[i])])
			break;
		else
		{
			index = nodes[index].childs[INT(str[i])];
		}
		++i;
	}
	if (str[i])
	{
		while (str[i])
		{
			child = init_node();
			nodes[index].childs[INT(str[i])] = child;
			nodes[child].parent_id = index;
			nodes[child].ch = str[i];
			index = child;
			++i;
		}
		nodes[index].count = 1;
		if (!max_count)
		{
			max_count = 1;
			max_index = index;
		}
	}
	else
	{
		nodes[index].count++;
		if (max_count < nodes[index].count)
		{
			max_count = nodes[index].count;
			max_index = index;
		}
	}
}

void print_str(int index)
{
	if (nodes[index].parent_id < 0)
		return;
	print_str(nodes[index].parent_id);
	printf("%c", nodes[index].ch);
}


char inp[MAXN], substr[MAXN][12];


int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int size, i, j, k;
	
	while (scanf("%d %s", &size, &inp) == 2)
	{
		init();

		for (i = 0; inp[i]; ++i)
		{
			for (j = i, k = 0; inp[j] && k < size; ++j, ++k)
			{
				substr[i][k] = inp[j];
			}
			substr[i][k] = 0x00;
			if (!(k - size))
				insert_str(substr[i]);
			else
				break;
		}
		print_str(max_index);
		printf("\n");
	}
}