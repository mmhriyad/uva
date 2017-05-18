#include <stdio.h>
#include <math.h>

typedef long long int lli;

//0.000
void get_pos2(lli startx, lli starty, lli *x, lli *y, lli val, lli len)
{
	lli cur_val = len*len;
	bool found;
	lli i, limit, start;
	if (val == cur_val)
	{
		*x = startx;
		*y = starty;
		return;
	}

	if (startx == starty) // odd
	{
		start = (len * len) + 1;
		limit = start + len;
		if (val >= start && val <= limit)
		{
			*y = starty - (val - start);
			*x = startx + 1;
			return;
		}
		else
		{
			start = (len * len) + len + 2;
			*x = startx - (val - start);
			*y = starty - len;
			return;
		}
	}
	else //even
	{
		start = (len * len) + 1;
		limit = start + len;
		if (val >= start && val <= limit)
		{
			*y = starty + (val - start);
			*x = startx - 1;
			return;
		}
		else
		{
			start = (len * len) + len + 2;
			*x = startx + (val - start);
			*y = starty + len;
			return;
		}
	}
}
//0.089 sec
void get_pos(lli startx, lli starty, lli *x, lli *y, lli val, lli len)
{
	lli cur_val = len*len;
	bool found;
	lli i, limit, start;
	if (val == cur_val)
	{
		*x = startx;
		*y = starty;
		return;
	}
	
	if (startx == starty) // odd
	{
		len += 2;
		found = false;
		//move left
		start = starty;
		limit = start - len + 1;
		for (i = start; i > limit; --i)
		{
			++cur_val;
			if (cur_val == val)
			{
				*y = i;
				*x = startx + 1;
				return;
			}
		}
		//move down
		start = startx;
		limit = start - len;
		for (i = start; i > limit; --i)
		{
			++cur_val;
			if (cur_val == val)
			{
				*y = starty - len + 2;
				*x = i;
				return;
			}
		}
	}
	else //even
	{
		len += 1;		
		//move right
		start = starty;
		limit = start + len;
		for (i = start; i < limit; ++i)
		{
			++cur_val;
			if (cur_val == val)
			{
				*y = i;
				*x = startx - 1;
				return;
			}
		}
		//move up
		start = startx;
		limit = start + len;
		for (i = start; i < limit; ++i)
		{
			++cur_val;
			if (cur_val == val)
			{
				*y = starty + len - 1;
				*x = i;
				return;
			}
		}
	}
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	lli N, P, pos, limit;
	lli x, y, resx, resy;
	
	while (scanf("%lld %lld", &N, &P) == 2)
	{
		if (N == 0 && P == 0)
			return 0;
		pos = (lli)sqrt((long double)P);

		resx = resy = 0;
		if (pos & 1) // odd
		{
			x = y = pos + (N - pos) / 2;
		}
		else
		{
			y = 1 + (N - pos - 1) / 2;
			x = y + 1;
		}

		resx = resy = 0;
		get_pos2(x, y, &resx, &resy, P, pos);

		printf("Line = %lld, column = %lld.\n", resx, resy);

	}
	return 0;
}