#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int a, b, qt, d, i;
	while (scanf("%d %d", &a, &b) == 2)
	{
		printf("[");
		qt = 1;
		i = 0;
		while (qt != 0)
		{
			d = a / b;
			qt = a % b;
			if (i == 0)
				printf("%d", d);
			else if (i == 1)
				printf(";%d", d);
			else
				printf(",%d", d);
			++i;
			a = b;
			b = qt;
		}
		printf("]\n");
	}

	return 0;
}