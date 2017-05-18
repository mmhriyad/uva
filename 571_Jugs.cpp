//571 - Jugs
#include <stdio.h>

#define GET_MIN(x, y) (x < y ? x : y)

typedef enum {
	OPERATION_NONE,
	OPERATION_POUR1,
	OPERATION_POUR2,
	OPERATION_EMPTY1,
	OPERATION_EMPTY2,
	OPERATION_POUR1_2,
	OPERATION_POUR2_1
}e_operations;

typedef struct{
	int jug1, jug2;
	int op;
	int parent, id;
}s_jug;

#define MAX 1001

s_jug q_jug[MAX*2];
bool visited[MAX][MAX];

int front, end;

void init_q()
{
	front = end = 0;
	int i, j;
	for (i = 0; i < MAX; ++i)
	{
		for (j = 0; j < MAX; ++j)
		{
			visited[i][j] = false;
		}
	}
}

void enque(s_jug item)
{
	if (visited[item.jug1][item.jug2])
		return;
	q_jug[end].jug1 = item.jug1;
	q_jug[end].jug2 = item.jug2;
	q_jug[end].parent = item.parent;
	q_jug[end].op = item.op;
	q_jug[end].id = end;
	visited[item.jug1][item.jug2] = true;
	++end;
}

s_jug* deque()
{
	s_jug *item = &q_jug[front];
	++front;
	return item;
}

bool is_empty_q()
{
	return (front == end);
}

int max_jug1, max_jug2, target;

void print_path(int id)
{
	if (id > 0)
	{
		print_path(q_jug[id].parent);
		switch (q_jug[id].op)
		{
		case OPERATION_EMPTY1:
			printf("empty A");
			break;
		case OPERATION_EMPTY2:
			printf("empty B");
			break;
		case OPERATION_POUR1:
			printf("fill A");
			break;
		case OPERATION_POUR2:
			printf("fill B");
			break;
		case OPERATION_POUR1_2:
			printf("pour B A");
			break;
		case OPERATION_POUR2_1:
			printf("pour A B");
			break;
		default:
			break;
		}
		printf("\n");
	}
}

void bfs()
{
	s_jug jugs;
	jugs.jug1 = jugs.jug2 = 0;
	jugs.parent = -1;
	jugs.op = OPERATION_NONE;
	enque(jugs);

	while (!is_empty_q())
	{
		s_jug* item = deque();
		int jug1 = item->jug1;
		int jug2 = item->jug2;
		jugs.parent = item->id;
		if (jug1 == target || jug2 == target)
		{
			/*if (jug2 != target)
			{
				if (jug2 > 0)
				{
					jugs.jug2 = 0;
					jugs.jug1 = jug1;
					jugs.parent = item->id;
					jugs.op = OPERATION_EMPTY2;
					enque(jugs);
				}
				jugs.jug2 = jug1;
				jugs.jug1 = 0;
				if (jug2 == 0)
					jugs.parent = item->id;
				else
					jugs.parent = end - 1;
				jugs.op = OPERATION_POUR2_1;
				enque(jugs);

				print_path(end - 1);
			}
			else*/
				print_path(item->id);
			printf("success\n");
			break;
		}

		int need;
		//pour all A
		jugs.jug1 = max_jug1;
		jugs.jug2 = jug2;
		jugs.op = OPERATION_POUR1;
		enque(jugs);

		//pour from B
		jugs.jug1 = jug1;
		jugs.jug2 = jug2;
		need = GET_MIN((max_jug1 - jug1), jug2);
		jugs.jug1 += need;
		jugs.jug2 -= need;
		jugs.op = OPERATION_POUR1_2;
		enque(jugs);

		//pour all B
		jugs.jug1 = jug1;
		jugs.jug2 = max_jug2;
		jugs.op = OPERATION_POUR2;
		enque(jugs);

		//pour from A
		jugs.jug1 = jug1;
		jugs.jug2 = jug2;
		need = GET_MIN((max_jug2 - jug2), jug1);
		jugs.jug2 += need;
		jugs.jug1 -= need;
		jugs.op = OPERATION_POUR2_1;
		enque(jugs);

		//empty A
		jugs.jug1 = 0;
		jugs.jug2 = jug2;
		jugs.op = OPERATION_EMPTY1;
		enque(jugs);

		//empty B
		jugs.jug1 = jug1;
		jugs.jug2 = 0;
		jugs.op = OPERATION_EMPTY2;
		enque(jugs);
	}
}


int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d %d %d", &max_jug1, &max_jug2, &target) == 3)
	{
		init_q();
		bfs();
	}
	return 0;
}