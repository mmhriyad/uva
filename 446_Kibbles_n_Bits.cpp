#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n1, n2, T, result, i;
	char op, bn1[15], bn2[15];
	bn1[13] = bn2[13] = '\0';
	scanf("%d", &T);
	while (T--)
	{
		scanf("%x %c %x", &n1, &op, &n2);
		result = n1 + n2;
		if (op == '-')
			result = n1 - n2;
		for (i = 12; i >=0; --i)
		{
			bn1[i] = (n1 & 1) + '0';
			bn2[i] = (n2 & 1) + '0';
			n1 = n1 >> 1;
			n2 = n2 >> 1;
		}
		printf("%s %c %s = %d\n", bn1, op, bn2, result);
	}
}