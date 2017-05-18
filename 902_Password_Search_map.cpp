#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str, substr, pass;
	int size, len, i, max;
	while (cin >> size >> str)
	{
		len = str.length();
		len -= size;
		map<string, int> mp;
		
		for (i = 0; i <= len; ++i)
		{
			substr = str.substr(i, size);
			++mp[substr];
		}
		max = 0;
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->second > max)
			{
				max = it->second;
				pass = it->first;
			}
		}
		cout << pass << endl;
	}
}