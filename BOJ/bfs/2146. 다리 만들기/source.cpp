#include <cstdio>
#include <queue>
using namespace std;

int map[100][100], floodfill[100][100], visited[100][100];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int main(){
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);

	//입력
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	//섬 구분
	int cnt = 0;
	queue<pair<int, int> > q;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (!map[i][j] || floodfill[i][j])
				continue;
			q.push(make_pair(i, j));
			floodfill[i][j] = ++cnt;

			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int dir = 0; dir < 4; ++dir){
					int nx = x + dx[dir];
					int ny = y + dy[dir];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] && !floodfill[nx][ny]){
						floodfill[nx][ny] = cnt;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}

	//각각의 섬에서 다리 증가
	
	return 0;



}