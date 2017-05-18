#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	bool solved[11];
	int penalty[11];
	int total_penaly;
	int total_solved;
	int total_tried;
	int number;
}t_cont;

t_cont s_contestant[101];

void init()
{
	int i, j;
	for (i = 0; i <= 100; ++i)
	{
		s_contestant[i].number = i;
		s_contestant[i].total_solved = 0;
		s_contestant[i].total_penaly = 0;
		s_contestant[i].total_tried = 0;
		for (j = 0; j <= 10; ++j)
		{
			s_contestant[i].penalty[j] = 0;
			s_contestant[i].solved[j] = false;
		}
	}
}

int sortf(const void *a, const void *b)
{
	t_cont *p1 = (t_cont *)a;
	t_cont *p2 = (t_cont *)b;

	if (p1->total_solved == p2->total_solved)
	{
		if (p1->total_penaly == p2->total_penaly)
			return p1->number - p2->number;
		else
			return p1->total_penaly - p2->total_penaly;
	}
	else
		return p2->total_solved - p1->total_solved;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int cont, prob, time, T, i, num, case_no = 0;
	char inp[1000], L;
	scanf("%d", &T);
	gets(inp);
	gets(inp);
	while (T--)
	{
		init();
		while (gets(inp))
		{
			if (!inp[0])
				break;
			i = 0;
			num = 0;
			while (inp[i] != ' ')
			{
				num = (num * 10) + (inp[i] - '0');
				++i;
			}
			cont = num;
			++i;
			num = 0;
			while (inp[i] != ' ')
			{
				num = (num * 10) + (inp[i] - '0');
				++i;
			}
			prob = num;
			++i;
			num = 0;
			while (inp[i] != ' ')
			{
				num = (num * 10) + (inp[i] - '0');
				++i;
			}
			time = num;
			++i;
			L = inp[i];
			
			s_contestant[cont].total_tried++;
			if (!s_contestant[cont].solved[prob])
			{
				if (L == 'C')
				{
					s_contestant[cont].solved[prob] = true;
					s_contestant[cont].penalty[prob] += time;
					s_contestant[cont].total_solved += 1;
					s_contestant[cont].total_penaly += s_contestant[cont].penalty[prob];
				}
				else if (L == 'I')
				{
					s_contestant[cont].penalty[prob] += 20;
				}
			}
		}//while (gets(inp))
		
		if (case_no > 0)
			printf("\n");
		
		qsort(s_contestant, 101, sizeof(t_cont), sortf);

		for (i = 0; i <= 100; ++i)
		{
			if (s_contestant[i].total_tried > 0)
			{
				printf("%d %d %d\n", s_contestant[i].number, s_contestant[i].total_solved, s_contestant[i].total_penaly);
			}
		}
		++case_no;
	}
}