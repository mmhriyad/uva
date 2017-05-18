//245 - Uncompress
#include <stdio.h>
#include <iostream>
#include <list>
#include <string>
using namespace std;

#define IS_CHAR(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define IS_NUM(x) (x >= '0' && x <= '9')
#define INT(x) (x - '0')

list<string> l_list;
list<string>::iterator l_it;

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, k, num, l;
	char wrd[55], inp[200], str_out[500];
	//string out;
	while (gets(inp))
	{
		if (inp[0] == '0')
			break;
		i = 0;
		l = 0;
		//out = "";
		while (inp[i])
		{
			k = 0;
			while (inp[i] && IS_CHAR(inp[i]))
			{
				wrd[k] = str_out[l] = inp[i];
				++i;
				++l;
				++k;
			}
			if (k > 0)
			{
				wrd[k] = 0x00;
				//l_list.insert(l_list.begin(), wrd);
				l_list.push_front(wrd);
				//out += wrd;
			}
			num = 0;
			while (inp[i] && IS_NUM(inp[i]))
			{
				num = num * 10 + INT(inp[i++]);
			}
			if (num)
			{
				l_it = l_list.begin();
				advance(l_it, num - 1);
				//out += *l_it;
				k = 0;
				while ((*l_it)[k])
				{
					str_out[l++] = (*l_it)[k++];
				}
				//l_list.insert(l_list.begin(), *l_it);
				l_list.push_front(*l_it);
				l_list.erase(l_it);
			}
			k = 0;
			while (inp[i] && !IS_CHAR(inp[i]) && !IS_NUM(inp[i]))
			{
				//wrd[k] = str_out[l] = inp[i];
				str_out[l] = inp[i];
				++i;
				++l;
				//++k;
			}

			//if (k > 0)
			//{
			//	wrd[k] = 0x00;
			//	//out += wrd;
			//}
		}
		str_out[l] = 0x00;
		//cout << out << endl;
		puts(str_out);
	}

	return 0;
}