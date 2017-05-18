#include <stdio.h>
#include <string.h>

#define MAXN 101
#define GET_MAX(x, y) (x > y ? x : y)

typedef struct
{
	bool printed;
	char wrd[35];
}t_wrd_list;

t_wrd_list list1[MAXN], list2[MAXN];
int arr[MAXN][MAXN], print[MAXN];
int N1, N2;

void run_dp()
{
	int i, j, n, max;
	n = 0;
	max = 0;
	for (i = 0; i <= N1; ++i)
	{
		for (j = 0; j <= N2; ++j)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
			else
			{
				if (!strcmp(list1[i - 1].wrd, list2[j - 1].wrd))
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = GET_MAX(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	i = N1;
	j = N2;
	n = 0;
	while (i > 0 && j > 0)
	{
		if (arr[i][j] == arr[i][j - 1])
			--j;
		else if (arr[i][j] == arr[i - 1][j])
			--i;
		else
		{
			print[n++] = i - 1;
			--i;
			--j;
		}
	}
	for (i = n - 1; i >= 0; --i)
	{
		if (i == n - 1)
			printf("%s", list1[print[i]].wrd);
		else
			printf(" %s", list1[print[i]].wrd);
	}
	printf("\n");

}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char inp[3005], ch;
	int i, j;
	bool start_second;

	start_second = false;
	N1 = N2 = 0;
	list1[N1].printed = list2[N2].printed = false;
	while (gets(inp))
	{
		if (inp[0] == '#')
		{
			if (start_second)
			{
				run_dp();
				start_second = false;
				N1 = N2 = 0;
				list1[N1].printed = list2[N2].printed = false;
			}
			else
				start_second = true;
			continue;
		}
		if (!start_second)
		{
			i = j = 0;
			while (inp[i])
			{
				ch = inp[i];
				if (ch == ' ')
				{
					list1[N1].wrd[j] = 0x00;
					++N1;
					j = 0;
					list1[N1].printed = false;
				}
				else //if (ch >= 'a' && ch <= 'z')
				{
					list1[N1].wrd[j++] = ch;
				}
				++i;
			}
			if (j > 0)
			{
				list1[N1].wrd[j] = 0x00;
				++N1;
			}
		}
		else
		{
			i = j = 0;
			while (inp[i])
			{
				ch = inp[i];
				if (ch == ' ')
				{
					list2[N2].wrd[j] = 0x00;
					++N2;
					list2[N2].printed = false;
					j = 0;
				}
				else //if (ch >= 'a' && ch <= 'z')
				{
					list2[N2].wrd[j++] = ch;
				}
				++i;
			}
			if (j > 0)
			{
				list2[N2].wrd[j] = 0x00;
				++N2;
			}
		} // else
	} // while

	return 0;
}