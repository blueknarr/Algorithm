#include <cstdio>
#include <queue>
using namespace std;
int N, L, R;
int map[50][50], area[50][50];
bool door[50][50][5]; //0:up, 1:left, 2:down, 3:right, 4:visited
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int abs(int x, int y){
	if (x > y)
		return x - y;
	else
		return y - x;
}

int main(){
	//freopen("input.txt", "r", stdin);

	int ans = 0;
	int isMoved = 0;
	//입력
	scanf("%d%d%d", &N, &L,&R);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	bool flag = false;
	while (1){
		
		// L <=인구차 <=W, 국경이 열린다.
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				//up
				int x = i - 1;
				if (x >= 0 && x < N && L <= abs(map[i][j], map[x][j]) && R >= abs(map[i][j], map[x][j])){
					door[x][j][2] = door[i][j][0] = true;
				}
				//down
				x = i + 1;
				if (x >= 0 && x < N && L <= abs(map[i][j], map[x][j]) && R >= abs(map[i][j], map[x][j])){
					door[x][j][0] = door[i][j][2] = true;
				}
				//left
				int y = j - 1;
				if (y >= 0 && y < N && L <= abs(map[i][j], map[i][y]) && R >= abs(map[i][j], map[i][y])){
					door[i][y][3] = door[i][j][1] = true;
				}
				//right
				y = j + 1;
				if (y >= 0 && y < N && L <= abs(map[i][j], map[i][y]) && R >= abs(map[i][j], map[i][y])){
					door[i][y][1] = door[i][j][3] = true;
				}
			}
		}

		// 나라를 다 탐색하면 인구이동 시작
		// 국경이 열린 나라들만 이동이 자유, 국경이 열린 모든 나라 인구수 / 나라수로 변경
		int number = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (door[i][j][4]){
					continue;
				}
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				door[i][j][4] = true;
				area[i][j] = ++number;
				isMoved=1;
				int population = map[i][j];

				while (!q.empty()){
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int dir = 0; dir < 4; ++dir){
						int nx = x + dx[dir];
						int ny = y + dy[dir];

						//범위 밖
						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;

						int opposite = (dir + 2) % 4;

						if (!door[nx][ny][4] && door[x][y][dir] && door[nx][ny][opposite]){
							isMoved++;
							door[nx][ny][4] = true;
							population += map[nx][ny];
							area[nx][ny] = number;
							q.push(make_pair(nx, ny));
						}
					}
				}

				if (isMoved == 1)
					continue;
				else
					flag = true;
				

				int avg = population / isMoved;
				for (int i = 0; i < N; ++i){
					for (int j = 0; j < N; ++j){
						if (area[i][j] == number)
							map[i][j] = avg;
					}
				}
			}
		}
		// 인구 이동이 안될때까지 반복
		if (flag == false){
			break;
		}
		ans++;
		flag = false;
		// 국경을 닫는다.
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				door[i][j][0] = door[i][j][1] = door[i][j][2] = door[i][j][3] = door[i][j][4] = false;
				area[i][j] = 0;
			}
		}
	}
	printf("%d\n", ans);
	
}