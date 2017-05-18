#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T, cn;
	long long int a, b, c;
	scanf("%d", &T);
	for (cn = 1; cn <= T; ++cn)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		printf("Case %d: ", cn);
		if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (c + b <= a))
			printf("Invalid\n");
		else
		{
			if (a == b && b == c)
				printf("Equilateral\n");
			else if (a == b || a == c || b == c)
				printf("Isosceles\n");
			else
				printf("Scalene\n");
		}
	}

	return 0;
}