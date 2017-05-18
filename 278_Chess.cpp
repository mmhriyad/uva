#include <iostream>
using namespace std;

#define HALF(x) ((x&1) ? (x+1)/2 : x/2)
#define MIN(x,y) ((x>y) ? y : x)
#define MAX(x,y) ((x>y) ? x : y)

int main()
{
	freopen("input.txt", "r", stdin);
	int T, m, n;
	char c;
	
	//scanf("%d", &T);
	cin >> T;
	while(T--)
	{
		//scanf("%c %d %d", &c, &m, &n);
		cin >> c >> m >> n;
		switch(c)
		{
		case 'r':
		case 'Q':
			//printf("%d\n", MIN(m, n));
			cout << MIN(m, n);
			break;
		case 'k':
			//printf("%d\n", HALF(m*n));
			cout << HALF(m*n);
			break;
		/*case 'Q':
			printf("%d", MIN(m-1, n-1));
			break;*/
		case 'K':
			//printf("%d\n", HALF(m)*HALF(n));
			cout << HALF(m)*HALF(n);
			break;
		}
		cout << endl;
	}
	return 0;
}