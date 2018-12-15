#include <iostream>
#include <stdio.h>
using namespace std;
int map[20][20], visited[20][20], check[101];
int N, res, flag,cnt,sx,sy;
int dx[] = { 1, 1, -1, -1 };
int dy[] = { 1, -1, -1, 1 };

void dfs(int x, int y){
	visited[x][y]++;
	check[map[x][y]]++;
	cnt++;
	if (sx == x && sy == y && visited[x][y] == 2){
		if (res < cnt)
			res = cnt;
		return;
		
	}

	if (flag == 0){//우하
		if (x + 1 < N && y + 1 < N && !check[map[x + 1][y + 1]]){
			dfs(x + 1, y + 1);
		}
		flag = 1;
	}
	if (flag == 1){//좌하
		if (x + 1 < N && y - 1 >= 0 && !check[map[x + 1][y - 1]]){
			dfs(x + 1, y - 1);
		}
		flag = 2;
	}
	if (flag == 2){//좌상
		if (x - 1 >= 0 && y - 1 >= 0 && !check[map[x - 1][y - 1]]){
			dfs(x - 1, y - 1);
		}
		flag = 3;
	}if (flag == 3){//우상
		if (x - 1 >= 0 && y + 1 < N && !check[map[x - 1][y + 1]]){
			dfs(x - 1, y + 1);
		}
		if (x-1 == sx && y+1 == sy){
			dfs(x - 1, y + 1);
			visited[x - 1][y + 1]--;
			check[map[x - 1][y + 1]]--;
			cnt--;
		}
		flag = 0;
	}
	visited[x][y]--;
	check[map[x][y]]--;
	cnt--;
}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		res = -1;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				visited[i][j] = 0;
			}
		}
		for (int i = 0; i < 101; ++i)
			check[i] = 0;

		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				sx = i, sy = j;
				cnt = -1, flag = 0;
				dfs(i, j);
			}
		}
		if (res < 4)
			res = -1;

		printf("#%d\n", res);
	}
}