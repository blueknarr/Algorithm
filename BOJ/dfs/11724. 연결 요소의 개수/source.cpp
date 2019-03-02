#include <cstdio>
#include <vector>
using namespace std;

bool check[1001];
vector<int> v[1001];

void dfs(int node){
	check[node] = true;
	for (int i = 0; i < v[node].size(); ++i){
		int next = v[node][i];
		if (!check[next])
			dfs(next);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	
	for (int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int component = 0;
	for (int i = 1; i <= n; ++i){
		if (!check[i]){
			dfs(i);
			component++;
		}
	}
	printf("%d\n", component);
}
