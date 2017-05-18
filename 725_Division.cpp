//this problem is used backtrack

#include <stdio.h>

#define MAXN 10
#define MAXPOS 5
bool taken[MAXN], found = false;
int arr[MAXPOS], arr2[MAXPOS];;

int N;
#if 0
void print()
{
	int i, num = 0, num2, tmp, j = MAXPOS;
	char snum[MAXPOS + 1];
	for (i = 0; i < MAXPOS; i++)
	{
		num = num * 10 + arr[i];
		snum[i] = '0' + arr[i];
	}
	snum[i] = '\0';
	num2 = num * N;
	tmp = num2;
	if (num2 / 10000 > 0)
	{
		while (num2)
		{
			i = num2 % 10;
			if (taken[i])
				break;
			arr2[--j] = i;
			taken[i] = true;
			num2 /= 10;
		}
		if (!num2)
		{
			found = true;
			printf("%d / %s = %d\n", tmp, snum, N);
		}
		for (i = j; i < MAXPOS; i++)
			taken[arr2[i]] = false;
	}
}

void backtrack(int pos)
{
	if (pos == MAXPOS)
	{
		print();
		return;
	}
	int i;
	for (i = 0; i < MAXN; i++)
	{
		if (pos == 0 && i*N > 9)
			continue;
		if (!taken[i])
		{
			taken[i] = true;
			arr[pos] = i;
			backtrack(pos + 1);
			taken[i] = false;
		}
	}
}
#endif
void linear()
{
	int i, num2, j, tmp, tmp2, a;
	i = 1234;
	num2 = i * N;
	char snum1[MAXPOS + 1];
	for (; num2 <= 98765; i++, num2 = i*N)
	{
		if (num2 / 10000 <= 0)
			continue;
		tmp = i;
		tmp2 = num2;
		for (j = 0; j < MAXN; j++)
			taken[j] = false;
		snum1[0] = '0';
		snum1[MAXPOS] = '\0';
		j = MAXPOS;
		if (i / 10000 <= 0)
			taken[0] = true;
		while (tmp)
		{
			a = tmp % 10;
			if (taken[a])
				break;
			taken[a] = true;
			snum1[--j] = '0' + a;
			tmp /= 10;
		}
		if (tmp == 0)
		{
			while (tmp2)
			{
				a = tmp2 % 10;
				if (taken[a])
					break;
				taken[a] = true;
				tmp2 /= 10;
			}
			if (tmp2 == 0)
			{
				found = true;
				printf("%d / %s = %d\n", num2, snum1, N);
			}

		}
	} // end for
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, caseNo = 0;
	for (i = 0; i < MAXN; i++)
		taken[i] = false;
	while (scanf("%d", &N) == 1 && N)
	{
		found = false;
		if (caseNo)
			printf("\n");
		//backtrack(0); // run time : 0.009
		linear(); // runtime : 0.009
		if (!found)
			printf("There are no solutions for %d.\n", N);
		++caseNo;
	}
	return 0;
}