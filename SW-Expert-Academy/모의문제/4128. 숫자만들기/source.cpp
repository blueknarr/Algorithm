#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX_N 12
int number[MAX_N];
int op[4];
int N, maxResult,minResult;

void dfs(int pos, int val){
	if (pos == N){
		if (val > maxResult)
			maxResult = val;
		if (val < minResult)
			minResult = val;
		return;
	}
	if (op[0] > 0){//'+'
		op[0]--;
		//val += number[pos];
		dfs(pos + 1, val+number[pos]);
		op[0]++;
	}
	if (op[1] > 0){//'-'
		op[1]--;
		//val -= number[pos];
		dfs(pos + 1, val - number[pos]);
		op[1]++;
	}
	if (op[2] > 0){//'*'
		op[2]--;
		//val *= number[pos]; //재귀함수 호출이 끝나고 이전 val값이 복구가 안됨
		dfs(pos + 1, val*number[pos]);
		op[2]++;
	}
	if (op[3] > 0){//'/'
		op[3]--;
		//val /= number[pos];
		dfs(pos + 1, val / number[pos]);
		op[3]++;
	}

}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case){
		scanf("%d", &N);
		for (int i = 0; i < 4;++i){
			scanf("%d", &op[i]);
		}
		for (int i = 0; i < N; ++i){
			scanf("%d", &number[i]);
		}
		maxResult = -1e9, minResult = 1e9;
		dfs(1, number[0]);
		printf("#%d %d\n", test_case, maxResult - minResult);
	}
}