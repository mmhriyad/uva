//10391 - Compound Words
#include <stdio.h>

#define MAXN 120001
#define INT(x) (x - 'a')

typedef struct
{
	int ID;
	char ch;
	bool end;
	int word_index;
	int parent_id;
	int childs[26];
}t_node;

t_node nodes[100000];
int NN, NW;

typedef struct
{
	int last_index;
	bool printed;
	char word[50];
}t_word;
t_word word_list[MAXN];

int init_node()
{
	int i;
	++NN;
	nodes[NN].ID = NN;
	nodes[NN].parent_id = -1;
	nodes[NN].end = false;
	for (i = 0; i < 26; ++i)
		nodes[NN].childs[i] = 0;
	return NN;
}

void init()
{
	NN = -1;
	NW = 0;
	init_node();
}

int insert_str(char *str)
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
		nodes[index].end = true;
	}
	return index;
}

int can_insert(char str[], int start)
{
	int i, index, child;
	i = 0;
	index = start;
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
	if (str[i] || !nodes[index].end)
		return -1;
	return nodes[index].word_index;
}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, start, index;
	init();
	while (gets(word_list[NW].word))
	{
		word_list[NW].last_index = insert_str(word_list[NW].word);
		word_list[NW].printed = false;
		nodes[word_list[NW].last_index].word_index = NW;
		++NW;
	}
	for (i = 0; i < NW; ++i)
	{
		start = word_list[i].last_index;
		for (j = 0; j < NW; ++j)
		{
			//if (j != i)
			{
				index = can_insert(word_list[j].word, start);
				if (index > 0)
				{
					word_list[index].printed = true;
				}
			}
		}
	}
	for (i = 0; i < NW; ++i)
		if (word_list[i].printed)
			puts(word_list[i].word);
	return 0;
}