#include <stdio.h>
#include <stdlib.h>

#define MAXN 26

int max_team = 0;

typedef struct
{
	int team_no;
	int problem_no;
	int time;
	char status;
}t_log;

t_log logs[1000];
int total_log = 0;

typedef struct
{
	int team_no;
	int team_rank;
	int problem_solved;
	int problem_tried;
	int time_required;
	bool solved[10];
	int penalty[10];
}t_contst;

t_contst contst[MAXN];

int sortf(const void *a, const void *b)
{
	t_contst *cn1 = (t_contst *)a;
	t_contst *cn2 = (t_contst *)b;
	if (cn1->problem_solved == cn2->problem_solved)
	{
		if (cn1->time_required == cn2->time_required)
			return cn1->team_no - cn2->team_no;
		return cn1->time_required - cn2->time_required;
	}
	return cn2->problem_solved - cn1->problem_solved;
}

int sort_log(const void *a, const void *b)
{
	t_log *log1 = (t_log *)a;
	t_log *log2 = (t_log *)b;
	
	return log1->time - log2->time;
}

void init()
{
	int i, j;
	for (i = 0; i < MAXN; ++i)
	{
		contst[i].problem_solved = 0;
		contst[i].problem_tried = 0;
		contst[i].time_required = 0;
		contst[i].team_no = i;
		for (j = 0; j < 10; ++j)
		{
			contst[i].solved[j] = false;
			contst[i].penalty[j] = 0;
		}
	}
	total_log = 0;
	max_team = 0;
}

void update_info()
{
	int i;
	int p_no, team_no, time_elsp;
	char status;
	max_team = 0;
	for (i = 0; i < total_log; ++i)
	{
		p_no = logs[i].problem_no;
		team_no = logs[i].team_no;
		status = logs[i].status;
		time_elsp = logs[i].time;
		
		if (team_no > max_team)
			max_team = team_no;

		if (!contst[team_no].solved[p_no])
		{
			if (status == 'Y')
			{
				contst[team_no].solved[p_no] = true;
				contst[team_no].penalty[p_no] += time_elsp;
				contst[team_no].time_required += contst[team_no].penalty[p_no];
				contst[team_no].problem_solved++;
				contst[team_no].problem_tried++;
			}
			else
			{
				contst[team_no].problem_tried++;
				contst[team_no].penalty[p_no] += 20;
			}
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int team_no, sub_time_h, sub_time_min, p_no, time_elsp;
	char stasus;
	int T, sum;
	char inp[1000];
	scanf("%d", &T);
	gets(inp);
	gets(inp);
	while (T--)
	{
		init();
		while (gets(inp))
		{
			int i;
			if (!inp[0])
				break;
			
			i = sum = 0;
			while (inp[i] != ' ')
			{
				sum = sum * 10 + inp[i] - '0';
				++i;
			}
			team_no = sum;
			++i;
			p_no = inp[i] - 'A';
			i+=2;
			sum = 0;
			while (inp[i] != ':')
			{
				sum = sum * 10 + inp[i] - '0';
				++i;
			}
			sub_time_h = sum;
			++i;
			sum = 0;
			while (inp[i] != ' ')
			{
				sum = sum * 10 + inp[i] - '0';
				++i;
			}
			sub_time_min = sum;
			++i;
			stasus = inp[i];
			time_elsp = sub_time_h * 60 + sub_time_min;

			logs[total_log].problem_no = p_no;
			logs[total_log].team_no = team_no;
			logs[total_log].status = stasus;
			logs[total_log].time = time_elsp;
			++total_log;

/*
			if (!contst[team_no].solved[p_no])
			{
				if (stasus == 'Y')
				{
					contst[team_no].solved[p_no] = true;
					contst[team_no].penalty[p_no] += time_elsp;
					contst[team_no].time_required += contst[team_no].penalty[p_no];
					contst[team_no].problem_solved++;
					contst[team_no].problem_tried++;
				}
				else
				{
					contst[team_no].problem_tried++;
					contst[team_no].penalty[p_no] += 20;
				}
			}*/
		}// end while

		qsort(logs, total_log, sizeof(t_log), sort_log);
		update_info();
		qsort(contst, max_team + 1, sizeof(t_contst), sortf);

		int i, rank = 0, ps, skiped = 0;
		ps = contst[0].problem_solved + 1;
		time_elsp = contst[0].time_required;
		
		printf("RANK TEAM PRO/SOLVED TIME\n");
		for (i = 0; i <= max_team; ++i)
		{
			if (contst[i].team_no > 0)
			{
				if (ps > contst[i].problem_solved || time_elsp < contst[i].time_required)
				{
					rank += skiped + 1;
					skiped = 0;
				}
				else
					++skiped;
				contst[i].team_rank = rank;

				ps = contst[i].problem_solved;
				time_elsp = contst[i].time_required;

				if (contst[i].problem_solved > 0)
				{
					printf("%4d %4d %4d %10d\n", rank, contst[i].team_no, ps, time_elsp);
				}
				else
					printf("%4d %4d\n", rank, contst[i].team_no);
			} // end if
		} // end for
		if (T)
			printf("\n");

	}//end while
}