#include <stdio.h>

#define MAXL 205

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int T, i, k;
	int res, carry;
	bool start;
	char inp1[MAXL], inp2[MAXL], out[MAXL];

	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %s", inp1, inp2);
		i = 0;
		k = 0;
		carry = 0;
		res = 0;
		start = false;
		while (inp1[i] && inp2[i])
		{
			res = inp1[i] - '0' + inp2[i] - '0' + carry;
			carry = res / 10;
			res = res % 10;
			if (start || res)
			{
				out[k++] = res + '0';
				start = true;
			}
			++i;
		}
		if (inp1[i])
		{
			while (inp1[i])
			{
				res = inp1[i] - '0' + carry;
				carry = res / 10;
				res = res % 10;
				if (start || res)
				{
					out[k++] = res + '0';
					start = true;
				}
				++i;
			}
		}
		else if (inp2[i])
		{
			while (inp2[i])
			{
				res = inp2[i] - '0' + carry;
				carry = res / 10;
				res = res % 10;
				if (start || res)
				{
					out[k++] = res + '0';
					start = true;
				}
				++i;
			}
		}
		if (carry)
			out[k++] = carry + '0';
		out[k] = 0x00;
		puts(out);
	}

	return 0;
}