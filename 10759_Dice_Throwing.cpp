#include <iostream>
using namespace std;

#define MAX 24

unsigned long long int arr[MAX+1][MAX*6+1], arr_cumul[MAX+1][MAX*6+1], arr_max_pos[MAX+1];

unsigned long long int gcd_euclid(unsigned long long int a, unsigned long long int b)
{
	if(b==0) return a;
	if(a==b) return a;
	return gcd_euclid(b, a%b);
}

int main()
{
	int i, j, k, l, n, x;
	unsigned long long int min_val, max_sum, sum, gcd;

	for(i=1; i<=MAX+1; i++)
	{
		arr[i][i] = arr[i][i*6] = arr_cumul[i][i] =  1;
		arr[i][i-1] = arr[i][i*6+1] = 0;
	}

	n=1;
	arr_cumul[1][0] = 0;
	for(i=1; i<=n*6; i++)
	{
		arr[1][i] = 1;
		arr_cumul[1][i] = arr_cumul[1][i-1]+1;
	}

	arr_max_pos[1] = 6;

	for(i=2; i<=MAX; i++)
	{
		max_sum = 0;
		for(j=i+1;j<=i*6;j++)
		{
			k = j-1;
			
			min_val = 1;
			if(k > (i-1)*6)
			{
				min_val += (k-(i-1)*6);
				k = (i-1)*6;
			}
			sum = 0;
			l=1;

			while(k+min_val == j && min_val<=6)
			{
				sum += arr[i-1][k];
				k--; 
				l++;
				min_val++;
			}
			arr[i][j] = sum;
			max_sum += sum;
			arr_cumul[i][j] = max_sum+1;

		}
		arr_max_pos[i] = max_sum + 1;
	}

	for(;;)
	{
		cin>>n>>x;
		if(n==0 && x==0) return 0;
		if(x>n*6) cout<<"0";
		else if(x<=n) cout<<"1";
		else
		{
		/*	
			max_sum = 0;
			for(i=x; i<=n*6; i++)
			{
				max_sum += arr[n][i];
			}
		*/	
			max_sum = arr_max_pos[n] - arr_cumul[n][x-1];
			gcd = gcd_euclid(max_sum, arr_max_pos[n]);
			cout<<max_sum/gcd<<"/"<<arr_max_pos[n]/gcd;
		}
		cout<<endl;
	}
	return 0;
}