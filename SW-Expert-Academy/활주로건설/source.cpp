#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[20][20], check[20][20];
int N, X, res;

void initCheck(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			check[i][j] = 0;
		}
	}
}

int isRowFlat(int r, int num){
	for (int j = 1; j < N; ++j){
		if (map[r][j] != num)
			return 0;
	}
	return 1;
}

void rowCheck(int r){
	if (isRowFlat(r,map[r][0])){
		res++;
	}
	else{
		for (int j = 0; j < N; ++j){
			int ny = j + 1;
			
			if (ny < N && abs(map[r][j] - map[r][ny]) > 1){
				return;
			}
			/*
			if (ny < N && j-1>=0 && map[r][j-1] == map[r][j] && map[r][j] == map[r][ny]){
				continue;
			}
			*/
			//right
			if (ny < N && map[r][j] - map[r][ny] == 1){
				int cnt = 0;
				
				for (int k = 0; k < X; ++k){
					if (ny + k < N && !check[r][ny + k] && map[r][ny] == map[r][ny + k])
						cnt += 1;
				}
				if (cnt == X){
					for (int k = 0; k < X; ++k){
						check[r][ny + k] = 1;
					}
				}
				else{
					return;
				}
			}
			//left
			if (j-1>=0 && map[r][j] - map[r][j-1] == 1){
				
				int cnt = 0;
				for (int k = X; k >0; --k){
					if (j - k >= 0 && !check[r][j - k] && map[r][j-1] == map[r][j - k])
						cnt += 1;
				}
				if (cnt == X){
					for (int k = X; k > 0; --k){
						check[r][j - k] = 1;
					}
				}
				else{
					return;
				}
			}
		}
		res++;
	}
}

int isColFlat(int c, int num){
	for (int i = 1; i < N; ++i){
		if (map[i][c] != num)
			return 0;
	}
	return 1;
}

void colCheck(int c){
	if (isColFlat(c, map[0][c])){
		res++;
	}
	else{
		for (int i = 0; i < N; ++i){
			int nx = i + 1;
			if (nx <N && abs(map[i][c] - map[nx][c]) > 1)
				return;
			/*
			if (nx < N && i-1>=0 && map[i-1][c] == map[i][c] && map[i][c] == map[nx][c])
				continue;
				*/
			//up
			if (i - 1 >= 0 && map[i][c] - map[i - 1][c] == 1){
				int cnt = 0;
				for (int k = X; k>0; --k){
					if (i-k >=0 && map[i-1][c] == map[i - k][c] && !check[i-k][c])
						cnt += 1;
				}
				if (cnt == X){
					for (int k = X; k > 0; --k)
						check[i - k][c] = 1;
				}
				else{
					return;
				}

			}
			//down
			if (nx < N && map[i][c] - map[nx][c] == 1){
				int cnt = 0;
				for (int k = 0; k < X; ++k){
					if (nx + k < N && map[nx][c] == map[nx + k][c] && !check[nx + k][c])
						cnt += 1;
				}
				if (cnt == X){
					for (int k = 0; k < X; ++k){
						check[nx + k][c] = 1;
					}
				}
				else{
					return;
				}
			}
		}
		res++;
	}
	
}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d%d", &N, &X);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		res = 0;
		initCheck();
		for (int i = 0; i < N; ++i)
			rowCheck(i);
		initCheck();
		for (int j = 0; j < N; ++j)
			colCheck(j);
		printf("#%d %d\n", tc, res);
	}
}