#include <iostream>
#include <cmath>

#define PI 3.14159265 //(22/7)

using namespace std;

int main()
{
	int len_h, len_v, A, v, t;
	int count_h, count_v;
	double sin_val, cos_val, vel_h, vel_v, max_s_h, max_s_v; 

	for(;;)
	{
		cin>>len_h>>len_v>>v>>A>>t;

		if(!(len_h|len_v|A|v|t)) return 0;
		
		count_h = count_v = 0;

		sin_val = (sin(((double)A)*PI/180));
		cos_val = (cos(((double)A)*PI/180));
		
		max_s_v = (double)v*t*(sin(((double)A)*PI/180))/2;
		max_s_h = (double)v*t*(cos(((double)A)*PI/180))/2;

		if(max_s_h >= ((double)len_h)/2)
		{
			count_v = 1;
			max_s_h -= ((double)len_h)/2; //ceil((double)len_h/2);//(len_h/2);
		}
		count_v += (max_s_h/len_h);

		if(max_s_v >= ((double)len_v)/2)
		{
			count_h = 1;
			max_s_v -= ((double)len_v)/2; //ceil((double)len_v/2);//(len_v/2);
		}
		count_h += (max_s_v/len_v);

		cout<<count_v<<" "<<count_h<<endl;
		//printf("%d %d\n", count_v, count_h);

	}

	return 0;
}


/*
====be carefull about odd numbers :)==========
207 3999 6033 60 4830
88 33 7 48 19
77 74 60 7 71
38 33 89 5 11
39 25 6 35 28
38 54 91 77 20
89 94 29 74 87
48 51 7 51 45
47 53 71 86 94
99 87 96 39 47
91 90 51 38 33
63 32 13 16 41
15 82 10 20 2
29 5 79 71 99
55 97 2 15 26
82 95 69 85 48
69 18 47 42 68
41 53 78 52 89
36 2 11 73 41
56 55 62 21 25
81 44 58 34 90
0 0 0 0 0
======================
35193 3155
1 1
27 4
13 1
2 2
5 16
4 13
2 2
5 63
18 16
7 6
4 2
1 0
44 739
0 0
2 17
17 59
52 52
2 108
13 5
27 33
*/