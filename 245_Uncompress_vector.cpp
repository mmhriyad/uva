//245 - Uncompress
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define IS_CHAR(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define IS_NUM(x) (x >= '0' && x <= '9')
#define INT(x) (x - '0')

vector<string> v_list;

int main()
{
	/*freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/

	int i, k, num;
	char wrd[55], inp[10000];
	string out;
	out = "";
	while (gets(inp))
	{
		if (inp[0] == '0')
			break;
		i = 0;
		out = "";
		while (inp[i])
		{
			k = 0;
			while (inp[i] && IS_CHAR(inp[i]))
			{
				wrd[k++] = inp[i++];
			}
			if (k > 0)
			{
				wrd[k] = 0x00;
				v_list.insert(v_list.begin(), wrd);
				out += wrd;
			}
			num = 0;
			while (inp[i] && IS_NUM(inp[i]))
			{
				num = num * 10 + INT(inp[i++]);
			}
			if (num)
			{
				out += v_list[num - 1];
				v_list.insert(v_list.begin(), v_list[num - 1]);
				v_list.erase(v_list.begin() + num);
			}
			k = 0;
			while (inp[i] && !IS_CHAR(inp[i]) && !IS_NUM(inp[i]))
			{
				wrd[k++] = inp[i++];
			}
			if (k > 0)
			{
				wrd[k] = 0x00;
				//v_list.insert(v_list.begin(), wrd);
				out += wrd;
			}
		}
		cout << out << endl;
	}

	return 0;
}