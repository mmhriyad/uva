#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

vector <char> stack;

int N;
char b[2] = {'(', '[' };
char e[2] = { ')', ']' };
char inp[200];


int main()
{
	freopen("input.txt", "r", stdin);
	bool yes = false, pushed = false;
	char ch;
	int i, len, j, size;
	scanf("%d", &N);
	while(getchar() != '\n')
		continue;
	while(N--)
	{
		stack.clear();
		yes = true;

		for(;;)
		{
			ch = getchar();

			if(ch == '\n' || ch == EOF)
			{
				if(yes)
					yes = stack.empty();

				if(yes)
					printf("Yes\n");
				else
					printf("No\n");
				break;
			}

			pushed = false;
			for(j=0; j<2; j++)
			{
				if(ch == b[j])
				{
					stack.push_back(e[j]);
					pushed = true;
					break;
				}
			}
			if(!pushed && (ch == ']' || ch == ')'))
			{
				size = stack.size();
				if(stack.empty())
				{
					yes = false;
					continue;
				}
				else if(ch != stack[size-1])
				{
					yes = false;
					continue;
				}
				else
					stack.pop_back();
			}
		}

	}
}