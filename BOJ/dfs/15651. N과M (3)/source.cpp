#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;

void dfs(int n, vector<int>& v, vector<int>& idx){
	if (M == n){
		for (int i = 0; i<n; ++i)
			printf("%d ", v[idx[i]]);
		printf("\n");
		return;
	}
	for (int i = 0; i<N; ++i){
		idx.push_back(i);
		dfs(n + 1, v, idx);
		idx.pop_back();
	}
}

int main(){
	vector<int> v;
	vector<int> idx;

	scanf("%d%d", &N, &M);
	for (int i = 0; i<N; ++i)
		v.push_back(i + 1);
	dfs(0, v, idx);

}