#include <stdio.h>
#include <stdlib.h>

int arr[4];

int sortf(const void *a, const void *b)
{
	int *num1 = (int *)a;
	int *num2 = (int *)b;
	return *num1 - *num2;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
		qsort(arr, 4, sizeof(int), sortf);
		if (arr[0] == 0)
			printf("banana\n");
		else
		{
			if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
				printf("square\n");
			else
			{
				if (arr[0] == arr[1] && arr[2] == arr[3])
				{
					printf("rectangle\n");
				}
				else if (arr[0] + arr[1] + arr[2] > arr[3])
				{
					printf("quadrangle\n");
				}
				else
					printf("banana\n");
			}
		}
	}
}