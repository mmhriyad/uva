#include <stdio.h>

#define MAXN 10001

#define GET_MAX(x, y) (x > y ? x : y)
#define GET_MIN(x, y) (x < y ? x : y)

typedef struct
{
	int x, y, val;
}pixel_t;

pixel_t pixel[MAXN];

int main()
{
	//freopen("inp.txt", "r", stdin);
	int a, h, b, i, min = MAXN, max = 0;
	for (i = 0; i < MAXN; i++)
	{
		pixel[i].x = i;
		pixel[i].y = i + 1;
		pixel[i].val = 0;
	}
	while (scanf("%d %d %d", &a, &h, &b) == 3)
	{
		if (min == MAXN)
			min = a;
		max = GET_MAX(max, b);
		for (i = a; i < b; i++)
		{
			pixel[i].val = GET_MAX(pixel[i].val, h);
		}
	}
	i = min;
	int prev = pixel[i].val;
	while (i < max)
	{
		prev = pixel[i].val;
		printf("%d %d ", pixel[i].x, pixel[i].val);
		while (prev == pixel[++i].val);
	}
	printf("%d %d\n", pixel[i].x, pixel[i].val);

	return 0;
}