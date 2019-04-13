#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
char map[11][11];
int dir[10];
int N, M, ans=11;

struct point{
	int bx;
	int by;
	int rx;
	int ry;
};

void game(){
	char map2[11][11];
	struct point p;
	memcpy(map2, map, sizeof(map));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			if (map[i][j] == 'R')
				p.rx = i, p.ry = j;
			if (map[i][j] == 'B')
				p.bx = i, p.by = j;
		}
	}
	//가장 바깥 행과 열은 모두 막혀져 있고
	// 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안된다.
 
	//빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다
	
	//총 10번 방향을 바꿈
	//0: 북, 1: 동, 2: 남, 3: 서
	//dir[0] = 3;

	int t = 0;
	bool flag_red = false, flag_blue = false;
	for (int i = 0; i < 10; ++i){
		t++;
 		if (dir[i] == 0){
			//0:북, 아래에서 위로
			//빨간공, 파란공 같은 열
			if (p.ry == p.by){
				for (int i = 0; i < N - 1; ++i){
					if (map2[i][p.ry] == 'R'){
						int x = i;
						map2[x][p.ry] = '.';
						while (map2[x - 1][p.ry] != '#' && map2[x - 1][p.ry] != 'B'){
							p.rx = --x;
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
					else{
						if (map2[i][p.ry] == 'B'){
							int x = i;
							map2[x][p.by] = '.';
							while (map2[x - 1][p.by] != '#' && map2[x - 1][p.ry] != 'R'){
								p.bx = --x;
								if (map2[p.bx][p.by] == 'O'){
									flag_blue = true;
									break;
								}
							}
							if (!flag_blue)
								map2[p.bx][p.by] = 'B';
						}
					}
				}
			}
			else
			{
				//빨간공
				for (int i = 0; i < N - 1; ++i)
				{
					if (map2[i][p.ry] == 'R'){
						int x = i;
						map2[x][p.ry] = '.';
						while (map2[x - 1][p.ry] != '#'){
							p.rx = --x;
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
				}
				//파란공
				for (int i = 0; i < N - 1; ++i)
				{
					if (map2[i][p.by] == 'B'){
						int x = i;
						map2[x][p.by] = '.';
						while (map2[x - 1][p.by] != '#'){
							p.bx = --x;
							
							if (map2[p.bx][p.by] == 'O'){
								flag_blue = true;
								break;
							}
						}
						if (!flag_blue)
							map2[p.bx][p.by] = 'B';
					}
				}
			}
		}
		else if (dir[i] == 1){
			//1:동, 왼쪽에서 오른쪽
			if (p.rx == p.bx){//빨간공, 파란공 같은 행
				for (int j = M-2; j >=0; --j){
					if (map2[p.rx][j] == 'R'){
						int y = j;
						map2[p.rx][y] = '.';
						while (map2[p.rx][y + 1] != '#' && map2[p.rx][y + 1] != 'B'){
							p.ry = ++y;
							//O를 만나면 
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
					else{
						if (map2[p.bx][j] == 'B'){
							int y = j;
							map2[p.bx][y] = '.';
							while (map2[p.bx][y + 1] != '#' && map2[p.bx][y + 1] != 'R'){
								p.by = ++y;
								if (map2[p.bx][p.by] == 'O'){
									flag_blue = true;
									break;
								}
							}
							if (!flag_blue)
								map2[p.bx][p.by] = 'B';
						}
					}
				}
			}
			else{
				//빨간공
				for (int j = M-2; j >=0; --j){
					if (map2[p.rx][j] == 'R'){
						int y = j;
						map2[p.rx][y] = '.';
						while (map2[p.rx][y + 1] != '#'){
							p.ry = ++y;
							//O를 만나면 
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
				}
				//파란공
				for (int j = M-2; j >=0; --j){
					if (map2[p.bx][j]=='B'){
						int y = j;
						map2[p.bx][y] = '.';
						while (map2[p.bx][y + 1] != '#'){
							p.by = ++y;
							if (map2[p.bx][p.by] == 'O'){
								flag_blue = true;
								break;
							}
						}
						if (!flag_blue)
							map2[p.bx][p.by] = 'B';
					}
				}
			}
		}
		else if (dir[i] == 2){
			//2: 남, 위에서 아래로
			//빨간공, 파란공 같은 열
			if (p.ry == p.by){
				for (int i = N-2; i >=0; --i){
					if (map2[i][p.ry] == 'R'){
						int x = i;
						map2[x][p.ry] = '.';
						while (map2[x + 1][p.ry] != '#' && map2[x + 1][p.ry] != 'B'){
							p.rx = ++x;
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
					else{
						if (map2[i][p.ry] == 'B'){
							int x = i;
							map2[x][p.by] = '.';
							while (map2[x + 1][p.by] != '#' && map2[x + 1][p.by] != 'R'){
								p.bx = ++x;
								if (map2[p.bx][p.by] == 'O'){
									flag_blue = true;
									break;
								}
							}
							if (!flag_blue)
								map2[p.bx][p.by] = 'B';
						}
					}
				}
			}
			else{
				//빨간공
				for (int i = N - 2; i >= 0; --i){
					if (map2[i][p.ry] == 'R'){
						int x = i;
						map2[x][p.ry] = '.';
						while (map2[x + 1][p.ry] != '#'){
							p.rx = ++x;
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
				}
				//파란공
				for (int i = N - 2; i >= 0; --i){
					if (map2[i][p.by] == 'B'){
						int x = i;
						map2[x][p.by] = '.';
						while (map2[x + 1][p.by] != '#'){
							p.bx = ++x;
							if (map2[p.bx][p.by] == 'O'){
								flag_blue = true;
								break;
							}
						}
						if (!flag_blue)
							map2[p.bx][p.by] = 'B';
					}
				}
			}
		}
		else if (dir[i] == 3){
			//3: 서, 오른쪽에서 왼쪽
			if (p.rx == p.bx){//빨간공, 파란공 같은 행
				for (int j = 1; j < M - 1; ++j){
					if (map2[p.rx][j] == 'R'){
						int y = j;
						map2[p.rx][y] = '.';
						while (map2[p.rx][y - 1] != '#' && map2[p.rx][y - 1] != 'B'){
							p.ry = --y;
							//O를 만나면 
							if (map2[p.rx][p.ry] == 'O'){
								flag_red = true;
								break;
							}
						}
						if (!flag_red)
							map2[p.rx][p.ry] = 'R';
					}
					else{
						if (map2[p.rx][j] == 'B'){
							int y = j;
							map2[p.bx][y] = '.';
							while (map2[p.bx][y - 1] != '#' && map2[p.bx][y - 1] != 'R'){
								p.by = --y;
								if (map2[p.bx][p.by] == 'O'){
									flag_blue = true;
									break;
								}
							}
							if (!flag_blue)
								map2[p.bx][p.by] = 'B';
						}
					}
				}
			}
			else{
				//빨간공
				for (int j = 1; j < M - 1; ++j){
					if (map2[p.rx][j] == 'R'){
						if (map2[p.rx][j] == 'R'){
							int y = j;
							map2[p.rx][y] = '.';
							while (map2[p.rx][y - 1] != '#'){
								p.ry = --y;
								//O를 만나면 
								if (map2[p.rx][p.ry] == 'O'){
									flag_red = true;
									break;
								}
							}
							if (!flag_red)
								map2[p.rx][p.ry] = 'R';
						}
					}
				}
				//파란공
				for (int j = 1; j < M - 1; ++j){
					if (map2[p.bx][j]=='B'){
						int y = j;
						map2[p.bx][y] = '.';
						while (map2[p.bx][y - 1] != '#'){
							p.by = --y;	
							if (map2[p.bx][p.by] == 'O'){
								flag_blue = true;
								break;
							}
						}
						if (!flag_blue)
							map2[p.bx][p.by] = 'B';
					}
				}
			}
		}

		//종료 조건
		//파란 구슬이 구멍에 빠지면 실패
		//빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다
		if (flag_blue){
			//실패
			//ans = 11;
			return;
		}
		else if (flag_red && !flag_blue){
			//성공
			if (t<ans)
				ans = t;
			return;
		}

	}

}

void choose_ball(int index){
	//방향선택 완료
	if (index == 10){
		for (int i = 0; i < 8; ++i){
			if (dir[i] == dir[i + 1])
				return;
		}
		game();
		return;
	}

	//방향 선택
	for (int i = 0; i < 4; ++i){
		dir[index] = i;
		choose_ball(index + 1);
	}

}

int main(){
	//freopen("input.txt", "r", stdin);
	//보드의 세로 크기는 N, 가로 크기는 M
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < N; ++i)
		scanf("%s", &map[i]);

	choose_ball(0);
	if (ans == 11)
		ans = -1;
	printf("%d\n", ans);
}