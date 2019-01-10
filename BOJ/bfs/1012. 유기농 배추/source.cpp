#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int map[50][50], isVisited[50][50];
int M, N, K;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init(){
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			map[i][j] = isVisited[i][j] = 0;
		}
	}
}

int main(){
	freopen("sample_input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		int res = 0;
		scanf("%d%d%d", &M, &N, &K);

		init();
		for (int i = 0; i < K; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			map[a][b] = 1;
		}

		queue<pair<int, int> > q;

		for (int i = 0; i < M; ++i){
			for (int j = 0; j < N; ++j){
				if (map[i][j] == 0)
					continue;
				if (map[i][j] == 1 && !isVisited[i][j]){
					res++;
					q.push(make_pair(i, j));
					isVisited[i][j] = res;
					while (!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int d = 0; d < 4; ++d){
							int nx = x + dx[d];
							int ny = y + dy[d];

							if (nx >= 0 && nx<50 && ny >= 0 && ny < 50 && map[nx][ny] == 1 && !isVisited[nx][ny]){
								isVisited[nx][ny] = res;
								q.push(make_pair(nx, ny));
							}

						}
					}
				}
			}
		}
		printf("%d\n", res);
	}
}