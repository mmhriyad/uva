#include <stdio.h>

#define MAXL 100000

int main()
{
	char str1[MAXL], str2[MAXL];
	int i, j;
	while (scanf("%s %s", str1, str2) == 2)
	{
		i = j = 0;
		while (str1[i] && str2[j])
		{
			if (str1[i] == str2[j])
				++i;
			++j;
		}
		if (str1[i])
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}