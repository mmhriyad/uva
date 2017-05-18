#include "stdio.h"
#include <stdlib.h>

#define MAX 1001

bool was_build[MAX];

struct node
{
	node *prev;
	node *next;
	int x;
	int y;
};

node *list[MAX], *head, *tail;

int count=0;

void insert_after(node *node_pos, int x, int y, int n)
{
	node *item = (node *)malloc(sizeof(node));
	item->x = x;
	item->y = y;

	item->next = node_pos->next;
	item->prev = node_pos;
	node_pos->next = item;
	count++;
}

void build_list(int n)
{
	node *cur_pos = head;
	while(cur_pos->next)
	{
		node *next_pos = cur_pos->next;
		if(cur_pos->x+next_pos->x <=n && cur_pos->y+next_pos->y <= n)
			insert_after(cur_pos, cur_pos->x+next_pos->x, cur_pos->y+next_pos->y, n);
		cur_pos = next_pos;
	}
}

void print_list()
{
	node *cur_pos = head;
	while(cur_pos->next)
	{
		printf("%d/%d, ",cur_pos->x, cur_pos->y);
		cur_pos = cur_pos->next;
	}
	printf("%d/%d\n",cur_pos->x, cur_pos->y);
}

void print_list(int pos)
{
	node *cur_pos = head->next;
	int i = 1;
	while(cur_pos)
	{
		if(i == pos)
		{
			printf("%d/%d\n",cur_pos->x, cur_pos->y);
			break;
		}
		i++;
		cur_pos = cur_pos->next;
	}
}

int main()
{	
	int n=3, k;
	int i;
	//memset(
	while(scanf("%d %d", &n, &k) == 2)
	{
		count = 0;
		if(!was_build[n])
		{
			list[n] = (node *)malloc(sizeof(node));
			list[n]->x = 0;
			list[n]->y = 1;
			list[n]->prev=NULL;
			list[n]->next=NULL;
			head = list[n];
			//count++;
			insert_after(head, 1, 1, n);
			for(i=2; i<=n; i++)
			{
				build_list(i);
				//print_list();
			}
			was_build[n] = true;
			//printf("total nodes : %d======", count);
		}
		else
			head = list[n];
		print_list(k);
		//free(list);
	}
	
	return 0;
}