#include <stdio.h>

char *res[] = { "", "",
	"00\n01\n81", "",
"0000\n0001\n2025\n3025\n9801", "",
"000000\n000001\n088209\n494209\n998001", "",
"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001"};

int main()
{
	int i;
	while(scanf("%d", &i) == 1)
	{
		printf("%s\n", res[i]);
	}
}