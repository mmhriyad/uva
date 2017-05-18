#include <iostream>
#include <vector>
using namespace std;

#define MAXNODES 27
#define INF 99999999
int dist_y[MAXNODES][MAXNODES], dist_m[MAXNODES][MAXNODES];

int main()
{
	int n, energy, i,j,k;
	char rtype, dir, x, y, a, b;
	for(;;)
	{
		cin>>n;
		if(n==0)
			return 0;
		for(i=0;i<MAXNODES;i++)
		{
			for(j=0; j<MAXNODES; j++)
			{
				if(i==j)
					dist_y[i][j] = dist_m[i][j] = 0;
				else
					dist_y[i][j] = dist_m[i][j] = INF;
			}
		}
		while(n--)
		{
			cin>>rtype>>dir>>x>>y>>energy;
			if(rtype == 'Y')
			{
				if(dist_y[x-'A'][y-'A'] > energy)
					dist_y[x-'A'][y-'A'] = energy;
				if((dir == 'B') && dist_y[y-'A'][x-'A'] > energy)
					dist_y[y-'A'][x-'A'] = energy;
			}
			else
			{
				if(dist_m[x-'A'][y-'A'] > energy)
					dist_m[x-'A'][y-'A'] = energy;
				if((dir == 'B') && (dist_m[y-'A'][x-'A'] > energy))
					dist_m[y-'A'][x-'A'] = energy;
			}
		}
		cin>>a>>b;
		/*if(a==b)
		{
			cout<<"0 "<<a<<endl;
			continue;
		}*/
		for(k=0; k<MAXNODES; k++)
		{
			for(i=0; i<MAXNODES; i++)
			{
				for(j=0; j<MAXNODES; j++)
				{
					if(dist_y[i][j] > dist_y[i][k]+dist_y[k][j])
						dist_y[i][j] = dist_y[i][k]+dist_y[k][j];
					if(dist_m[i][j] > dist_m[i][k]+dist_m[k][j])
						dist_m[i][j] = dist_m[i][k]+dist_m[k][j];
				}
			}
		}
		int mindist = INF, place=0;
		char p = 'A';
	
		for(j=0; j<MAXNODES; j++)
		{
			if((dist_y[a-'A'][j] != INF && dist_m[b-'A'][j] != INF) && (mindist > dist_y[a-'A'][j]+dist_m[b-'A'][j]))
			{
				//if(mindist > dist_y[a-'A'][j]+dist_m[b-'A'][j])
				{
					mindist = dist_y[a-'A'][j]+dist_m[b-'A'][j];
					place = j;
				}
			}
		}
		p+=place;
		if(mindist == INF)
			cout<<"You will never meet."<<endl;
		else
		{
			cout<<mindist;//<<p<<endl;
			for(j=0; j<MAXNODES; j++)
			{
				p = 'A';
				if((mindist == dist_y[a-'A'][j]+dist_m[b-'A'][j]))
				{
					p += j;
					cout<<" "<<p;
				}
			}
			cout<<endl;
		}
	}
}


/*
input:
2
Y U A B 10
Y U A B 100
A B
4 
Y B A B 2 
Y U B D 0 
M B B C 3 
M U B D 0 
B B
4
Y U A B 4
Y U C A 1
M U D B 6
M B C D 2
A D
2
Y U A B 10
M U C D 20
A D
6
Y U A Z 0
Y U C A 0
Y U A Y 0
M U D Z 0
M B C D 0
M B C Y 0
A D
2
Y U B D 0
M U B D 0
B B
2
Y U A B 0
M U A B 0
A C
2
Y U A B 0
M U A B 0
C C
2
Y U A Z 10
Y U A B 20
K K
2
Y U X Z 1
Y U X Z 10
X Z
2
M U X Z 1
M U X Z 10
X Z
2
M U X Z 1
Y U X Z 10
X Z
2
Y U A B 0
M U B A 10
A B
3
Y U A B 5
M B B C 5
M U B A 10
A B
3
Y U X Y 5
M B A Y 10
Y B X Y 10
X A
2
Y U A B 10
Y U A B 100
A B
0
output:
10 B
0 B D
10 B
You will never meet.
0 Y Z
0 B D
You will never meet.
0 C
0 K
1 Z
You will never meet.
10 Z
0 B
5 B
15 Y
10 B
*/