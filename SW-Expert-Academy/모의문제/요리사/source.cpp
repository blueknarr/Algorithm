/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[16][16], check[16];
int N, res;

void dfs(int food, int cnt){
	check[food] = 1;
	if (cnt == N / 2){
		int A = 0, B = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (i == j)
					continue;
				if (check[i] && check[j])
					A += map[i][j];
				if (!check[i] && !check[j])
					B += map[i][j];
			}
		}
		res = min(res, abs(A - B));
	}
	for (int i = food + 1; i < N; ++i){
		dfs(i, cnt + 1);
	}
	check[food] = 0;
}

int main(){
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		res = 1e9;
		for (int i = 0; i < 16; ++i)
			check[i];
		dfs(0, 1);
		printf("#%d %d\n", tc, res);
	}
}
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[16][16], check[16];
int N,res;

void dfs(int food, int cnt){
	check[food] = 1;
	if (cnt == N / 2){
		int A = 0, B = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (i == j)
					continue;
				if (check[i] && check[j])
					A += map[i][j];
				if (!check[i] && !check[j])
					B += map[i][j];
			}
		}
		res = min(res, abs(A - B));
		return;
	}
	for (int next = food + 1; next < N; ++next){
		dfs(next, cnt + 1);
		check[next] = 0;
	}
	//check[food] = 0;
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
		for (int i = 0; i < 16; ++i)
			check[i] = 0;
		res = 1e9;
		//for (int i = 0; i < N; ++i)
			dfs(0,1);
		printf("#%d %d\n", tc, res);
	}
}