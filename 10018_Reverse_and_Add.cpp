//10018 - Reverse and Add
#include <stdio.h>

typedef long long int lli;

bool is_palindrome(lli a, lli *out)
{
	lli rev = 0, div;
	lli tmp = a;
	while (tmp) {
		div = tmp % 10;
		rev = rev * 10 + div;
		tmp /= 10;
	}
	*out = rev;
	return (rev == a);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	lli ans = 4294967295, P, rev;
	int N, it;
	scanf("%d", &N);

	while (N--) {
		scanf("%lld", &P);
		is_palindrome(P, &rev);
		P += rev;
		it = 1;
		while (is_palindrome(P, &rev) == false) {
			P += rev;
			++it;
		}
		printf("%d %lld\n", it, P);
	}

	return 0;
}