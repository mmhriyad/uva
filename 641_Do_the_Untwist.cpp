//641 - Do the Untwist
#include <stdio.h>

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	char plaintext[100], chiphertext[100];
	int i, num, len, k;
	while (scanf("%d", &k) == 1 && k)
	{
		getchar();
		gets(chiphertext);
		i = 0;
		while (chiphertext[i])
		{
			if (chiphertext[i] >= 'a' && chiphertext[i] <= 'z')
				chiphertext[i] = (chiphertext[i] - 'a' + 1 + i) % 28;
			else if (chiphertext[i] == '_')
				chiphertext[i] = (i) % 28;
			else if (chiphertext[i] == '.')
				chiphertext[i] = (27 + i) % 28;

			if (chiphertext[i] == 0)
				chiphertext[i] = '_';
			else if (chiphertext[i] == 27)
				chiphertext[i] = '.';
			else
				chiphertext[i] = chiphertext[i] - 1 + 'a';
			++i;
		}
		len = i;
		i = 0;
		while (chiphertext[i])
		{
			plaintext[(k*i) % len] = chiphertext[i];
			++i;
		}
		plaintext[len] = 0x00;
		puts(plaintext);
	}

	return 0;
}