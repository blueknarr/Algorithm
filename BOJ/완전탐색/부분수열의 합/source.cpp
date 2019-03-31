#include <iostream>
#include <stdio.h>
using namespace std;
int number[20];
int N, S,res,cnt;

void dfs(int index, int val){
	if (index == N)
		return;
	if (S == val + number[index])
		res++;
	dfs(index + 1, val);
	dfs(index + 1, val + number[index]);
}

int main(){
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &S);
	res = 0;
	for (int i = 0; i < N; ++i)
		scanf("%d", &number[i]);
		dfs(0, 0);
	printf("%d\n", res);
}