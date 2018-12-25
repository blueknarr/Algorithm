#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, W, H, res=987654321;
int pin[15][12], cp[15][12];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void init(){
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			cp[i][j] = pin[i][j]=0;
		}
	}
}

void rearrange(){
	//벽돌 재배치
	for (int j = 0; j < W; ++j){
		for (int i = H - 2; i >= 0; --i){
			if (!cp[i][j])
				continue;
			if (cp[i][j] > 0){
				int x = i;
				if (cp[x + 1][j] == 0){
					while (x < H - 1 && cp[x + 1][j] == 0){
						x++;
					}
					cp[x][j] = cp[i][j];
					cp[i][j] = 0;
				}
			}
		}
	}
}

void block(int x, int y){
	int cnt = cp[x][y];
	cp[x][y] = 0;
	for (int i = 0; i < 4; ++i){
		int nx = x;
		int ny = y;
		for (int j = 1; j < cnt; ++j){
			nx += dx[i];
			ny += dy[i];

			if (nx >= 0 && nx<H && ny >= 0 && ny<W && cp[nx][ny] == 0)
				continue;
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && cp[nx][ny] == 1){
				cp[nx][ny] = 0;
			}
			if (nx >= 0 && nx < H && ny >= 0 && ny < W && cp[nx][ny]>1){
				//cp[x][y] = 0;
				block(nx, ny);
			}
		}
	}
}

void dfs(int sel, vector<int>& pick){
	if (sel == 0){
		int cnt = 0;
		//벽돌깨기
		for (int i = 0; i < pick.size(); ++i){
			int x = 0;
			int y = pick[i];

			while (x<H && cp[x][y] == 0){
				x++;
			}

			if (cp[x][y] == 1){
				cp[x][y] = 0;
			}
			else{
				//상,하,좌,우
				block(x, y);
				rearrange();
			}
		}

		//원본 배열 복사
		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				if (cp[i][j] > 0)
					cnt++;
				cp[i][j] = pin[i][j];
			}
		}
		if (res > cnt){
			res = cnt;
			cnt = 0;
		}
		return;
	}

	for (int i = 0; i < W; ++i){
        if(res==0)
           break;
		pick.push_back(i);
		dfs(sel - 1, pick);
		pick.pop_back();
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++){
		vector<int> pick;

		scanf("%d%d%d", &N, &W, &H);

		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				scanf("%d", &pin[i][j]);
				cp[i][j] = pin[i][j];
			}
		}
		dfs(N, pick);
		//최저로 남는 벽돌 개수, 
		printf("#%d %d\n", tc, res);
		res = 987654321;
		init();
	}
}