#include <stdio.h>


int map[256];

void init()
{
	map['c'] = 'z';
	map['v'] = 'x';
	map['b'] = 'c';
	map['n'] = 'v';
	map['m'] = 'b';
	map[','] = 'n';
	map['.'] = 'm';
	map['/'] = ',';

	map['d'] = 'a';
	map['f'] = 's';
	map['g'] = 'd';
	map['h'] = 'f';
	map['j'] = 'g';
	map['k'] = 'h';
	map['l'] = 'j';
	map[';'] = 'k';
	map['\''] = 'l';

	map['e'] = 'q';
	map['r'] = 'w';
	map['t'] = 'e';
	map['y'] = 'r';
	map['u'] = 't';
	map['i'] = 'y';
	map['o'] = 'u';
	map['p'] = 'i';
	map['['] = 'o';
	map[']'] = 'p';
	
	map['C'] = 'z';
	map['V'] = 'x';
	map['B'] = 'c';
	map['N'] = 'v';
	map['M'] = 'b';

	map['D'] = 'a';
	map['F'] = 's';
	map['G'] = 'd';
	map['H'] = 'f';
	map['J'] = 'g';
	map['K'] = 'h';
	map['L'] = 'j';

	map['E'] = 'q';
	map['R'] = 'w';
	map['T'] = 'e';
	map['Y'] = 'r';
	map['U'] = 't';
	map['I'] = 'y';
	map['O'] = 'u';
	map['P'] = 'i';

	map[' '] = ' ';
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char inp[1000], ch;
	int i;
	init();
	while (gets(inp))
	{
		i = 0;
		while (inp[i])
		{
			ch = inp[i];
			inp[i] = map[ch];
			++i;
		}
		puts(inp);
	}

	return 0;
}