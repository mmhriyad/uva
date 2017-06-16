//839 - Not so Mobile 
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>

typedef struct node {
	int w1;
	int d1;
	int w2;
	int d2;
}node;

node stack[1000];
int stack_size = 0;

void init_stack()
{
	stack_size = 0;
}

void push(int w1, int d1, int w2, int d2)
{
	stack[stack_size].d1 = d1;
	stack[stack_size].d2 = d2;
	stack[stack_size].w1 = w1;
	stack[stack_size].w2 = w2;
	++stack_size;
}

node pop()
{
	return stack[--stack_size];
}

bool is_empty_stack()
{
	return (stack_size == 0);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	int w1, w2, d1, d2;
	bool balance = true;
	bool pushed = false;
	scanf("%d", &T);
	while (T--) {
		init_stack();
		balance = true;
		do {
			scanf("%d %d %d %d", &w1, &d1, &w2, &d2);
			if (w1 == 0 || w2 == 0) {
				push(w1, d1, w2, d2);
			}
			else {
				
				do {
					if ((w1*d1 != w2*d2)) {
						balance = false;
					}
					if (is_empty_stack())
						break;
					int total_w = w1 + w2;
					node n = pop();
					if (n.w1 == 0) {
						n.w1 = total_w;
					}
					else {
						n.w2 = total_w;
					}
					
					if (n.w1 == 0 || n.w2 == 0) {
						push(n.w1, n.d1, n.w2, n.d2);
						pushed = true;
					}
					else {
						pushed = false;
						w1 = n.w1;
						w2 = n.w2;
						d1 = n.d1;
						d2 = n.d2;
					}
				} while (pushed == false);
			}
		} while (is_empty_stack() == false);

		if (balance)
			puts("YES");
		else
			puts("NO");
		if (T > 0)
			printf("\n");
	}
	return 0;
}