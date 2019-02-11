#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, res, cnt;
int map[25][25], visited[25][25];

void dfs(int x, int y){
	visited[x][y] = cnt++;
	if (x + 1 >= 0 && x + 1 < N && !visited[x + 1][y] && map[x + 1][y] == 1){
		//visited[x+1][y] = cnt++;
		dfs(x + 1, y);
	}
	if (x - 1 >= 0 && x - 1 < N && !visited[x - 1][y] && map[x - 1][y] == 1){
		//visited[x - 1][y] = cnt++;
		dfs(x - 1, y);
	}
	if (y + 1 >= 0 && y + 1 < N && !visited[x][y + 1] && map[x][y + 1] == 1){
		//visited[x][y + 1] = cnt++;
		dfs(x, y + 1);
	}
	if (y - 1 >= 0 && y - 1 < N && !visited[x][y - 1] && map[x][y - 1] == 1){
		//visited[x][y - 1] = cnt++;
		dfs(x, y - 1);
	}
	return;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%1d", &map[i][j]);
		}
	}

	vector<int> v;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (!map[i][j] || visited[i][j])
				continue;
			res++;
			cnt = 1;
			dfs(i, j);
			v.push_back(cnt-1);
		}
	}
	cout << res << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}