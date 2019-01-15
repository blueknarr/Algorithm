#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int R, C, res;
char map[50][50];
int visited[50][50];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main(){
	scanf("%d%d", &R, &C);
	int sx, sy,wx,wy,ex,ey;
	queue<pair<int, int> > q;
	for (int i = 0; i < R; ++i){
		scanf("%s", map[i]);
		for (int j = 0; j < C; ++j){
			if (map[i][j] == '*'){
				wx = i, wy = j;
				q.push(make_pair(wx, wy));
			}
			else if (map[i][j] == 'S'){
				sx = i, sy = j;
				
			}
			else if (map[i][j] == 'D'){
				ex = i, ey = j;
			}
		}
	}
	q.push(make_pair(sx, sy));
	

	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == ex && y == ey)
			break;

		for (int d = 0; d < 4; ++d){
			int nx = x + dx[d];
			int ny = y + dy[d];


			if (map[x][y] == '*'){
				visited[x][y] = 100;
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && map[nx][ny] == '.' && !visited[nx][ny]){
					visited[nx][ny] = 100;
					map[nx][ny] = '*';
					q.push(make_pair(nx, ny));
				}
			}
			else{
				if (nx >= 0 && nx < R && ny >= 0 && ny < C && (map[nx][ny] == '.' || map[nx][ny] == 'D') && !visited[nx][ny]){
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if (visited[ex][ey] > 0){
		printf("%d\n", visited[ex][ey]);
	}
	else{
		printf("KAKTUS\n");
	}

}