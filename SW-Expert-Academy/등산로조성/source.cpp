#include <iostream>
#include <stdio.h>
using namespace std;
int map[8][8];
int N, K, res,cnt, maxHeight;

void dfs(int x, int y){
	cnt++;
	if (map[x][y] == maxHeight){
		if (res < cnt)
			res = cnt;
	}
	if (x + 1 < N && map[x + 1][y] > map[x][y]){
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && map[x - 1][y] > map[x][y]){
		dfs(x - 1, y);
	}
	if (y + 1 < N && map[x][y + 1] > map[x][y]){
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && map[x][y - 1] > map[x][y]){
		dfs(x, y - 1);
	}
	cnt--;
}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d %d", &N, &K);
		maxHeight = 0, res = 0, cnt = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
				if (maxHeight < map[i][j])
					maxHeight = map[i][j];
			}
		}
		
		for (int x = 0; x < N; ++x){
			for (int y = 0; y < N; ++y){
				for (int depth = 1; depth <= K; ++depth){
					map[x][y] -= depth;
					for (int i = 0; i < N; ++i){
						for (int j = 0; j < N; ++j){
							dfs(i, j);
						}
					}
					map[x][y] += depth;
				}
			}
		}
		printf("#%d %d\n", tc, res);
	}
}
