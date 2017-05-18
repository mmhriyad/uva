#include <iostream>

using namespace std;

int arr1[4][4],arr2[4][4],arr3[4][4],arr4[4][4]; // | - \ /

bool all3=false;
char inparr[4][4], ch;

int victory=0,countx=0, oppos_victory=0;
int oppos_x = -1, oppos_y = -1;

void check4all3()
{
	all3=false;
	int i, cx=0;
	for(i=0;i<4;i++)
	{
		cx = (inparr[i][0]=='x') + (inparr[i][1]=='x') + (inparr[i][2]=='x') + (inparr[i][3]=='x');
		if(4==cx)
		{
			all3=true;
			return;
		}
	}
	for(i=0;i<4;i++)
	{
		cx = (inparr[0][i]=='x') + (inparr[1][i]=='x') + (inparr[2][i]=='x') + (inparr[3][i]=='x');
		if(4==cx)
		{
			all3=true;
			return;
		}
	}
	cx = (inparr[0][0]=='x') + (inparr[1][1]=='x') + (inparr[2][2]=='x') + (inparr[3][3]=='x');
	if(4==cx)
	{
		all3=true;
		return;
	}
	cx = (inparr[0][3]=='x') + (inparr[1][2]=='x') + (inparr[2][1]=='x') + (inparr[3][0]=='x');
	if(4==cx)
	{
		all3=true;
		return;
	}
}

void check()
{
	victory=0;
	int i, j, cx=0;
	for(i=0;i<4;i++)
	{
		cx = (inparr[i][0]=='x') + (inparr[i][1]=='x') + (inparr[i][2]=='x') + (inparr[i][3]=='x')
			-((inparr[i][0]=='o') + (inparr[i][1]=='o') + (inparr[i][2]=='o') + (inparr[i][3]=='o'));
		if(cx > 2)
			victory++;
		if(cx < -2)
		{
			oppos_victory++;
			for(j=0; j<4; j++)
			{
				if(inparr[i][j] == '.') break;
			}
			oppos_x = i;
			oppos_y = j;
		}
	}
	for(i=0;i<4;i++)
	{
		cx = (inparr[0][i]=='x') + (inparr[1][i]=='x') + (inparr[2][i]=='x') + (inparr[3][i]=='x')
			-((inparr[0][i]=='o') + (inparr[1][i]=='o') + (inparr[2][i]=='o') + (inparr[3][i]=='o'));
		if(cx>2)
			victory++;
		if(cx < -2)
		{
			oppos_victory++;
			for(j=0; j<4; j++)
			{
				if(inparr[j][i] == '.') break;
			}
			oppos_x = j;
			oppos_y = i;
		}
	}
	cx = (inparr[0][0]=='x') + (inparr[1][1]=='x') + (inparr[2][2]=='x') + (inparr[3][3]=='x')
		-((inparr[0][0]=='o') + (inparr[1][1]=='o') + (inparr[2][2]=='o') + (inparr[3][3]=='o'));
	if(cx>2)
		victory++;
	if(cx<-2)
	{
		oppos_victory++;
		for(i=0,j=0; j<4; i++,j++)
		{
			if(inparr[i][j] == '.') break;
		}
		oppos_x = i;
		oppos_y = j;
	}
	cx = (inparr[0][3]=='x') + (inparr[1][2]=='x') + (inparr[2][1]=='x') + (inparr[3][0]=='x')
		-((inparr[0][3]=='o') + (inparr[1][2]=='o') + (inparr[2][1]=='o') + (inparr[3][0]=='o'));
	if(cx>2)
		victory++;
	if(cx<-2)
	{
		oppos_victory++;
		for(i=0,j=3; i<4; i++,j--)
		{
			if(inparr[i][j] == '.') break;
		}
		oppos_x = i;
		oppos_y = j;
	}
}

