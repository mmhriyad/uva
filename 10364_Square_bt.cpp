#include <iostream>
using namespace std;

#define MAX 21
#define GETMAX(x,y) (x>y ? x : y)

int arr[MAX], sum, avg, n, isum;

bool possible = false, taken[MAX];

bool ispossible(int i, int csum, int len)
{
	if(len == 4)
		return true;
	if(csum == avg) 
		return ispossible(0, 0, len+1);
	if(i >= n)
		return false;
	if(!taken[i] && csum+arr[i] <= avg)
	{
		taken[i] = true;
		
		if(ispossible(i+1, csum+arr[i], len))
			return true;

		taken[i] = false;
	}
	return ispossible(i+1, csum, len);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, maxn, i, count, a, countb;


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
			taken[i] = false;
		}
		
		avg = sum / 4;

		if((sum%4 != 0) || (avg < maxn) || n<4)
		{
			cout << "no" << endl;
		}
		else
		{
			count = countb = 0;
			possible = false;
			
			if(ispossible(0, 0, 0))
				cout << "yes" <<endl;
			else
				cout << "no" <<endl;

		}

	}
	return 0;
}