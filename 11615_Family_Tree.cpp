//11615 - Family Tree
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>

int get_max_node(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	return ((2 << (n - 1)) - 1);
}

int get_level(int val)
{
	if (val == 0)
		return 0;
	if (val == 1)
		return 1;

	for (int i = 0; i < 21; ++i) {
		int min = 2 << i;
		int max = (2 << (i + 1)) - 1;
		if (val >= min && val <= max)
			return (i + 2);
	}
	return 0;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	int n, a, b, max;
	int total_nodes;
	int skip_nodes;
	int current_level;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &n, &a, &b);
		total_nodes = get_max_node(n);
		max = a;
		if (b > a) {
			max = b;
		}
		current_level = get_level(max);
		skip_nodes = get_max_node(n - current_level + 1);
		//if (skip_nodes > 0)
			--skip_nodes;
		printf("%d\n", total_nodes - skip_nodes);
	}

	return 0;
}