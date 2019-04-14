#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

int map[15][15], archer[3];
int N, M, D;
int ans;

void kill(){
	int map2[15][15] = { 0, }, cnt = 0, t = N;
	memcpy(map2, map, sizeof(map));
	while (t--){
		//적 찾기
		vector<pair<int, int> > v;
		for (int k = 0; k < 3; ++k){
			priority_queue <pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > q;
			for (int i = 0; i < N; ++i){
				for (int j = 0; j < M; ++j){
					if (map2[i][j]){
						int dist = abs(N - i) + abs(archer[k] - j);
						if (dist <= D){
							q.push(make_pair(dist, make_pair(j, i)));
						}
					}
				}
			}
			if (q.size()){
				int x = q.top().second.second;
				int y = q.top().second.first;
				v.push_back(make_pair(x, y));
			}
		}
		//적 죽이기
		int size = v.size();
		for (int i = 0; i < size; ++i){
			int x = v[i].first;
			int y = v[i].second;
			if (map2[x][y])
			{
				map2[x][y] = 0;
				cnt++;
			}
		}
		//적 좌표 갱신
		for (int i = N - 2; i >= 0; --i){
			for (int j = 0; j < M; ++j){
				map2[i + 1][j] = map2[i][j];
			}
		}
		for (int j = 0; j < M; ++j)
			map2[0][j] = 0;
	}
	if (cnt > ans)
		ans = cnt;
}

void solve(){
	for (int i = 0; i < M - 2; ++i){
		for (int j = i + 1; j < M - 1; ++j){
			for (int k = j + 1; k < M; ++k){
				archer[0] = i, archer[1] = j, archer[2] = k;
				kill();
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &D);

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	solve();
	printf("%d\n", ans);
}