#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 22
#define MAXVAL 50002
#define GETMAX(x,y) (x>y ? x : y)

int sum, avg, n;
int arrdp[MAXVAL][MAX];
int way[MAXVAL];

vector<int> inp;

int findindex(int val)
{
	int i, sum=0;
	for(i=0; i<=n; i++)
	{
		sum+=inp[i];
		if(sum >= val)
			return i;
	}
	return i-1;
}

void dp2()
{
	int i, j, start;
	way[0] = 1;

	for(i=1; i<=n; i++)
	{
		for(j=0; j>=inp[i]; j++)
			way[j] += way[j-inp[i]];
	}
}

void dp()
{
	int i,j, sum;
	for(i=0; i<=n; i++)
		arrdp[0][i] = 1;
	for(i=1; i<=avg; i++)
	{
		sum = 0;
		for(j=0; j<=n; j++)
		{
			if(j == 0)
				arrdp[i][j] = 0;
			else if(inp[j] > i)
				arrdp[i][j] = arrdp[i][j-1];
			else
			{
				sum += inp[j];
				if(sum < i)
					arrdp[i][j] = 0;
				else
				{
					int a = arrdp[i][j-1];
					int b = arrdp[i-inp[j]][j-1];
					int c = arrdp[i][findindex(sum-i)];
					arrdp[i][j] = GETMAX(arrdp[i][j-1], ((arrdp[i-inp[j]][j-1]>0 ? 1 : 0) + arrdp[i][findindex(sum-i)]));
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int T, maxn, i, j, a;


	cin >> T;
	while(T--)
	{
		cin >> n;
		sum = 0;
		avg = 0;
		maxn = 0;
		inp.clear();
		inp.push_back(0);

		for(i=0; i<n; i++)
		{
			cin >> a;
			sum += a;
			maxn = GETMAX(maxn, a);
			
			inp.push_back(a);
		}
		
		avg = sum / 4;

		if((sum%4 != 0) || (avg < maxn) || n<4)
		{
			cout << "no" << endl;
		}
		else if(avg == 0)
			cout << "yes" << endl;
		else
		{
			sort(inp.begin(), inp.end());
			for(i=0; i<=avg; i++)
				for(j=0; j<=n; j++)
					arrdp[i][j] = 0;
			dp();
			if(arrdp[avg][n] == 4)
				cout << "yes" <<endl;
			else
				cout << "no" <<endl;

		}

	}
	return 0;
}