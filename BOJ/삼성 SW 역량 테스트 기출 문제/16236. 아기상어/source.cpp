#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, cnt;
int map[20][20],visited[20][20];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct point{
	int size;
	int x;
	int y;
};

int abs(int x, int y){
	if (x > y)
		return x - y;
	else
		return y - x;
}

int main(){
	scanf("%d", &N);
	point shark;
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9)
			{
				shark.size = 2;
				shark.x = i;
				shark.y = j;
			}
		}
	}
	
	int eatingTime = 0;
	
	while (1){
		
		//물고기와 상어 거리차 구하기
		queue<pair<int, int> > q;
		q.push(make_pair(shark.x, shark.y));
		visited[shark.x][shark.y] = 1;

		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int dir = 0; dir < 4; ++dir){
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (shark.size < map[nx][ny])
					continue;

				if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0){
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
		vector<pair<int,pair<int, int> > > fish;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (map[i][j] == 0 || map[i][j] == 9)
					continue;

				if (shark.size > map[i][j])
                    if(visited[i][j]-1>0)
					    fish.push_back(make_pair(visited[i][j]-1, make_pair(i, j)));
			}
		}
		//물고기 크기 오름차순, 가장 위, 왼쪽 순으로 정렬
		sort(fish.begin(), fish.end());

		if (fish.size()){
			//물고기 찾는다.
			bool flag = false;
			//물고기 크기 차이 비교
			for (int i = 0; i < fish.size(); ++i){
				if (shark.size > map[fish[i].second.first][fish[i].second.second]){
					//물고기가 존재한다.
					//물고기까지 갈 수 있는지 확인
					eatingTime += fish[i].first;
					//상어 사이즈 변경
					cnt++;
					if (cnt == shark.size){
						shark.size++;
						cnt = 0;
					}
					//이전 상어 좌표 갱신
					map[shark.x][shark.y] = 0;

					//상어 좌표							
					shark.x = fish[i].second.first;
					shark.y = fish[i].second.second;

					//새로운 상어 좌표 갱신
					map[shark.x][shark.y] = 9;
					flag = true;
					break;
				}
			}
			//물고기가 없다면 엄마 상어 호출
			if (!flag){
				//종료
				break;
			}
			for (int i = 0; i < N; ++i){
				for (int j = 0; j < N; ++j){
					visited[i][j] = 0;
				}
			}
		}
		else{
			//종료
			break;
		}
	}
	printf("%d\n", eatingTime);
	return 0;
}