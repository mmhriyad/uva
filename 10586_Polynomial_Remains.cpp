#include <iostream>
using namespace std;

int main()
{
	int arr[100000];
	int i,j,n,k;
	for(;;)
	{
		cin>>n>>k;
		if(n == -1 && k == -1) return 0;
		for(i=1; i<=n+1; i++)
		{
			cin>>arr[i];
		}
		for(i=n+1; (i>1 && i>k); i--)
		{
			if(arr[i])
			{
				arr[(i-k)] -= arr[i];
				arr[i] = 0;
			}
		}
		//cout<<"======= ";
		j=i;
		if(k==0)
			cout<<"0";
		else
		{
			for(i=1; i<=j; i++)
			{
				if(arr[i])
				{
					cout<<arr[i];
					if(i<j)
						cout<<" ";
				}

			}
		}
		cout<<endl;
	}
}