int main()
{
	int i,j,l,m;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			arr1[i][j]=arr2[i][j]=arr3[i][j]=arr4[i][j]=0;

	for(;;)
	{
		cin>>ch;
		if(ch=='$') return 0;
		
		victory = 0;
		countx = 0;
		oppos_victory = 0;
		all3 = false;
		oppos_x = oppos_y = -1;

		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				//arr1[4][4]=arr2[4][4]=arr3[4][4]=arr4[4][4]=0;
				cin>>inparr[i][j];
				if(inparr[i][j]=='x')
				{
					countx++;
				}//if(inparr[i][j]=='x')
			}//for j
		}//for i

		//print the result
		if(countx < 3)
			cout<<"#####"<<endl;
		else
		{
			check();
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(inparr[i][j] == '.' && victory > 1)
						break;
				}
				if(inparr[i][j] == '.' && victory > 1) break;
			}
			l=i; m=j;

			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(inparr[i][j] == '.')
					{
						inparr[i][j] = 'x';
						check4all3();
						inparr[i][j] = '.';
					}
					if(all3) break;
				}
				if(all3) break;
			}
			
/*
			if(victory>1 && oppos_victory == 0)
				cout<<"("<<i<<","<<j<<")"<<endl;
			else if(victory>1 && oppos_victory > 0)
			{
				if(i<oppos_x || (i == oppos_x && j<=oppos_y))
					cout<<"("<<i<<","<<j<<")"<<endl;
				else
					cout<<"("<<oppos_x<<","<<oppos_y<<")"<<endl;
			}
*/
			if(victory>1 && oppos_victory == 0)
				cout<<"("<<l<<","<<m<<")"<<endl;
			else if((victory>1 || all3) && oppos_victory > 0)
			{
				if(all3)
						cout<<"("<<i<<","<<j<<")"<<endl;
					else
						cout<<"("<<l<<","<<m<<")"<<endl;
				/*
				if(all3)
					cout<<"("<<i<<","<<j<<")"<<endl;
				else if(l<oppos_x || (l == oppos_x && m<=oppos_y))
					cout<<"("<<l<<","<<m<<")"<<endl;
				else
					cout<<"("<<oppos_x<<","<<oppos_y<<")"<<endl;
				*/
					//cout<<"("<<l<<","<<m<<")"<<endl;
			}
			else
			{
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
					{
						if(inparr[i][j] == '.')
						{
							inparr[i][j] = 'x';
							check();
							inparr[i][j] = '.';
						}
						if(victory>1) break;
					}
					if(victory>1) break;
				}



				l=i; m=j;

				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
					{
						if(inparr[i][j] == '.')
						{
							inparr[i][j] = 'x';
							check4all3();
							inparr[i][j] = '.';
						}
						if(all3) break;
					}
					if(all3) break;
				}
/*
				if(victory>1 && oppos_victory==0)
					cout<<"("<<l<<","<<m<<")"<<endl;
				else if(all3)
					cout<<"("<<i<<","<<j<<")"<<endl;
				else
					cout<<"#####"<<endl;
*/
				if(victory>1 && oppos_victory == 0)
					cout<<"("<<l<<","<<m<<")"<<endl;
				else if((victory>1 || all3) && oppos_victory > 0)
				{
					if(all3)
						cout<<"("<<i<<","<<j<<")"<<endl;
					else
						cout<<"("<<l<<","<<m<<")"<<endl;
				}
				else cout<<"#####"<<endl;

			}			
		}
	

	}//forever

	return 0;
}

/*
inp
==========
?
x.o.
.x.o
..xo
.xo.
?
x.o.
.x..
o.xo
.xo.
?
x...
ox.o
..xo
.xo.
?
x...
x...
x...
.ooo
?
o...
.oxx
.xxx
.ooo
?
....
.xo.
.ox.
....
?
o...
.ox.
.xxx
xooo
?
x..o
....
....
o..x
?
xx.x
ooo.
....
....
?
.ooo
xxx.
....
....
?
.ooo
xxxo
xox.
....
?
.ooo
xxxo
x...
....
?
..xx
.xxx
.x..
.ooo
?
ooo.
xxx.
.x..
x...
? 
oxx. 
xoo. 
xxo. 
....
?
ox.o
xo..
xo..
oxxo
?
x...
.xo.
.ooo
.xxo
$
=============

ouput:
===============
(0,1)
(0,1)
(0,1)
(3,0)
(2,0)
#####
(0,1)
#####
(0,2)
(1,3)
(0,0)
#####
(1,0)
(0,3)
(0,3)
(0,2)
(0,1)
*/