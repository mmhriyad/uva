//755 - 487–3279 
//Author : Md. Mahbubul Huq (Riyad)
//Runtime : 0.120s (0.066)
//Rank : 30

#include <stdio.h>

#define MAX_VAL 10000000
#define MAX_ENTRY 100001

int map[26] = {
	2, 2, 2, //a,b,c
	3, 3, 3, //d,e,f
	4, 4, 4, //g,h,i
	5, 5, 5, //j,k,l
	6, 6, 6, //m,n,o
	7, 0, 7, 7, //p,q,r,s
	8, 8, 8, //t,u,v
	9, 9, 9, 0 //w,x,y,z
};

int values[MAX_VAL];

void init()
{
	for (int i = 0; i < MAX_VAL; ++i)
		values[i] = 0;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int val, N, T;
	char inp[100];
	bool has_dupli;
	int min, max;
	char cn1[4], cn2[5];
	int n1, n2;

	init();

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		gets(inp);
		has_dupli = false;
		min = MAX_VAL;
		max = 0;
		
		for (int i = 0; i < N; ++i) {
			val = 0;
			gets(inp);
			int l = 0;
			while (inp[l]) {
				char ch = inp[l];
				if (ch >= 'A' && ch <= 'Z') {
					val = val * 10 + map[ch - 'A'];
				}
				else if (ch >= '0' && ch <= '9') {
					val = val * 10 + (ch - '0');
				}
				++l;
			}

			values[val]++;
			if (values[val] > 1)
				has_dupli = true;
			
			if (val < min)
				min = val;
			if (val > max)
				max = val;
		}

		if (has_dupli == false) {
			printf("No duplicates.\n");
			for (int i = min; i <= max; ++i) {
				values[i] = 0;
			}
		}
		else {
			for (int i = min; i <= max; ++i) {
				int val = i;
				int count = values[val];
				char ch;
				if (count > 1) {
					n1 = (val / 10000);
					n2 = (val % 10000);
					
					cn1[3] = 0x00;
					int l = 2;
					while (l >= 0) {
						ch = (n1 % 10) + '0';
						cn1[l] = ch;
						n1 /= 10;
						--l;
					}

					cn2[4] = 0x00;
					l = 3;
					while (l >= 0) {
						ch = (n2 % 10) + '0';
						cn2[l] = ch;
						n2 /= 10;
						--l;
					}
					
					printf("%s-%s %d\n", cn1, cn2, count);
				}
				values[i] = 0;
			}
		}

		if (T) {
			printf("\n");
		}
	}

	return 0;
}