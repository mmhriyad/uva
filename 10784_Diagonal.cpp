#include <stdio.h>
#include <math.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	long long int a;
	int case_no = 0;
	while (scanf("%lld", &a) == 1 && a)
	{
		printf("Case %d: %d\n", ++case_no, (int)ceil((sqrt(8.0 * a + 9.0) + 3.0) / 2.0));
	}
}