//353 - Pesky Palindromes
#include <stdio.h>
#include <set>
#include <string>
using namespace std;

bool is_palindrom(char *str, int start, int end)
{
	int i, k;
	i = start;
	k = end;
	while (str[i] == str[k] && i <= k)
	{
		++i;
		--k;
	}
	if (i >= k)
		return true;
	return false;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	set<string> set_pd;
	char inp[100], str[100];
	bool has[256];
	int i, len, count, cur_len, k, l, m;
	while (gets(inp))
	{
		if (!inp[0])
			continue;
		for (i = 0; i < 256; ++i)
			has[i] = false;
		len = 0;
		count = 0;
		set_pd.clear();
		str[1] = 0x00;
		while (inp[len] && inp[len] != ' ')
		{
			str[0] = inp[len];
			set_pd.insert(str);
			++len;
		}
		
		for (cur_len = 2; cur_len <= len; ++cur_len)
		{
			for (i = 0; i + cur_len <= len; ++i)
			{
				l = i + cur_len - 1;
				if (is_palindrom(inp, i, l))
				{
					m = 0;
					for (k = i; k <= l; ++k)
						str[m++] = inp[k];
					str[m] = 0x00;
					set_pd.insert(str);
				}
			}
		}
		printf("The string '%s' contains %d palindromes.\n", inp, set_pd.size());
	}

	return 0;
}