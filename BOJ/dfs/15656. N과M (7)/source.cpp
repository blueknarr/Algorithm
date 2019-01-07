#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void dfs(int n, vector<int>& v,vector<int>& res){
	if (n == M){
		for (int i = 0; i < M; ++i){
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; ++i){
		res.push_back(v[i]);
		dfs(n + 1, v, res);
		res.pop_back();
	}
}

int main(){
	vector<int> v;
	vector<int> res;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0, v,res);
}