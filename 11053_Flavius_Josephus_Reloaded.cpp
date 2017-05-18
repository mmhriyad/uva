//normal approach
//use Pollard's rho algorithm/ or cycle detection algorithm

#include <iostream>
#include <set>
using namespace std;

#define getnext(x) (((((a%n)*((x*x)%n))%n) + b)%n)

int main ()
{
  set<long long int> myset;
  set<long long int>::iterator it;

  long long int n, x=0,y, a, b, count, begin;  

  for(;;)
  {
	  cin>>n;
	  myset.clear();
	  count=0;
	  
	  if(n == 0) return 0;
	  cin>>a>>b;
	  x = 0;
	  myset.insert(x);
	  begin=-1;
	  
	  for(;;)
	  {
		  y = x;
		  x = getnext(y);

		  it = myset.find(x);
		  if(it != myset.end())
		  {
			  if(*it == begin) break;
			  
			  if(begin == -1)
				  begin = *it;
			  count++;
		  }
		  else
		  {
			myset.insert(x);
		  }

	  }
	  cout<<n-count<<endl;
  }


  return 0;
}

  // set some initial values:
  //for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50
/*
  it=myset.find(20);
  myset.erase (it);
  myset.erase (myset.find(40));

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  */