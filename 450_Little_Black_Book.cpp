#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10000
#define MAXDEPT 13
#define MAXLEN 200

char dept[MAXDEPT][MAXLEN];

typedef struct
{
	char title[MAXLEN];
	char first_name[MAXLEN];
	char last_name[MAXLEN];
	char home_address[MAXLEN];
	int dept_index;
	char home_phone[MAXLEN];
	char work_phone[MAXLEN];
	char campus_box[MAXLEN];
}t_contact;

t_contact contact_arr[MAXN];

typedef struct
{
	int index;
	char last_name[MAXLEN];
}t_last_name;

t_last_name last_name_arr[MAXN];

int sortf(const void *a, const void *b)
{
	t_last_name *c1 = (t_last_name *)a;
	t_last_name *c2 = (t_last_name *)b;

	return strcmp(c1->last_name, c2->last_name);
}

int main()
{
	//freopen("inp.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, i, j, k, n;
	char inp[10000];
	scanf("%d", &T);
	gets(inp);
	n = 0;
	//memset(contact_arr, 0x00, sizeof(contact_arr));
	//memset(last_name_arr, 0x00, sizeof(last_name_arr));
	for (i = 0; i < T; ++i)
	{
		gets(dept[i]);
		while (gets(inp)) //Title, First Name, Last Name, Street Address, Home Phone, Work Phone, and Campus Mailbox.
		{
			if (!inp[0])
				break;
			contact_arr[n].dept_index = i;
			last_name_arr[n].index = n;
			j = 0;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].title[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].title[k] = '\0';
			
			++j;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].first_name[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].first_name[k] = '\0';

			++j;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].last_name[k] = inp[j];
				last_name_arr[n].last_name[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].last_name[k] = '\0';
			last_name_arr[n].last_name[k] = 0;

			++j;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].home_address[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].home_address[k] = '\0';

			++j;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].home_phone[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].home_phone[k] = '\0';

			++j;
			k = 0;
			while (inp[j] != ',')
			{
				contact_arr[n].work_phone[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].work_phone[k] = '\0';

			++j;
			k = 0;
			while (inp[j])
			{
				contact_arr[n].campus_box[k] = inp[j];
				++k;
				++j;
			}
			contact_arr[n].campus_box[k] = '\0';

			++n;
		} // end department
	}//end input

	qsort(last_name_arr, n, sizeof(t_last_name), sortf);

	for (j = 0; j < n; ++j)
	{
		i = last_name_arr[j].index;
		printf("----------------------------------------\n");
		printf("%s %s %s\n", contact_arr[i].title, contact_arr[i].first_name, contact_arr[i].last_name);
		printf("%s\n", contact_arr[i].home_address);
		printf("Department: %s\n", dept[contact_arr[i].dept_index]);
		printf("Home Phone: %s\n", contact_arr[i].home_phone);
		printf("Work Phone: %s\n", contact_arr[i].work_phone);
		printf("Campus Box: %s\n", contact_arr[i].campus_box);
	}
}