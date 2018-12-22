#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int map[51][51][4], visited[51][51];
int N, M, R, C, L,res;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int pipe[8][4] = {//상,좌,하,우
	{0,0,0,0},
	{1,1,1,1},
	{1,0,1,0},
	{0,1,0,1},
	{1,0,0,1},
	{0,0,1,1},
	{0,1,1,0},
	{1,1,0,0}
};
typedef struct{
	int x;
	int y;
	int time;
}node;

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d%d%d%d%d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M; ++j){
				int type;
				scanf("%d", &type);
				for (int dir = 0; dir < 4; ++dir){
					map[i][j][dir] = pipe[type][dir];
				}
				visited[i][j] = 0;
			}
		}
		int nt = 1;
		res = 1;
		node point;
		queue<node> q;
		point.x = R, point.y = C, point.time = 1;
		q.push(point);
		visited[point.x][point.y] = 1;

		while (!q.empty()){
			int x = q.front().x;
			int y = q.front().y;
			int t = q.front().time;
			q.pop();

			for (int dir = 0; dir < 4; ++dir){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				nt = t + 1;
				int oppDir = (dir + 2) % 4;

				if (!visited[nx][ny] && map[x][y][dir] && map[nx][ny][oppDir] && nx >= 0 && nx < N && ny >= 0 && ny < M && nt <= L){
					res++;
					visited[nx][ny] = 1;
					point.x = nx, point.y = ny, point.time = nt; 
					q.push(point);
				}
			}
		}
		printf("#%d %d\n", test_case, res);
	}
}