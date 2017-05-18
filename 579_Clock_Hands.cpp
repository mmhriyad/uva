#include <stdio.h>

int main()
{
	int hh, mm;
	double angleh, anglem;
	for(;;)
	{
		scanf("%d:%d", &hh, &mm);
		printf("%d h : %d m", hh, mm);
	}
	return 0;
}