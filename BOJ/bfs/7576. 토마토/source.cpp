#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int map[1000][1000];
int M, N, res,cnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };


int main(){
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d%d", &M, &N);

	queue<pair<int, int> > q;
	bool flag = false;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1){
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 0){
				flag = true;
			}
		}
	}
	if (!flag){
		res = 0;
	}
	else{
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int d = 0; d < 4; ++d){
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0){
					res = map[nx][ny] = map[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < M; ++j){
				if (map[i][j] == 0){
					res -= res;
					break;
				}
			}
			if (res == 0)
				break;
		}
		res -= 1;
	}
	printf("%d\n", res);
}