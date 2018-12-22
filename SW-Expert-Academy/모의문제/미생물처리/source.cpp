#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct{
	int cnt;
	int maxCnt;
	int dir;
}node;
node map[101][101], nextMap[101][101];
int N, K, M,res;
int dx[] = { 0,-1, 1, 0, 0 };
int dy[] = { 0,0, 0, -1, 1 };

void dfs(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (map[i][j].cnt >0){
				int d = map[i][j].dir;
				int nx = i + dx[d];
				int ny = j + dy[d];

				if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1){
					nextMap[nx][ny].maxCnt = nextMap[nx][ny].cnt = map[i][j].cnt / 2;
					if (d == 1)
						nextMap[nx][ny].dir = 2;
					else if (d == 2)
						nextMap[nx][ny].dir = 1;
					else if (d == 3)
						nextMap[nx][ny].dir = 4;
					else if (d == 4)
						nextMap[nx][ny].dir = 3;
				}
				else{
					if (nextMap[nx][ny].cnt > 0){
						if (nextMap[nx][ny].maxCnt > map[i][j].maxCnt){
							nextMap[nx][ny].cnt += map[i][j].cnt;
						}
						else{
							nextMap[nx][ny].maxCnt = map[i][j].maxCnt; //방향을 선택할 미생물의 최대 개수
							nextMap[nx][ny].cnt += map[i][j].cnt;
							nextMap[nx][ny].dir = map[i][j].dir;
						}
					}
					else{
						nextMap[nx][ny].maxCnt = nextMap[nx][ny].cnt = map[i][j].cnt;
						nextMap[nx][ny].dir = map[i][j].dir;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (nextMap[i][j].cnt != nextMap[i][j].maxCnt)
				nextMap[i][j].maxCnt = nextMap[i][j].cnt;
			map[i][j] = { 0, 0, 0 };
			map[i][j] = nextMap[i][j];
			nextMap[i][j] = { 0, 0, 0 };
		}
	}

}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				map[i][j] = nextMap[i][j] = { 0, 0, 0 };
			}
		}
		res = 0;
		for (int i = 0; i < K; ++i){
			int a, b, count, d;
			scanf("%d%d%d%d", &a, &b, &count, &d);
			map[a][b].maxCnt=map[a][b].cnt = count;
			map[a][b].dir = d;
		}
		while (M>0){
			dfs();
			M--;
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				res += map[i][j].cnt;
			}
		}
		printf("#%d %d\n", test_case, res);
	}
}