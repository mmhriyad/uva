/*
124_Following_Orders.cpp
Auther: Md. Mahbubul Huq
*/

#include <stdio.h>

#define MAXN 26

char arr[MAXN], nodes[MAXN];
int parent[MAXN][MAXN + 1];
char inp[4 * 50];
bool taken[MAXN], exist[MAXN];

int N;

void print()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%c", arr[i]);
	printf("\n");
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
//	freopen("inp.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int i, cn = 0, ind;
	char a, b;
	N = 0;
	while (gets(inp))
	{
		for (i = 0; i < MAXN; i++)
		{
			parent[i][0] = 0;
			exist[i] = false;
		}
		i = 0;
		while (inp[i])
		{
			//if (inp[i] >= 'a' && inp[i] <= 'z')
			exist[inp[i] - 'a'] = true;
			++i;
			if (!inp[i])
				break;
			++i;
		}
		N = 0;
		for (i = 0; i < MAXN; i++)
		{
			if (exist[i])
				nodes[N++] = i + 'a';
		}
		gets(inp);
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
		if (cn > 0)
			printf("\n");
		permu(0);
		cn++;
	}
	return 0;
}