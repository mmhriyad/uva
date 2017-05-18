#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char str[105][105], str2[105][105];
	int i = 0, max_len = 0, len, j, N, k;
	while (gets(str[i]))
	{
		if (str[i][0] == '0')
			break;
		len = strlen(str[i]);
		if (len > max_len)
			max_len = len;
		++i;
	}
	N = i;
	for (i = 0; i < N; ++i)
	{
		len = strlen(str[i]);
		for (j = 0; j < max_len - len; ++j)
			str2[i][j] = '0';
		for (k=0; j < max_len; ++j, ++k)
			str2[i][j] = str[i][k];
	}
	int sum, carry = 0, val;

	str[N][max_len] = '\0';
	for (j = max_len - 1; j >= 0; --j)
	{
		sum = carry;
		for (i = 0; i < N; i++)
		{
			sum += (str2[i][j] - '0');
		}
		carry = sum / 10;
		str[N][j] = (sum % 10) + '0';
	}
	if (carry)
		printf("%d%s\n", carry, str[N]);
	else
		puts(str[N]);
	return 0;
}