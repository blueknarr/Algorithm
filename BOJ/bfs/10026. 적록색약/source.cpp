#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

char color[100][100];
int rgb[100][100], rb[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main(){
	int N, res1=0, res2=0;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		scanf("%s", color[i]);
	}
	queue<pair<int, int> > q;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (rgb[i][j])
				continue;
			q.push(make_pair(i, j));
			res1++;
			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int dir = 0; dir < 4; ++dir){
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N && color[i][j] == color[nx][ny] && !rgb[nx][ny]){
						rgb[nx][ny] = res1;
						q.push(make_pair(nx, ny));
					}
				}
			}

			if (rb[i][j])
				continue;
			q.push(make_pair(i, j));
			res2++;
			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				if (color[i][j] == 'B'){
					for (int dir = 0; dir < 4; ++dir){
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && color[nx][ny] == 'B' && !rb[nx][ny]){
							rb[nx][ny] = res2;
							q.push(make_pair(nx, ny));
						}
					}
				}
				else{
					for (int dir = 0; dir < 4; ++dir){
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && color[nx][ny] != 'B' && !rb[nx][ny]){
							rb[nx][ny] = res2;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}

	cout << res1 << ' ' << res2 << endl;
}