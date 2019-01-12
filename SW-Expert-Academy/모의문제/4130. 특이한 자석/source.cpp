#include <iostream>
#include <stdio.h>
using namespace std;
int map[4][8], check[4];
int K;

void initCheck(){
	for (int i = 0; i < 4; ++i)
		check[i] = 0;
}

void rotate(int number, int dir){
	if (dir == 1){
		int n = map[number][7];
		for (int i = 6; i >=0; --i)
			map[number][i + 1] = map[number][i];
		map[number][0] = n;
	}
	else{
		int n = map[number][0];
		for (int i = 1; i<8; ++i)
			map[number][i - 1] = map[number][i];
		map[number][7] = n;
	}

}

void dfs(int number, int dir){
	check[number] = 1;
	if (number < 3 && map[number][2] != map[number + 1][6] && !check[number + 1]){
		dfs(number + 1, -1 * dir);
	}
	if (number > 0 && map[number - 1][2] != map[number][6] && !check[number - 1]){
		dfs(number - 1, -1 * dir);
	}
	rotate(number, dir);
}

int main(){
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &K);
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 8; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		int res = 0;
		for (int i = 0; i < 4; ++i)
			check[i] = 0;
		while (K>0){
			int num, dir;
			scanf("%d%d", &num, &dir);
			dfs(num-1, dir);
			initCheck();
			K--;
		}
		for (int i = 0; i < 4; ++i){
			if (map[i][0] == 1)
				res += (1 << i);
		}
		printf("#%d %d\n", tc, res);
	}
}