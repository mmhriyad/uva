//401 - Palindromes
#include <stdio.h>
#include <string.h>


char mirror_mapping[26] = { 'A', ' ', ' ', ' ', '3', ' ', ' ', 'H', 'I', 'L', ' ', 'J', 'M', ' ', 'O', ' ', ' ', ' ', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5' };
char mirror_mapping_num[10] = { ' ', '1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' ' };

char get_mirror_char(char a)
{
	char ch = ' ';
	if (a >= 'A' && a <= 'Z')
		ch = mirror_mapping[a - 'A'];
	else if (a >= '1' && a <= '9')
		ch = mirror_mapping_num[a - '0'];
	return ch;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char inp[30];
	int begin, end;
	bool is_mirrored = true;
	bool is_palindrom = true;

	while (gets(inp)) {
		end = strlen(inp) - 1;
		begin = 0;
		is_mirrored = true;
		is_palindrom = true;

		while (begin <= end) {
			if (inp[begin] != inp[end])
				is_palindrom = false;
			char ch = get_mirror_char(inp[begin]);
			if (ch != inp[end])
				is_mirrored = false;

			if (is_palindrom == false && is_mirrored == false)
				break;
			++begin;
			--end;
		}

		printf("%s -- is ", inp);
		if (is_mirrored && is_palindrom)
			printf("a mirrored palindrome.\n");
		else if (is_mirrored)
			printf("a mirrored string.\n");
		else if (is_palindrom)
			printf("a regular palindrome.\n");
		else
			printf("not a palindrome.\n");

		printf("\n");
	}

	return 0;
}