#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

#define MAXVAL 999999

#define GET_MIN(x,y) ( (x > y) ? y : x )

void insert_plane(int n, vector< pair< pair<int,int>, pair<int,int> > > *vecp_planes)
{
	int a, b, startx, starty, prevx, prevy;
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
	int distx, disty, minx1, minx2, miny1, miny2, maxx1, maxx2, maxy1, maxy2, i, j, a, b, n1, n2;

	vector< pair< pair<int,int>, pair<int,int> > > vec_planes1, vec_planes2;
	int size1, size2, min_dist, dist;

	for(;;)
	{
		minx1 = minx2 = miny1 = miny2 = MAXVAL;
		maxx1 = maxx2 = maxy1 = maxy2 = 0;
		distx = disty = 0;

		vec_planes1.clear();
		vec_planes2.clear();

		scanf("%d", &n1);
		if(0 == n1) return 0;

		insert_plane(n1, &vec_planes1);

		scanf("%d", &n2);
		insert_plane(n2, &vec_planes2);
		
		//process
		size1 = vec_planes1.size();
		size2 = vec_planes2.size();
		min_dist = MAXVAL;

		for(i=0; i<size1; i++)
		{
			for(j=0; j<size2; j++)
			{
				minx1 = GET_MIN( abs(vec_planes2[j].first.first - vec_planes1[i].first.first), abs(vec_planes2[j].second.first - vec_planes1[i].first.first));
				//if(minx1 < 0) minx1 = 0;
				minx2 = GET_MIN( abs(vec_planes2[j].first.first - vec_planes1[i].second.first), abs(vec_planes2[j].second.first - vec_planes1[i].second.first));
				//if(minx2 < 0) minx2 = 0;
				/*
				if((minx1<0 && minx2<0))
				{
					//do nothing
					minx1 = abs(minx1);
					minx2 = abs(minx2);
				}
				else if((minx1<0 || minx2<0))
				{
					if(minx1 < 0) minx1 = 0;
					else if(minx2 < 0) minx2 = 0;
				}
				*/

				miny1 = GET_MIN( abs(vec_planes2[j].first.second - vec_planes1[i].first.second), abs(vec_planes2[j].second.second - vec_planes1[i].first.second));
				//if(miny1 < 0) miny1 = 0;
				miny2 = GET_MIN( abs(vec_planes2[j].first.second - vec_planes1[i].second.second), abs(vec_planes2[j].second.second - vec_planes1[i].second.second));
				//if(miny2 < 0) miny2 = 0;
				/*
				if((miny1<0 && miny2<0))
				{
					miny1 = abs(miny1);
					miny2 = abs(miny2);
				}
				else if((miny1<0 || miny2<0))
				{
					if(miny1 < 0) miny1 = 0;
					else if(miny2 < 0) miny2 = 0;
				}
				*/
				dist = (GET_MIN(minx1, minx2)) + (GET_MIN(miny1, miny2));

				if(dist < min_dist)
					min_dist = dist;
			}
		}

		printf("%d\n", min_dist);

	}

	return 0;
}