#include <stdio.h>

#define MAXN 10

char arr_main[MAXN][MAXN], arr_new[MAXN][MAXN];

int N;

bool is_rotate_90(char arr[MAXN][MAXN])
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (arr[i][j] != arr_new[j][N - i - 1])
				return false;
		}
	}
	return true;
}

bool is_rotate_180(char arr[MAXN][MAXN])
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (arr[i][j] != arr_new[N - i - 1][N - j - 1])
				return false;
		}
	}
	return true;
}

bool is_rotate_270(char arr[MAXN][MAXN])
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (arr[i][j] != arr_new[N - j - 1][i])
				return false;
		}
	}
	return true;
}

bool is_vertical_reflection(char arr[MAXN][MAXN])
{
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (arr[i][j] != arr_new[N - i - 1][j])
				return false;
		}
	}
	return true;
}

bool is_combination(char arr[MAXN][MAXN], int *rotation)
{
	*rotation = 0;
	int i, j;
	char arr_mir[MAXN][MAXN];

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			arr_mir[N - i - 1][j] = arr[i][j];
		}
	}

	if (is_rotate_90(arr_mir))
	{
		*rotation = 90;
		return true;
	}
	else if (is_rotate_180(arr_mir))
	{
		*rotation = 180;
		return true;
	}
	else if (is_rotate_270(arr_mir))
	{
		*rotation = 270;
		return true;
	}
	return false;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, j, k, l;
	char inp[25];
	bool is_preserved;
	int case_no = 0;
	while (scanf("%d", &N) == 1)
	{
		gets(inp);
		is_preserved = true;
		l = 2 * N + 1;
		for (i = 0; i < N; ++i)
		{
			gets(inp);
			for (j = 0, k = 0; j < N; ++j, ++k)
				arr_main[i][k] = inp[j];
			++j;
			for (k = 0; j < l; ++j, ++k)
			{
				arr_new[i][k] = inp[j];
				if (is_preserved && arr_new[i][k] != arr_main[i][k])
					is_preserved = false;
			}
		}//end for
		int rotation;
		printf("Pattern %d was ", ++case_no);
		if (is_preserved)
			printf("preserved.\n");
		else if (is_rotate_90(arr_main))
			printf("rotated 90 degrees.\n");
		else if (is_rotate_180(arr_main))
			printf("rotated 180 degrees.\n");
		else if (is_rotate_270(arr_main))
			printf("rotated 270 degrees.\n");
		else if (is_vertical_reflection(arr_main))
			printf("reflected vertically.\n");
		else if (is_combination(arr_main, &rotation))
			printf("reflected vertically and rotated %d degrees.\n", rotation);
		else
			printf("improperly transformed.\n");
	}
}