#include <iostream>
using namespace std;

int main()
{
	unsigned int num, count, i;
	char arr[1000];
	for(;;)
	{
		cin>>num;
		if(num == 0) return 0;
		i=0;
		count = 0;
		/*
		itoa (num, arr, 2);

		while(arr[i])
		{
			if(arr[i] == '1') 
				count++;
			i++;
		}
		cout<<"The parity of "<<arr<<" is "<<count<<" (mod 2)."<<endl;
		*/
		
		
		while(num)
		{
			arr[i] = num%2 + '0';
			if(num%2) count++;
			num /= 2;
			i++;
		}
		
		cout<<"The parity of ";
		
		while(i)
		{
			cout<<arr[--i];
		}
		cout<<" is "<<count<<" (mod 2)."<<endl;
		
	}
	return 0;
}