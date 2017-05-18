#include <stdio.h>

int arr[8][8];
int x1, x2, y1, y2;
int count;
int dir[8][2] = { { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 } };

void init()
{
	int i, j;
	count = -1;
	for (i = 0; i < 8; ++i)
		for (j = 0; j < 8; ++j)
			arr[i][j] = -1;
	arr[x1][y1] = 0;
}

void get_count(int val)
{
	int i, j, k, a, b;
	bool increase;
	increase = false;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 8; ++j)
		{
			if (arr[i][j] == val)
			{
				for (k = 0; k < 8; ++k)
				{
					a = i + dir[k][0];
					b = j + dir[k][1];
					if (a >= 0 && a < 8 && b >= 0 && b < 8 && arr[a][b] < 0)
					{
						increase = true;
						arr[a][b] = val + 1;
						if (a == x2 && b == y2)
						{
							count = val + 1;
							return;
						}
					}
				}
			}
		}
	}

	if (increase)
		get_count(val + 1);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, j;
	char cx1, cx2;
	while (scanf("%c%d %c%d", &cx1, &y1, &cx2, &y2) == 4)
	{
		x1 = cx1 - 'a';
		x2 = cx2 - 'a';
		--y1;
		--y2;
		init();
		count = 0;
		if (x1 != x2 || y1 != y2)
			get_count(0);
		printf("To get from %c%d to %c%d takes %d knight moves.\n", cx1, y1 + 1, cx2, y2 + 1, count);
		getchar();
	}
}