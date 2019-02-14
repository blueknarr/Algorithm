#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[32001];
int ind[32001];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		ind[y] += 1;
	}

	queue<int> q;

	for (int i = 1; i <= n; ++i){
		if (ind[i] == 0)
			q.push(i);
	}

	for (int k = 0; k < n; ++k){
		int x = q.front();
		q.pop();

		printf("%d ", x);
		for (int i = 0; i < v[x].size(); ++i){
			int y = v[x][i];
			ind[y] -= 1;
			if (ind[y] == 0)
				q.push(y);
		}
	}
	printf("\n");
	return 0;
}