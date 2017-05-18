#include "stdio.h"

int main()
{
	long long int row, col, max_len, min_len;

	long long int rook_moves, bishop_moves, queen_moves;
	long long int i;

	for(;;)
	{
		rook_moves = 0;
		bishop_moves = 0;
		queen_moves = 0;

		scanf("%lld %lld", &row, &col);
		if(0 == row || 0 == col)
			return 0;

		max_len = (row > col) ? row : col;
		min_len = (row < col) ? row : col;
		//calculating rook moves [straight]
		rook_moves = row * col * ( row + col - 2); //mn(n+m-2)
		//calculating bishop moves [diagonal]
		bishop_moves = 0;
		/*
		for(i = 1; i<min_len; i++)
		{
			bishop_moves += 4 * (col - i) * (row - i);
		}
		*/
		if(min_len > 1)
		{
			i = min_len-1;
			bishop_moves = 4 * ( (col*row)*(i) - (i*(i+1)/2)*(col+row) + ((i*(i+1)*(2*i+1))/6) ); 
		}
		queen_moves = bishop_moves + rook_moves;

		printf("%lld\n", queen_moves);
	}
	
}

/*
row= n
col= m
min_len = (m<n) ? m : n;
min_len = (m>n) ? m : n;
----------
rook(boat) check pos:
number of straight check in a row: mn(n-1)
number of straight check in a col: mn(m-1)
total number of straight check : mn(n+m-2)
---------
bishop (elephant) check pos:
for(i=1 to min_height-1)
	total_moves += (max_len-i)(max_len-i+1)
--------
queen (minister) check pos: rook+bishop
--------
*/
