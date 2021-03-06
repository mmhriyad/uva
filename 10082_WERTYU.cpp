#include <stdio.h>

char map[][2] = {
	{'S', 'A'}, 
	{'N', 'B'}, 
	{'V', 'C'}, 
	{'F', 'D'}, 
	{'R', 'E'}, 
	{'G', 'F'}, 
	{'H', 'G'}, 
	{'J', 'H'}, 
	{'O', 'I'}, 
	{'K', 'J'}, 
	{'L', 'K'}, 
	{';', 'L'}, 
	{',', 'M'}, 
	{'M', 'N'}, 
	{'P', 'O'}, 
	{'[', 'P'}, 
	{'W', 'Q'},
	{'T', 'R'},
	{'D', 'S'},
	{'Y', 'T'},
	{'I', 'U'}, 
	{'B', 'V'},
	{'E', 'W'},
	{'C', 'X'},
	{'U', 'Y'},
	{'X', 'Z'},
	{'1', '`'},
	{'2', '1'},
	{'3', '2'},
	{'4', '3'},
	{'5', '4'},
	{'6', '5'},
	{'7', '6'},
	{'8', '7'},
	{'9', '8'},
	{'0', '9'},
	{'-', '0'},
	{'=', '-'},
	{']', '['},
	{'\\', ']'},
	{'\'', ';'},
	{'.', ','},
	{'/', '.'}
};

int main()
{
	freopen("input.txt", "r", stdin);
	char ch;
	int i;
	for(;;)
	{
		ch = getchar();
		if(ch == EOF)
			return 0;
		if(ch == ' ' || ch == '\n')
			putchar(ch);
		else
		{
			for(i=0; i<43; i++)
			{
				if(map[i][0] == ch)
				{
					putchar(map[i][1]);
					break;
				}
			}
		}
	}
}