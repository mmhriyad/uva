//10502 Counting Rectangle

#include <stdio.h>

#define MAX 101
#define MIN(x, y) (x < y ? x : y)

typedef struct
{
	char val;
	long long int up, left, sqr, total;
}s_array;

s_array arr[MAX][MAX];
int R, C;

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j, val, k, n;
	char inp[MAX + 1];
	long long int total;
	while (scanf("%d", &R) == 1) {
		scanf("%d", &C);
		if (R == 0 || C == 0)
			break;
		gets(inp);
		total = 0;
		for (i = 0; i < R; ++i) {
			gets(inp);
			for (j = 0; j < C; ++j) {
				val = inp[j] - '0';
				arr[i][j].val = val;
				arr[i][j].left = 0;
				arr[i][j].up = 0;
				arr[i][j].sqr = 0;
				arr[i][j].total = 0;
				if (val) {
					if (j > 0 && arr[i][j - 1].val > 0)
						arr[i][j].left = arr[i][j - 1].left + 1;
					if (i > 0 && arr[i - 1][j].val > 0)
						arr[i][j].up = arr[i - 1][j].up + 1;
					if ((j > 0 && arr[i][j - 1].val > 0) && (i > 0 && arr[i - 1][j].val > 0)) {

						int min_left = arr[i][j].left;
						int min_up = arr[i][j].up;
						int left_sum = 0;
						int up_sum = 0;
						for (k = i - 1; k >= 0; --k) {
							min_left = MIN(min_left, arr[k][j].left);
							left_sum += min_left;
						}
						/*for (k = j - 1; k >= 0; --k) {
							min_up = MIN(min_up, arr[i][k].up);
							if (min_up > 0)
								up_sum += (min_up - 1);
						}*/

						arr[i][j].sqr = left_sum + up_sum;
						//arr[i][j].sqr = min_left * min_up;
						//arr[i][j].sqr = MIN(arr[i - 1][j].left, arr[i][j].left) * MIN(arr[i][j - 1].up, arr[i][j].up);
					}

					arr[i][j].total = arr[i][j].sqr + arr[i][j].left + arr[i][j].up + 1;
					total += arr[i][j].total;
				}
			}
		}

		printf("%lld\n", total);
	}
}