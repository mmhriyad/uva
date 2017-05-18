#include <stdio.h>

int max = 0;
int surp = 0, defct = 0;
int rep[12];

int getreport(int month)
{
	int i;
	int sum = 0;
	for (i = month - 4; i <= month; ++i)
		sum += rep[i];
	return sum;
}

void backtrack(int month, int earning)
{
	if (max >= 0)
		return;
	if (month == 12)
	{
		if (earning > max)
			max = earning;
		//for (int j = 0; j < 12; ++j)
		//	printf("%d + ", rep[j]);
		//printf("\n=============================\n");
		return;
	}
	int i = month;
	//for (i = month; i < 12; ++i)
	{
		rep[i] = surp;
		if (i < 4 || (i>=4 && getreport(i) < 0))
		{
			backtrack(i + 1, earning + surp);
		}
		rep[i] = -defct;
		if (i >= 4 && getreport(i) >= 0)
			return;
		backtrack(i + 1, earning - defct);
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d %d", &surp, &defct) == 2)
	{
		max = -1;
		backtrack(0, 0);
		if (max < 0)
			printf("Deficit\n");
		else
			printf("%d\n", max);
	}
	return 0;
}