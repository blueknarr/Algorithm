#include <stdio.h>
using namespace std;

int N, res=987654321,size;
int mat[20][20], taken[20];

void dfs(int pick,int index){
	taken[index] = 1;
	if (pick == size){	
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (i == j)
					continue;
				if (taken[i] == 1 && taken[j] == 1){//A팀
					sum_a += mat[i][j];
				}
				if (taken[i] == 0 && taken[j] == 0){
					sum_b += mat[i][j];
				}
			}
		}
		int min = sum_a - sum_b;
		if (min < 0 )
			min = -min;
		if (res > min)
			res = min;
		return;

	}
	//조합
	for (int i = index+1; i < N; ++i){
			dfs(pick + 1, i);
			taken[i] = 0;
		
	}	
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &mat[i][j]);
		}
	}
	size = N / 2;
	dfs(1,0);
	printf("%d\n", res);
}