#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

#define MAXVAL 999999

vector< pair< pair<int,int>, pair<int,int> > > vec_planes1, vec_planes2;

void insert_plane(int n, vector< pair< pair<int,int>, pair<int,int> > > *vecp_planes)
{
	int a, b;
	for(int i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			if(i == 0)
			{
				startx = a;
				starty = b;
			}
			else
			{
				if((startx != a && starty != b)) //changed direction. new plane
				{
					vecp_planes->push_back( make_pair( make_pair(startx,starty), make_pair(prevx,prevy) ) );
					startx = prevx;
					starty = prevy;
				}
				if(i == n-1)
				{
					vecp_planes->push_back( make_pair( make_pair(startx,starty), make_pair(a,b) ) );
					pair<int, int> xy1 = vecp_planes->begin()->first;
					pair<int, int> xy2 = vecp_planes->begin()->second;
					if(xy1.first == a) //vertical line
					{
						if(xy2.first == a) //both are same plane
						{
							vecp_planes->push_back( make_pair( make_pair(startx,starty), xy2 ) );
						}
						else
						{
							vecp_planes->push_back( make_pair( make_pair(a,b), xy1 ) );
						}
					}
					else if(xy1.second == b) //horizontal line
					{
						if(xy2.second == b) //both are same plane
						{
							vecp_planes->push_back( make_pair( make_pair(startx,starty), xy2 ) );
						}
						else
						{
							vecp_planes->push_back( make_pair( make_pair(a,b), xy1 ) );
						}
					}
				}
			}

			prevx = a;
			prevy = b;
		} //end of for loop
}

int main()
{
	int distx, disty, minx1, minx2, miny1, miny2, maxx1, maxx2, maxy1, maxy2, i, j, a, b, n, 
		initx, inity, prevx, prevy, startx, starty;

	for(;;)
	{
		minx1 = minx2 = miny1 = miny2 = MAXVAL;
		maxx1 = maxx2 = maxy1 = maxy2 = 0;

		scanf("%d", &n);
		if(0 == n) return 0;
		//prevx = prevy = -1;
		vec_planes1.clear();
		vec_planes2.clear();

		for(i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			if(i == 0)
			{
				initx = a;
				inity = b;
				startx = a;
				starty = b;
			}
			else
			{
				if((startx != a && starty != b)) //changed direction. new plane
				{
					vec_planes1.push_back( make_pair( make_pair(startx,starty), make_pair(prevx,prevy) ) );
					startx = prevx;
					starty = prevy;
				}
				if(i == n-1)
				{
					vec_planes1.push_back( make_pair( make_pair(startx,starty), make_pair(a,b) ) );
					pair<int, int> xy1 = vec_planes1.begin()->first;
					pair<int, int> xy2 = vec_planes1.begin()->second;
					if(xy1.first == a) //vertical line
					{
						if(xy2.first == a) //both are same plane
						{
							vec_planes1.push_back( make_pair( make_pair(startx,starty), xy2 ) );
						}
						else
						{
							vec_planes1.push_back( make_pair( make_pair(a,b), xy1 ) );
						}
					}
					else if(xy1.second == b) //horizontal line
					{
						if(xy2.second == b) //both are same plane
						{
							vec_planes1.push_back( make_pair( make_pair(startx,starty), xy2 ) );
						}
						else
						{
							vec_planes1.push_back( make_pair( make_pair(a,b), xy1 ) );
						}
					}
				}
			}

			if(a<minx1) minx1 = a;
			else 
				if(a>maxx1) maxx1 = a;

			if(b<miny1) miny1 = b;
			else 
				if(b>maxy1) maxy1 = b;

			prevx = a;
			prevy = b;
		} //end of for loop

		scanf("%d", &n);
		//if(0 == n) return 0;

		for(i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);

			if(i == 0)
			{
				initx = a;
				inity = b;
				startx = a;
				starty = b;
			}
			else
			{
				if((startx != a && starty != b) || (i == n-1)) //changed direction. new plane
				{
					if(i == n-1)
					{
						pair<int, int> xy1 = vec_planes2.begin()->first;
						pair<int, int> xy2 = vec_planes2.begin()->second;
						if(xy1.first == a) //vertical line
						{
							if(xy2.first == a) //both are same plane
							{
								vec_planes2.push_back( make_pair( make_pair(startx,starty), xy2 ) );
							}
							else
							{
								vec_planes2.push_back( make_pair( make_pair(a,b), xy1 ) );
							}
						}
						else if(xy1.second == b) //horizontal line
						{
							if(xy2.second == b) //both are same plane
							{
								vec_planes2.push_back( make_pair( make_pair(startx,starty), xy2 ) );
							}
							else
							{
								vec_planes2.push_back( make_pair( make_pair(a,b), xy1 ) );
							}
						}
					}
					else
					{
						vec_planes2.push_back( make_pair( make_pair(startx,starty), make_pair(prevx,prevy) ) );
						startx = prevx;
						starty = prevy;
					}
				}
			}

			if(a<minx2) minx2 = a;
			else 
				if(a>maxx2) maxx2 = a;

			if(b<miny2) miny2 = b;
			else 
				if(b>maxy2) maxy2 = b;

			prevx = a;
			prevy = b;
		} //end of for loop

		if((minx1>=minx2 && minx1<=maxx2) || (maxx1>=minx2 && maxx1<=maxx2))
			distx = 0;
		else
		{
			if(maxx1<minx2)
				distx = minx2-maxx1;
			else
				distx = minx1-maxx2;
		}

		if((miny1>=miny2 && miny1<=maxy2) || (maxy1>=miny2 && maxy1<=maxy2))
			disty = 0;
		else
		{
			if(maxy1<miny2)
				disty = miny2-maxy1;
			else
				disty = miny1-maxy2;
		}

		if(distx|disty == 0) distx = 1;
		printf("%d\n", distx+disty);

	}

	return 0;
}