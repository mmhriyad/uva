//10459 - The Tree Root
//Author : Md. Mahbubul Huq (Riyad)

#include <stdio.h>
#include <malloc.h>

#define MAX 5001

typedef struct node {
	int val;
	int nchilds;
	int tmp_nchilds;
	int* childs;
	bool visited;
	int depth;
	bool is_worst;
}node;

node nodes[MAX];
int N;

int max_path_len;
int worst[MAX];
int worst_len;

void dfs(int root, int path_len)
{
	nodes[root].visited = true;
	
	if (max_path_len == path_len) {
		/*worst[worst_len++] = root;*/
		nodes[root].is_worst = true;
	}

	int i;
	for (i = 0; i < nodes[root].nchilds; ++i) {
		if (nodes[nodes[root].childs[i]].visited == false) {
			dfs(nodes[root].childs[i], path_len + 1);
		}
	}
}

int Q[MAX];
int q_front;
int q_rear;

void init_Q()
{
	q_front = q_rear = 0;
}

void enQ(int val)
{
	Q[q_rear++] = val;
	if (q_rear >= MAX)
		q_rear = 0;
}

int deQ()
{
	int tmp = Q[q_front++];
	if (q_front >= MAX)
		q_front = 0;
	if (q_front == q_rear)
		init_Q();
	return tmp;
}

bool is_empty_Q()
{
	return (q_front == q_rear);
}

void init_visited()
{
	for (int i = 1; i <= N; ++i)
		nodes[i].visited = false;
}

void print_best_worst()
{
	int bests[2];
	int best_count = 0;
	int added = 0;
	init_Q();

	for (int i = 1; i <= N; ++i) {
		if (nodes[i].tmp_nchilds == 1) {
			nodes[i].tmp_nchilds--;
			nodes[i].depth = 1;
			enQ(i);
			++added;
		}
	}
	max_path_len = 1;
	
	while (is_empty_Q() == false) {
		int root = deQ();
		
		for (int j = 0; j < nodes[root].nchilds; ++j) {
			int child = nodes[root].childs[j];
			nodes[child].tmp_nchilds--;
			if (nodes[child].tmp_nchilds == 1) {
				enQ(child);
				++added;
				nodes[child].depth = nodes[root].depth + 1;
				max_path_len = nodes[child].depth;
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (nodes[i].depth == max_path_len)
			bests[best_count++] = i;
	}
	//++max_path_len;

	printf("Best Roots  : ");
	if (best_count == 2) {
		++max_path_len;
		if (bests[0] > bests[1]) {
			int tmp = bests[0];
			bests[0] = bests[1];
			bests[1] = tmp;
		}

		printf("%d %d\n", bests[0], bests[1]);
		dfs(bests[0], 1);
		init_visited();
		dfs(bests[1], 1);
	}
	else {
		printf("%d\n", bests[0]);
		dfs(bests[0], 1);
	}

	printf("Worst Roots :");
	for (int i = 0; i < worst_len; ++i) {
		if (nodes[worst[i]].is_worst)
			printf(" %d", worst[i]);
	}
	printf("\n");
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i;
	int j;
	int n;
	while (scanf("%d", &N) == 1) {
		
		worst_len = 0;
		max_path_len = 0;
		for (i = 1; i <= N; ++i) {
			scanf("%d", &n);
			nodes[i].nchilds = n;
			nodes[i].tmp_nchilds = n;
			nodes[i].visited = false;
			nodes[i].is_worst = false;
			if (n == 1)
				worst[worst_len++] = i;
			nodes[i].childs = (int*)malloc(sizeof(int)* n);
			
			for (j = 0; j < n; ++j) {
				scanf("%d", &nodes[i].childs[j]);
			}
		}

		print_best_worst();
	}
	return 0;
}