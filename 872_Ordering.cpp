/*
872_Ordering.cpp
Auther: Md. Mahbubul Huq
*/

#include <stdio.h>

#define MAXN 26

char arr[MAXN], nodes[MAXN];
int parent[MAXN][MAXN + 1];
char inp[4 * 50]; // 50 constraings, each need space of 4 'A<B '
bool taken[MAXN], exist[MAXN], is_possible = false;

int N;

void print()
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%c", arr[i]);
	}
	printf("\n");
	is_possible = true;
}

bool parents_taken(int a)
{
	int b = parent[a][0];
	int i;
	for (i = 1; i <= b; i++)
	{
		if (!taken[parent[a][i]])
			return false;
	}
	return true;
}

void permu(int n)
{
	int i;
	if (n == N)
	{
		print();
		return;
	}
	for (i = 0; i < N; i++)
	{
		if (!taken[i] && (parent[i][0] == 0 || (parent[i][0] > 0 && parents_taken(i))))
		{
			taken[i] = true;
			arr[n] = nodes[i];
			permu(n + 1);
			taken[i] = false;
		}
	}
}

int getid(char ch)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (nodes[i] == ch)
			return i;
	}
	return -1;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, ind;
	char a, b;
	int T;
	scanf("%d", &T);
	gets(inp); //blank
	N = 0;
	while (T--)
	{
		for (i = 0; i < MAXN; i++)
		{
			parent[i][0] = 0;
			exist[i] = false;
		}
		gets(inp); //blank line
		gets(inp); //nodes
		i = 0;
		while (inp[i])
		{
			exist[inp[i] - 'A'] = true;
			++i;
			if (!inp[i])
				break;
			++i;
		}
		N = 0;
		for (i = 0; i < MAXN; i++)
		{
			if (exist[i])
				nodes[N++] = i + 'A';
		}
		gets(inp); // constrains
		i = 0;
		while (inp[i])
		{
			a = inp[i];
			i += 2;
			b = inp[i];
			ind = getid(b);
			parent[ind][++parent[ind][0]] = getid(a);
			++i;
			if (!inp[i])
				break;
			++i;
		}
		is_possible = false;
		permu(0);
		if (!is_possible)
			printf("NO\n");
		if (T)
			printf("\n");
	}
	return 0;
}