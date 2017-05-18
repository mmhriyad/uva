#include <iostream>
#include <string.h>

using namespace std;

unsigned int strToInt(char inp[], int start_pos, int len)
{
	unsigned int int_num = 0, i;
	for(i=start_pos; i<len; i++)
	{
		int_num = int_num*10 + (inp[i]-'0');
	}
	return int_num;
}

unsigned int count_digit_sum(char arr[], int len)
{
	int digit_sum = 0;
	for(int i=0; i<len; i++)
	{
		digit_sum += arr[i]-'0';
	}
	return digit_sum;
}

bool isDivideby2(char arr[], int len)
{
	return ((arr[len-1]-'0')%2 == 0);
}

bool isDivideby3(int digit_sum)
{
	return (digit_sum%3 == 0);
}

bool isDivideby4(char arr[], int len)
{
	int last2digits = 0, i=0;
	if(len>2)
		i=len-2;
	for(;i<len; i++)
	{
		last2digits = last2digits * 10 + (arr[i]-'0');
	}

	return (last2digits%4 == 0);
}

bool isDivideby5(char arr[], int len)
{
	return ((arr[len-1] == '0') || (arr[len-1] == '5'));
}

bool isDivideby6(char arr[], int len, int digitsum)
{
	return isDivideby3(digitsum) && isDivideby2(arr, len);
}

bool isDivideby7(char arr[], int len)
{
	int main_arr[6] = {1, 3, 2, 6, 4, 5};
	int digitsum = 0, i;
	for(i=len-1; i>=0; i--)
	{
		digitsum += ((arr[i]-'0') * main_arr[(len - i - 1)%6]);
	}

	return (digitsum%7 == 0);
}

bool isDivideby8(char arr[], int len)
{
	int last3digits = 0, i=0;
	if(len>3)
		i=len-3;
	for(;i<len; i++)
	{
		last3digits = last3digits * 10 + (arr[i]-'0');
	}

	return (last3digits%8 == 0);
}

bool isDivideby9(int digit_sum)
{
	return (digit_sum%9 == 0);
}

bool isDivideby10(char arr[], int len)
{
	return (arr[len-1] == '0');
}

bool isDivideby11(char arr[], int len)
{
	int evensum=0, oddsum=0, i;
	for(i=0; i<len; i++)
	{
		if(i%2 == 0)
			evensum += (arr[i]-'0');
		else
			oddsum += (arr[i]-'0');
	}

	return ((evensum-oddsum)%11 == 0);
}

bool isDivideby12(char arr[], int len, int digitsum)
{
	return isDivideby3(digitsum) && isDivideby4(arr, len);
}

int main()
{
	unsigned long long int N, M, num, count, len, digitsum;
	bool simple = false;

	char str_inp[20001];

	cin>>N;
	while(N)
	{
		//cin>>M;

		
		cin>>str_inp;
		len = strlen(str_inp);
		
		//digitsum = 0;
		digitsum = count_digit_sum(str_inp, len);
		M = 1;
		if(len == 1 && str_inp[0] == '0')
			M=0;
		
		cin>>count;
		simple = false;
		while(count)
		{
			cin>>num;
			if(!simple && M)
			{
				/*
				if(M%num != 0)
					simple = true;
				*/
				
				switch(num)
				{
				case 2:
					simple = !isDivideby2(str_inp, len);
					break;
				case 3:
					simple = !isDivideby3(digitsum);
					break;
				case 4:
					simple = !isDivideby4(str_inp, len);
					break;
				case 5:
					simple = !isDivideby5(str_inp, len);
					break;
				case 6:
					simple = !isDivideby6(str_inp, len, digitsum);
					break;
				case 7:
					simple = !isDivideby7(str_inp, len);
					break;
				case 8:
					simple = !isDivideby8(str_inp, len);
					break;
				case 9:
					simple = !isDivideby9(digitsum);
					break;
				case 10:
					simple = !isDivideby10(str_inp, len);
					break;
				case 11:
					simple = !isDivideby11(str_inp, len);
					break;
				case 12:
					simple = !isDivideby12(str_inp, len, digitsum);
					break;

				}
				
			}
			count--;
		}
/*
		if(simple)
			cout<<M<<" - Simple."<<endl;
		else cout<<M<<" - Wonderful."<<endl;
*/
		if(simple)
			cout<<str_inp<<" - Simple."<<endl;
		else cout<<str_inp<<" - Wonderful."<<endl;
		N--;
	}



	return 0;
}

//LCM of 1~12=27720

/*
input:
=====================
18
6213620589
1 11
16
3 2 4 8
2982752926433280000
12 1 2 3 4 5 6 7 8 9 10 11 12
8888888888
1 2
16944708
1 3
501988
1 4
6182945
1 5
7415934
1 6
87965423
1 7
45476438152
1 8
511612461
1 9
565645890
1 10
545493751068
1 12
341234612736481253489125349812643761283458123548213541273468213549821354182354891623458917245921834593218645921580
1 7
0
12 1 2 3 4 5 6 7 8 9 10 11 12
379749833583241
1 11
3909821048582988049
1 7
10
3 1 2 9

output:
====================
6213620589 - Wonderful.
16 - Wonderful.
2982752926433280000 - Wonderful.
8888888888 - Wonderful.
16944708 - Wonderful.
501988 - Wonderful.
6182945 - Wonderful.
7415934 - Wonderful.
87965423 - Wonderful.
45476438152 - Wonderful.
511612461 - Wonderful.
565645890 - Wonderful.
545493751068 - Wonderful.
341234612736481253489125349812643761283458123548213541273468213549821354182354891623458917245921834593218645921580 - Simple.
0 - Wonderful.
379749833583241 - Wonderful.
3909821048582988049 - Wonderful.
10 - Simple.
*/