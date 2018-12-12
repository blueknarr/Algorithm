#include <iostream>
#include <cstdio>
using namespace std;

int N;
long long int Max=-1000000000, Min=1000000000;
int num[100];
int op[4];

void dfs(int pick, long long int sum){
	if (pick == N-1){
		if (sum > Max)
			Max = sum;
		if (sum < Min)
			Min = sum;
		return;
	}
	if (op[0] > 0){
		op[0]--;
		dfs(pick + 1, sum + num[pick+1]);
		op[0]++;
	}
	if (op[1] > 0){
		op[1]--;
		dfs(pick + 1, sum - num[pick + 1]);
		op[1]++;
	}
	if (op[2] > 0){
		op[2]--;
		dfs(pick + 1, sum * num[pick + 1]);
		op[2]++;
	}
	if (op[3] > 0){
		op[3]--;
		dfs(pick + 1, sum / num[pick + 1]);
		op[3]++;
	}
}

int main(){
	scanf("%d", &N);

	for (int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 4; ++i){
		scanf("%d", &op[i]);
	}
	dfs(0,num[0]);
	printf("%d\n", Max);
	printf("%d\n", Min);
}