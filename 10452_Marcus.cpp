#include <stdio.h>

typedef enum
{
	LEFT = 1,
	RIGHT,
	UP
}t_dir;

#define MAX_MOVES 7

const char STR[] = "IEHOVA#";
const char strdir[4][6] = { "-", "left", "right", "forth" };
char arr[8][9];
int dir[MAX_MOVES];
int M, N;

void find(int x, int y, int pos)
{
	if (pos == MAX_MOVES)
	{
		int i;
		printf("%s", strdir[dir[0]]);
		for (i = 1; i < pos; ++i)
		{
			printf(" %s", strdir[dir[i]]);
		}
		printf("\n");
		return;
	}
	if (x - 1 >= 0 && arr[x - 1][y] == STR[pos])
	{
		dir[pos] = UP;
		find(x - 1, y, pos + 1);
	}
	else if (y - 1 >= 0 && arr[x][y - 1] == STR[pos])
	{
		dir[pos] = LEFT;
		find(x, y - 1, pos + 1);
	}
	else
	{
		dir[pos] = RIGHT;
		find(x, y + 1, pos + 1);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	int i, j, x, y;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &M, &N);
		gets(arr[0]);
		x = y = -1;
		for (i = 0; i < M; ++i)
		{
			gets(arr[i]);
			if (x < 0)
			{

				j = 0;
				while (arr[i][j])
				{
					if (arr[i][j] == '@')
					{
						x = i;
						y = j;
						break;
					}
					++j;
				}
			}
		}
		find(x, y, 0);
	}
	return 0;
}