#include <stdio.h>

typedef struct
{
	int source, stime, etime, dest;
}t_slist;

t_slist listarr[100];

int N;

int getNumber(int source, int tm, int originalsource, int count)
{
	if (source == originalsource && count > 0)
		return 9999;
	int i;
	for (i = 0; i < N; ++i)
	{
		t_slist *edge = &listarr[i];
		if (edge->source == source && (edge->stime <= tm  && edge->etime >= tm))
			return getNumber(edge->dest, tm, originalsource, count + 1);
	}
	return source;
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, i, tm, src, dst, syst;
	char stm[5] = "0000", ssrc[5] = "0000", sdest[5] = "0000";
	scanf("%d", &T);
	printf("CALL FORWARDING OUTPUT\n");
	for (syst = 1; syst <= T; ++syst)
	{
		N = 0;
		while (true)
		{
			scanf("%d", &listarr[N].source);
			if (listarr[N].source == 0)
				break;
			scanf("%d %d %d", &listarr[N].stime, &listarr[N].etime, &listarr[N].dest);
			listarr[N].etime += listarr[N].stime;
			++N;
		}
		printf("SYSTEM %d\n", syst);
		while (true)
		{
			scanf("%d", &tm);
			if (tm == 9000)
				break;
			scanf("%d", &src);
			
			dst = getNumber(src, tm, src, 0);
			i = 3;
			while (i>=0)
			{
				stm[i] = '0' + tm % 10;
				tm /= 10;
				ssrc[i] = '0' + src % 10;
				src /= 10;
				sdest[i] = '0' + dst % 10;
				dst /= 10;
				--i;
			}
			printf("AT %s CALL TO %s RINGS %s\n", stm, ssrc, sdest);

		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}