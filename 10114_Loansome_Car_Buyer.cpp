#include <stdio.h>

#define MAX_MONTH 101

int main()
{
	int lm, nd;
	double inst, car_val, rem_loan, dp;
	for(;;)
	{
		int req_mon = 0, nex_mon = 0;
		int dep_month[101];
		double dep_rate[101];
		int i,j;

		scanf("%d %lf %lf %d", &lm, &dp, &rem_loan, &nd);
		if(lm < 0) return 0;

		inst = rem_loan/lm;
		car_val = rem_loan + dp;

		for(i=0; i<nd; i++)
		{
			scanf("%d %lf", &dep_month[i], &dep_rate[i]);
		}

		car_val = car_val - (car_val * dep_rate[0]);

		while(car_val < rem_loan)
		{
			req_mon++;
			if((nex_mon+1 < nd) && (dep_month[nex_mon+1] == req_mon))
				nex_mon++;
			rem_loan -= inst;
			car_val = car_val - (car_val * dep_rate[nex_mon]);
		}
		if(req_mon == 1)
			printf("%d month\n", req_mon);
		else printf("%d months\n", req_mon);
	}
	return 0;
}

/*
input:
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
100 0 60000 101
0 .1
1 .1
2 .01
3 .01
4 .1
5 .1
6 .01
7 .01
8 .01
9 .01
10 .1
11 .01
12 .01
13 .01
14 .01
15 .01
16 .01
17 .01
18 .01
19 .01
20 .1
21 .01
22 .01
23 .01
24 .01
25 .01
26 .01
27 .01
28 .01
29 .01
30 .1
31 .01
32 .01
33 .01
34 .01
35 .01
36 .01
37 .01
38 .01
39 .01
40 .1
41 .01
42 .01
43 .01
44 .01
45 .01
46 .01
47 .01
48 .01
49 .01
50 .1
51 .01
52 .01
53 .01
54 .01
55 .01
56 .01
57 .01
58 .01
59 .01
60 .1
61 .01
62 .01
63 .01
64 .01
65 .01
66 .01
67 .01
68 .01
69 .01
70 .1
71 .1
72 .1
73 .1
74 .1
75 .01
76 .01
77 .01
78 .01
79 .01
80 .1
81 .1
82 .1
83 .1
84 .1
85 .1
86 .1
87 .1
88 .1
89 .1
90 .1
91 .1
92 .1
93 .01
94 .01
95 .01
96 .1
97 .1
98 .1
99 .1
100 .1
100 0 75000 2
0 .10
99 .5
100 74999 1 1
0 .20
36 2000 10000 4
0 .2
1 .1
3 .01
10 .005
36 0 12000 3
0 .25
1 .1
10 .005
23 3000 5000 2
0 .15
20 .005
42 4000 0 1
0 .79
-10 0 0 4


output:
4 months
1 month
49 months
99 months
100 months
0 months
11 months
27 months
0 months
0 months
*/