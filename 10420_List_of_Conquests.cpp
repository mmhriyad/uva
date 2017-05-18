#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>


using namespace std;

bool myfunction (string i,string j) 
{
	if(i.compare(j) < 0)
		return false;
	else return true; 
}


int main()
{	
	vector<string> v;
	string str;
	char name[80];
	int N, i;

	//freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for(i=0; i<N; i++)
	{
		cin >> str;
		v.push_back(str);
		//getchar();
		gets(name);
		//cout <<"country: "<<str<<", name: "<<name<<endl;
	}
	sort(v.begin(), v.end());
	int size = v.size(), count = 0;
	
	for(i = 0; i<size-1; i++)
	{
		if(v[i].compare(v[i+1]) == 0)
		{
			count++;
		}
		else
		{
			cout << v[i] << " " << count+1 << endl;
			count = 0;
		}
	}
	cout << v[i] << " " << count+1 << endl;
		
}