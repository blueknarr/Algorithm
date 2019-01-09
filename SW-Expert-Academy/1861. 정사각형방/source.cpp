#include <iostream>
#include <stdio.h>
using namespace std;
int map[1000][1000], check[100001];
int N,num,res,cnt;

void dfs(int x, int y){
	cnt++;
	if (x + 1 < N && map[x+1][y] - map[x][y] == 1){ //down
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && map[x - 1][y] - map[x][y] == 1){
		dfs(x - 1, y);
	}
	if (y + 1 < N && map[x][y + 1] - map[x][y] == 1){
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && map[x][y - 1] - map[x][y] == 1){
		dfs(x, y - 1);
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < 100001; ++i)
			check[i] = 0;
		num = 0, res = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				cnt = 0;
				dfs(i, j);
				check[map[i][j]] = cnt;
			}
		}
		for (int i = 1; i <= N*N; ++i){
			if (res < check[i]){
				num = i;
				res = check[i];
			}
		}
		printf("#%d %d %d\n", tc,num,res);
	}
}