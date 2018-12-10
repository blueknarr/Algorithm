#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int block[6][4] = {
	{ 0, 1, 2, 3 },
	{ 1, 3, 0, 2 },
	{ 1, 2, 3, 0 },
	{ 2, 0, 3, 1 },
	{ 3, 0, 1, 2 },
	{ 1, 0, 3, 2 }
};
int dx[] = { 0, 0, 1, -1 }; //동,서,남,북
int dy[] = { 1, -1, 0, 0 };
struct point{
	int x;
	int y;
};
point hall[11][2];
int N, sx, sy, cnt, res;
int map[103][103];
int check[11];

void dfs(int x, int y, int dir){
	//현재값

	while (1){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		//종료 조건
		if ((nx == sx && ny == sy) || map[nx][ny] == -1){
			break;
		}
		if (map[nx][ny] == 0){
			x = nx;
			y = ny;
		}
		else if (map[nx][ny] > 0 && map[nx][ny] < 6){
			cnt++;
			dir = block[map[nx][ny]][dir];
			x = nx;
			y = ny;
		}
		else if (map[nx][ny] > 5 && map[nx][ny] < 11){
			int idx = 0;
			if (hall[map[nx][ny]][1].x == nx && hall[map[nx][ny]][1].y == ny)
				idx = 1;
			idx = 1 - idx;

			x = hall[map[nx][ny]][idx].x;
			y = hall[map[nx][ny]][idx].y;

		}
	}

}

int main(){
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		scanf("%d", &N);
		//가장자리 벽으로 세팅
		for (int i = 0; i < N + 2; ++i){
			map[0][i] = map[N + 1][i] = map[i][0] = map[i][N + 1] = 5;
		}

		//핀볼 좌표 입력
		for (int i = 1; i < N + 1; ++i){
			for (int j = 1; j < N + 1; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] > 5){
					if (!check[map[i][j]]){
						hall[map[i][j]][0].x = i;
						hall[map[i][j]][0].y = j;
						check[map[i][j]] = 1 - check[map[i][j]];
					}
					else{
						hall[map[i][j]][1].x = i;
						hall[map[i][j]][1].y = j;
						check[map[i][j]] = 1 - check[map[i][j]];
					}
				}
			}
		}
		for (int d = 0; d < 4; ++d){
			for (int i = 1; i < N + 1; ++i){
				for (int j = 1; j < N + 1; ++j){
					//0이 아니면 패스
					if (map[i][j])
						continue;
					sx = i, sy = j;
					dfs(i, j, d);
					if (res < cnt)
						res = cnt;
					cnt = 0;
				}
			}
		}

		printf("#%d %d\n", tc, res);
		res = 0;
	}
}