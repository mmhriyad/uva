//using Pollard's rho algorithm/ or cycle detection algorithm

#include <iostream>
using namespace std;

#define getnext(x) (((((a%n)*((x*x)%n))%n) + b)%n)

int main ()
{
  long long int n, x=0, y, a, b, count, begin;  

  for(;;)
  {
	  cin>>n;
	  
	  count=0;
	  
	  if(n == 0) return 0;
	  cin>>a>>b;
	  x = 0;
	  y = 0;
	  
	  begin=-1;
	  
	  for(;;)
	  {
		  x = getnext(x);
		  y = getnext(getnext(y));

		  if(begin >= 0)
			count++;

		  if(x == y) //loop exists
		  {
			  if(x == begin) break;
			  if(begin<0)
				  begin = x;
		  }
	  }
	  cout<<n-count<<endl;
  }
  return 0;
}
