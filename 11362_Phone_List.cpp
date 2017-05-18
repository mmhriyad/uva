//11362 - Phone List
#include <stdio.h>

#define INT(x) (x - '0')

typedef struct
{
	int parent_id;
	int nchild;
	char ch;
	int childs[10];
}t_node;

t_node nodes[100000];
int NN;

bool possible = true;

int init_node()
{
	int i, k;
	i = ++NN;
	nodes[i].nchild = 0;
	nodes[i].parent_id = -1;
	for (k = 0; k < 10; ++k)
		nodes[i].childs[k] = 0;
	return i;
}

void init()
{
	NN = -1;
	init_node();
}

void insert(char str[])
{
	int i, j, p, index, child;
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
	if (index > 0 && nodes[index].nchild == 0)
	{
		possible = false;
		return;
	}
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				child = init_node();
				nodes[index].childs[INT(str[i])] = child;
				nodes[index].nchild++;
				nodes[child].parent_id = index;
				nodes[child].ch = str[i];
				index = child;
			}
			++i;
		}
	}
	else
		possible = false;
}

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int T, N, i;
	char inp[15];
	scanf("%d", &T);
	while (T--)
	{
		init();
		scanf("%d", &N);
		gets(inp);
		possible = true;
		for (i = 0; i < N; ++i)
		{
			gets(inp);
			if (possible)
				insert(inp);
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}