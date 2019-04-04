#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int ice[300][300], ice2[300][300],visited[300][300];
int N, M;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);

	//시작 조건:  N과 M은 3 이상 300 
	//배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%d", &ice[i][j]);
		}
	}

	int year = 0,divided=0;
	
	
	while (1){
		//얼음 탐색
		for (int i = 1; i < N - 1; ++i){
			for (int j = 1; j < M - 1; ++j){
				int cnt = 0;
				if (ice[i][j]==0)
					continue;
				if (ice[i + 1][j] == 0)
					cnt++;
				if (ice[i - 1][j] == 0)
					cnt++;
				if (ice[i][j + 1] == 0)
					cnt++;
				if (ice[i][j - 1] == 0)
					cnt++;
				ice2[i][j] = max(ice[i][j] - cnt,0);
			}
		}

		//빙산 분리 탐색
		queue<pair<int, int> > q;
		divided = 0;
		for (int i = 1; i < N - 1; ++i){
			for (int j = 1; j < M - 1; ++j){
				if (ice2[i][j] == 0 || visited[i][j])
					continue;
				q.push(make_pair(i, j));
				visited[i][j] = ++divided;

				while (!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; ++dir){
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						if (ice2[nx][ny] && visited[nx][ny] == 0){
							visited[nx][ny] = divided;
							q.push(make_pair(nx, ny));
						}
					}

				}
			}
		}
		//시간 증가
		year++;

		//종료 조건: 두 덩어리 이상으로 분리되는 최초의 시간, 
		if (divided >= 2){
			break;
		}
		bool melted = true;
		//빙산이 다 녹았는지 확인
		for (int i = 1; i < N - 1; ++i){
			for (int j = 1; j < M - 1; ++j){
				if (visited[i][j] == 1)
					melted=false;
				ice[i][j] = ice2[i][j];
				ice2[i][j] = visited[i][j] = 0;
			}
		}
		//종료 조건: 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0
		if (melted){
			year = 0;
			break;
		}
	}
	printf("%d\n", year);
	return 0;
}