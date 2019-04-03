#include <cstdio>
#include <queue>
using namespace std;
int N;
int map[100][100],visited[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void init(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			visited[i][j] = 0;
	}
}

int main(){
	//2 <= N <=100 integer
	//low, high 1<= h <=100
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int low = 101, high = 0;
	int answer = 1;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &map[i][j]);

			if (map[i][j]>high)
				high = map[i][j];
			if (map[i][j] < low)
				low = map[i][j];
		}
	}

	for (int k = low; k <= high; ++k){
		//tile보다 낮은 지대 찾기
		int tile = k;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (map[i][j] > tile)
					continue;
				visited[i][j] = -1;
			}
		}
		
		queue<pair<int, int> > q;
		int region = 0;
		//안전영역 구하기
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (visited[i][j])
					continue;
				q.push(make_pair(i, j));
				visited[i][j] = ++region;

				while (!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; ++dir){
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny]==0){
							visited[nx][ny] = region;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
		if (region > answer)
			answer = region;
		//visited 초기화
		init();
	}
	printf("%d\n", answer);
	return 0;
}