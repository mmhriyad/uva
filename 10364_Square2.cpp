#include <iostream>
using namespace std;

#define MAX 21
#define GETMAX(x,y) (x>y ? x : y)

int arr[MAX], sum, avg, n, isum;

bool possible = false, taken[MAX];

int finalcount = 0;

void srch2(int parent)
{
	int i = 0;
	if(isum == avg)
	{
		finalcount++;
		if(finalcount == 4)
			possible = true;
		isum = 0;
		return;
	}


	if(isum > 0)
		i = parent+1;
	for(; i<n; i++)
	{
		if(!taken[i] && isum + arr[i] <= avg)
		{
			taken[i] = true;
			isum += arr[i];
			srch2(i);
			if(isum > 0)
			{
				taken[i] = false;
				isum -= arr[i];
			}
		}
	}

}

void srch(int step, int sum, int in, int parent = 0)
{
	printf("step [%d], sum [%d], inp [%d], parent [%d]\n", step, sum, in, parent);
	if(sum == avg*step)
	{
		if(step == 4)
		{
			possible = true;
			return;
		}
		else
			step++;
	}
	else if(sum > avg*step)
		return;

	for(int i=0; i<n; i++)
	{
		if(!taken[i])
		{
			sum += arr[i];
			taken[i] = true;
			srch(step, sum, i+1, in);
			if(possible)
				break;
			taken[i] = false;
			sum -= arr[i];

		}
	}
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
			//srch(1, 0, 0);
			finalcount = 0;
			isum =0;
			srch2(0);
			if(possible)
				cout << "yes" <<endl;
			else
				cout << "no" <<endl;

		}

	}
	return 0;
}