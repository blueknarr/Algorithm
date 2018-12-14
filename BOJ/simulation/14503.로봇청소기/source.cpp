#include <iostream>
#include <cstdio>

using namespace std;

int N, M, res;
int map[50][50], visited[50][50];
int dx[] = { -1, 0, 1, 0 }; //북,동,남,서
int dy[] = { 0, 1, 0, -1 };
int bx[] = { 0, 0, 1, -1 };
int by[] = { 1, -1, 0, 0 }; //동,남,서,북

void dfs(int x, int y, int dir){
	//현재 위치를 청소한다.
	if (map[x][y] == 0){
		map[x][y] = 2;
		res++;
	}
		
	//현재 위치에서 dir 방향으로 탐색
	for (int i = 0; i < 4; ++i){
		dir = (dir + 3) % 4;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (map[nx][ny] == 0){
			dfs(nx, ny, dir);
			return;
		}
	}
	//후진
	int back_dir = (dir + 2) % 4;
	int nx = x + dx[back_dir];
	int ny = y + dy[back_dir];

	if (map[nx][ny] != 1)
		dfs(nx, ny, dir);
	return;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int x, y, d;
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &x, &y, &d);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	dfs(x, y, d);
	printf("%d\n", res);
}