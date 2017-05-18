#include <iostream>

using namespace std;

#define MAX 21

#define GETMAX(x,y) (x>y ? x : y)

int arr[MAX];
char taken[MAX];

int avg, n;

int visit(int i, int sum)
{
	if(!taken[i])
	{
		if(arr[i]+sum <= avg)
		{
			taken[i] = 1;
			sum += arr[i];
			if(sum == avg)
				return 1;
			else if(i+1<n)
				visit(i+1, sum);
			else return 0;
		}
	}
	else if(i+1<n)
		visit(i+1, sum);
	else return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, sum, maxn, i, count, a;

	cin >> T;
	while(T--)
	{
		cin >> n;
		sum = 0;
		avg = 0;
		maxn = 0;
		
		for(i=0; i<n; i++)
		{
			cin >> a;
			sum += a;
			maxn = GETMAX(maxn, a);
			arr[i] = a;
			taken[i] = 0;
		}
		
		avg = sum / 4;

		if((sum%4 != 0) || (avg < maxn) || n<4)
		{
			cout << "no" << endl;
		}
		else
		{
			count = 0;
			for(i=0; i<n; i++)
			{
				count += visit(i, 0);
			}
			
			if(count >= 4)
				cout << "yes" <<endl;
			else
				cout << "no" <<endl;

		}

	}
	return 0;
}