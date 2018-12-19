#include <iostream>
#include <stdio.h>
#include <queue>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct node{
	int cctv;
	int dir;
	node(){};
	node(int _cctv, int _dir) : cctv(_cctv), dir(_dir){};
};
int map[8][8], visited[8][8];
int H, W, K, res,wall;


void countEmptySpace(){
	int zero = 0;
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			if (!visited[i][j])
				zero++;
		}
	}
	zero -= wall;
	if (res > zero)
		res = zero;
}

void initVisited(){
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			visited[i][j] = 0;
		}
	}
}
void update(vector<node> &v){
	int num = 0;
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			if (map[i][j] == 1){ //1번 cctv
				if (v[num].dir == 0){//0
					//right
					int y = j;
					while (y<W && map[i][y] !=6){
						visited[i][y]++;
						y++;
					}
				}
				else if (v[num].dir == 1){//90
					//down
					int x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
				}
				else if (v[num].dir == 2){//180
					//left
					int y = j;
					while (y>=0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
				}
				else if (v[num].dir == 3){//270
					//up
					int x = i;
					while (x >=0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
				}
				num++;
			}
			if (map[i][j] == 2){//2번 cctv
				if (v[num].dir == 0 || v[num].dir == 2){//0
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
					//left
					y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
				}
				else if (v[num].dir == 1 || v[num].dir == 3){//90
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					//down
					x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
				}
				num++;
			}
			if (map[i][j] == 3){//3번 cctv
				if (v[num].dir == 0){//0
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
				}
				else if (v[num].dir == 1){//90
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
					//down
					int x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
				}
				else if (v[num].dir == 2){//180
					//down
					int x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
					//left
					int y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
				}
				else if (v[num].dir == 3){//270
					//left
					int y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
				}
				num++;
			}
			if (map[i][j] == 4){//4번 cctv
				if (v[num].dir == 0){//0
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
					//down
					x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
				}
				else if (v[num].dir == 1){//90
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
					//down
					int x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
					//left
					y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
				}
				else if (v[num].dir == 2){//180
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					//left
					int y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
					//down
					x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
				}
				else if (v[num].dir == 3){//270
					//left
					int y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
					//up
					int x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					//right
					y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
				}
				num++;
			}
			if (map[i][j] == 5){//5번 cctv
				if (v[num].dir == 0 || v[num].dir == 1 || v[num].dir == 2 || v[num].dir == 3){//0
					//right
					int y = j;
					while (y<W && map[i][y] != 6){
						visited[i][y]++;
						y++;
					}
					//down
					int x = i;
					while (x < H && map[x][j] != 6){
						visited[x][j]++;
						x++;
					}
					//left
					y = j;
					while (y >= 0 && map[i][y] != 6){
						visited[i][y]++;
						y--;
					}
					//up
					x = i;
					while (x >= 0 && map[x][j] != 6){
						visited[x][j]++;
						x--;
					}
					num++;
				}
			}
		}
	}
	//res count
	countEmptySpace();
	//initVisited
	initVisited();
}

void dfs(int cnt, vector<node> &v){

	if (cnt == v.size()){
		update(v);
		return;
	}

	for (int i = 0; i < 4; ++i){
		v[cnt].dir = i;
		dfs(cnt + 1,v);
	}
}

int main(){
	//freopen("sample_input.txt", "r", stdin);
		vector<node> v;
		scanf("%d %d", &H, &W);
		K = 0, res = 987654321, wall = 0;;
		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j] != 6 && map[i][j] != 0){
					v.push_back(node(map[i][j], 0));
				}
				if (map[i][j] == 6)
					wall++;
			}
		}
		dfs(0,v);
		printf("%d\n", res);
}