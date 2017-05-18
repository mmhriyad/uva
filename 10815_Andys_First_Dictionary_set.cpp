#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	char inp[10000], word[10000], ch;
	set<string> dictionary;
	int i, n, k;
	n = 0;
	while (gets(inp))
	{
		i = 0;
		while (inp[i])
		{
			while (inp[i] && !((inp[i] >= 'a' && inp[i] <= 'z') || (inp[i] >= 'A' && inp[i] <= 'Z')))
				++i;
			k = 0;
			while (inp[i])
			{
				ch = inp[i];
				if (ch >= 'a' && ch <= 'z')
					word[k++] = ch;
				else if (ch >= 'A' && ch <= 'Z')
					word[k++] = ch + 'a' - 'A';
				else
					break;
				++i;
			}
			word[k] = 0x00;
			if (k > 0)
				dictionary.insert(word);
		}
	}

	set<string>::iterator it;
	for (it = dictionary.begin(); it != dictionary.end(); ++it)
		cout << *it << endl;
}