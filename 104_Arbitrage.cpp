#include <iostream>
using namespace std;

int main()
{
	for(;;)
	{
		int n, i, j, k;
		float rate[21][21], r;
		int prev[21][21];
		cin>>n;
		//while(n--)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					prev[i][j] = 0;
					if(i == j)
					{
						rate[i][j] = 1;
					}
					else
					{
						cin>>r;
						rate[i][j] = r;
					}
				}
			}
		}
		float max = 1;
		
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					if(rate[i][j] < rate[i][k]*rate[k][j])
					{
						rate[i][j] = rate[i][k]*rate[k][j];

						prev[i][j] = k;

						if((i == j) && (max < rate[i][j]))
						{
							max = rate[i][j];
						}
					}
				} //j
			}//i
		}//k

		if(max>1)
		{
			cout<<"exists"<<endl;
		}
		else
			cout<<"no arbitrage sequence exists"<<endl;

	}
}
