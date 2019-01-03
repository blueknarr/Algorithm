#include <iostream>
#include <queue>

using namespace std;

#define GSIZE 101

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int N, M;

typedef struct Graph{
	char adj_mat[GSIZE][GSIZE];
	int visited[GSIZE][GSIZE];
}Graph;

struct element{
	int x, y;
};

int safe(int a, int b)
{
	return (a >= 0 && a < N) && (b >= 0 && b < M);
}

void input(Graph *g)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
        scanf("%s", &g->adj_mat[i]);
		//for (int j = 0; j < M; j++)
			
}

void init(Graph *g)
{
	for (int i = 0; i < GSIZE; i++)
	{
		for (int j = 0; j < GSIZE; j++)
		{
			g->visited[i][j] = 0;
		}
	}
}

void BFS(Graph *g)
{
	queue<element> q;
	element ele;
	ele.x = 0, ele.y = 0;
	q.push(ele);
	g->visited[ele.x][ele.y] = 1;

	while (!q.empty())
	{
		element cur;
		cur = q.front();
		q.pop();

		if (cur.x == N - 1 && cur.y == M - 1)
			break;
		for (int i = 0; i < 4; i++)
		{
			element next;
			next.x = cur.x + dx[i], next.y = cur.y + dy[i];
			if (safe(next.x, next.y) && !g->visited[next.x][next.y] && g->adj_mat[next.x][next.y]=='1')
			{
				g->visited[next.x][next.y] = g->visited[cur.x][cur.y] + 1;
				q.push(next);
			}
		}
	}
	printf("%d", g->visited[N - 1][M - 1]);
}

int main(){

	Graph g;

	input(&g);
	init(&g);
	BFS(&g);
	return 0;
}