#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K,res,cnt;
int map[101][101];

void dfs(int x, int y){
	map[x][y] = cnt++;

	if (x + 1 >= 0 && x + 1 < M && !map[x + 1][y])
		dfs(x + 1, y);
	if (x - 1 >= 0 && x - 1 < M &&!map[x - 1][y])
		dfs(x - 1, y);
	if (y + 1 >= 0 && y+1 < N && !map[x][y + 1])
		dfs(x, y + 1);
	if (y - 1 >= 0 && y-1 < N && !map[x][y - 1])
		dfs(x, y - 1);
	return;
}

int main(){
	vector<int> v;
	cin >> M >> N >> K;

	for (int i = 0; i < K; ++i){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int j = y1; j < y2; ++j){
			for (int k = x1; k < x2; ++k){
				map[j][k] = 5;
			}
		}
	}
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			if (!map[i][j]){
				res++;
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt-1);
			}
		}
	}
	cout << res << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << ' ';
}