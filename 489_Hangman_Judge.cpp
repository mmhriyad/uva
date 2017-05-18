#include <stdio.h>

#define MAX 256
#define NEW_LINE '\n'
bool alph[26], alph2[26];
int char_count, wrong_count, case_no;

int main()
{
	freopen("input.txt", "r", stdin);
	char ch;
	int i;
	for(;;)
	{
		scanf("%d", &case_no);
		if(case_no < 0)
			break;
		for(i=0; i<26; i++)
			alph[i] = alph2[i] = false;
		getchar();
		char_count = 0;
		wrong_count = 0;
		for(;;)
		{
			ch = getchar();
			if(ch == NEW_LINE)
				break;
			ch -= 'a';
			if(!alph[ch])
			{
				alph[ch] = alph2[ch] = true;
				char_count++;
			}
		}
		for(;;)
		{
			ch = getchar();
			if(ch == NEW_LINE)
				break;
			ch -= 'a';
			if(alph[ch])
			{
				if(wrong_count < 7 && alph2[ch])
				{
					alph2[ch] = false;
					char_count--;
				}
			}
			else
			{
				if(char_count > 0 && !alph2[ch])
				{
					alph2[ch] = true;
					wrong_count++;
				}
			}
		}
		printf("Round %d\n", case_no);
		if(wrong_count>=7)
			printf("You lose.\n");
		else if(char_count == 0)
			printf("You win.\n");
		else
			printf("You chickened out.\n");

	}

}