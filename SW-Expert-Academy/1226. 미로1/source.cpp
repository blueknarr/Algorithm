#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define SIZE 17
using namespace std;


int room[SIZE][SIZE];
int isVisited[SIZE][SIZE];
int dir[4][2] = {
	{ 1, 0 },
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 }
};
int sx, sy;

int solve(){
    queue<pair<int, int> > q;
	q.push(make_pair(sx, sy));
	isVisited[sx][sy] = 1;

	while (!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (room[x][y] == 3)
			return 1;

		for (int d = 0; d<4; d++){
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];

			if (!isVisited[nx][ny] && room[nx][ny] != 1){
				isVisited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return 0;
}

int main(){
	int TestCase = 0;
	//freopen("input.txt", "r", stdin);

	for (int tc = 1; tc <= 10; tc++) {
		scanf("%d", &TestCase);
		for (int i = 0; i<16; i++){
			for (int j = 0; j<16; j++){
				scanf("%1d", &room[i][j]);
				if (room[i][j] == 2){
					sx = i, sy = j;
				}
			}
		}
		printf("#%d %d\n", TestCase, solve());
		memset(isVisited, 0, sizeof(isVisited));
	}
}