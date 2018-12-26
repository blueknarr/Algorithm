#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 51;

int N, M, ans,cnt;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
char adj_mat[MAX][MAX];
int visited[MAX][MAX];


struct vertex{
	int x, y;
};

bool safe(int x, int y)
{
	return (x >= 0 && x < N) && (y >= 0 && y < M);
}

void init()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
		{
			//adj_mat[i][j] = NULL;
			visited[i][j] = 0;
		}
	}
}

queue<vertex> v;

void input()
{
	//queue<vertex> v; 
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", adj_mat[i]);
		for (int j = 0; j < M; j++)
		{
			if (adj_mat[i][j] == 'L')
			{
				v.push(vertex{ i, j });
			}
		}
	}
}

void BFS()
{
	while (!v.empty())
	{
		queue<vertex> q;
		q.push(v.front());
		v.pop();
		visited[q.front().x][q.front().y] = 1;
		
		while (!q.empty())
		{
			vertex cur=q.front();
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int next_x = cur.x + dx[i], next_y = cur.y + dy[i];
				if (safe(next_x, next_y) && !visited[next_x][next_y] && adj_mat[next_x][next_y] == 'L')
				{
					visited[next_x][next_y] = visited[cur.x][cur.y] + 1;
					ans = visited[next_x][next_y];
					if (ans > cnt)
						cnt = ans;
					q.push(vertex{ next_x, next_y });
				}
			}
		}
		
		//for (int i = 0; i < N; i++)
		//	printf("%d %d %d %d %d %d %d\n", visited[i][0], visited[i][1], visited[i][2], visited[i][3], visited[i][4], visited[i][5], visited[i][6]);
		init();
	}
	printf("%d\n", cnt-1);
}

int main()
{
	input();
	BFS();
}