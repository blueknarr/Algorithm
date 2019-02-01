#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

char map[100][100];
int visited[100][100];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(){
	int R, C;
	int wolf = 0, sheep = 0;
	scanf("%d%d", &R, &C);
	for (int i = 0; i < R; ++i)
		scanf("%s", &map[i]);

	queue<pair<int, int> > q;

	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			int wolfCnt = 0, sheepCnt = 0;
			if (visited[i][j] || map[i][j] == '#')
				continue;

			q.push(make_pair(i, j));
			visited[i][j] = 1;
			
			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (map[x][y] == 'v'){
					wolfCnt++;
				}
				else if (map[x][y] == 'o'){
					sheepCnt++;
				}

				for (int d = 0; d < 4; ++d){
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] != '#' && !visited[nx][ny]){
						visited[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
			if (sheepCnt > wolfCnt){
				sheep += sheepCnt;
			}
			else{
				wolf += wolfCnt;
			}
		}
	}
	printf("%d %d\n", sheep, wolf);
}