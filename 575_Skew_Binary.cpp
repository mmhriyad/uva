#include <iostream>
#include "string.h"
//#include "math.h"
using namespace std;

int main()
{
	char arr[1000];
	unsigned int sum, i, len;
	
	for(;;)
	{
		cin>>arr;
		len = strlen(arr);
		if(len == 1 && arr[0] == '0') return 0;

		sum = 0;
		for(i=0; i<len; i++)
		{
			if(arr[i]-'0')
				sum += (arr[i]-'0')*((unsigned int)(1<<(len-i)) - 1);
				//sum += (arr[i]-'0')*((unsigned int)pow(2.0, (double)(len-i)) - 1);
			if(arr[i] == '2')
				break;
		}
		
		cout<<sum<<endl;

	}
	return 0;
}