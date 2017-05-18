#include "stdio.h"
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <iostream>     // std::cout
using namespace std;

bool mf_l2h(int i,int j) { return (i<j); }
bool mf_h2l(int i,int j) { return (i>j); }

int main()
{
	unsigned long long int num, rev_num, max_num, min_num, dif, div;
	int arr[100], min_arr[100], max_arr[100], i, min, max;
	bool contain0 = false;

	while(scanf("%lld", &num)==1)
	{
		rev_num = 0;
		min_num = num;
		i=0;
		contain0 = false;
		min = 9;
		max = 1;
		while(num)
		{
			rev_num = rev_num*10 + num%10;
			arr[i] = num%10;
			if(arr[i])
			{
				if(min>arr[i]) min = arr[i];
				if(max<arr[i]) max = arr[i];
			}
			else contain0=true;
			i++;
			num /= 10;
		}
		
		vector<int> myvector (arr, arr+i); 
		// using default comparison (operator <):
		//sort (myvector.begin(), myvector.begin()+i);
		// using function as comp
		sort (myvector.begin(), myvector.end(), mf_l2h);
		i=0;
		min_num = 0;
		for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		{
			//std::cout << ' ' << *it;
	
			if(contain0 && 0==i)
				min_num = min;
			if(contain0 && (min==*it))
			{
				min_arr[i] = 0;
				min_arr[0] = min;
				contain0=false;
			}
			else  min_arr[i] = *it;

			if(contain0 && 0==i)
				min_num = min;
			else
				min_num  = min_num*10 + min_arr[i];
			i++;
		}
		sort (myvector.begin(), myvector.end(), mf_h2l);
		max_num = 0;
		for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		{
			max_num  = max_num*10 + *it;
			
		}
/*
		max_num = rev_num;
		if(min_num>rev_num)
		{
			max_num = min_num;
			min_num = rev_num;
		}
	*/
		dif = (max_num-min_num);
		div = dif/9;
		printf("%lld - %lld = %lld = 9 * %lld\n", max_num, min_num, dif, div);
	}
	return 0;
}