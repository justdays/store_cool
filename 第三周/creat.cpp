#include"creat.h"
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long LL;
vector <int> a;
map <int, bool> vis;

int random(int n)
{
	return (LL)rand() * rand() % n + 1;
}

int creat()
{
	FILE* fp = NULL;
	fp = fopen("random number.txt", "wb+");
	srand((unsigned)time(0));
	int n, m;
	printf("Please input the range in roll :\n");
	cin >> n;// scanf("%d", &n);
	printf("Please input the quantity you want : \n");
	cin >> m;// scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		int tmp = random(n);
		//while(vis[tmp])		tmp = random(n);
		a.push_back(tmp);
		vis[tmp] = 1;
	}
	//sort(a.begin(), a.end());
	for (vector <int> ::iterator it = a.begin(); it != a.end(); ++it)
		printf("%-5d ", *it), fprintf(fp, "%-5d", *it);
	return 0;
}
