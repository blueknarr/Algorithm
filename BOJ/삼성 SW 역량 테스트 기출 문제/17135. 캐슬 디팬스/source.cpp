#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M,D;
int map[16][15], map2[16][15];

int abs(int x, int y){
	if (x > y)
		return x - y;
	else
		return y - x;
}

struct distance{
	int dist1;
	int dist2;
	int dist3;
};

struct point{
	int x;
	int y;
};

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &D);

	int isEnemy = 0;
	int ans = 0;
	
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%d", &map[i][j]);
			map2[i][j] = map[i][j];
			if (map[i][j] == 1)
				isEnemy++;
		}
	}
	//궁수 3명 배치 방법
	for (int i = 0; i < M - 2; ++i){
		for (int j = i + 1; j < M - 1; ++j){
			for (int k = j + 1; k < M; ++k){
				
				int cnt = 0;
				int isEnemy2 = isEnemy;
				while (isEnemy2)
				{
					//D 거리 안에 있는 적을 찾는다.
					//최소 거리 좌표 
					struct point point[3];
					for (int l = 0; l < 3; ++l){
						point[l].x = point[l].y = N;
					}
					//궁수별 최소 거리 
					struct distance dist[16][15] = { 0, };
					
					for (int l = N - 1; l >= 0; --l){
						for (int m = 0; m < M; ++m){
							if (map[l][m] == 0)
								continue;
							//N, i,j,k
							dist[l][m].dist1 = abs(l,N) + abs(m,i);
							dist[l][m].dist2 = abs(l,N) + abs(m,j);
							dist[l][m].dist3 = abs(l,N) + abs(m,k);
						}
					}
					
					int D1 = D, D2 = D, D3 = D;
					int col1 = M - 1, col2 = M - 1, col3 = M - 1;
					
					for (int l = N - 1; l >= 0; --l){
						for (int m = 0; m < M; ++m){
							//궁수1
							if (dist[l][m].dist1 !=0){
								if (dist[l][m].dist1 < D1){
									D1 = dist[l][m].dist1;
									point[0].x = l;
									point[0].y = m;
								}
								else if (dist[l][m].dist1 == D1){
									D1 = dist[l][m].dist1;
									if (col1 >= m){
										col1 = m;
										point[0].x = l;
										point[0].y = m;
									}
								}
							}
							//궁수2
							if (dist[l][m].dist2 != 0){
								if (dist[l][m].dist2 < D2){
									D2 = dist[l][m].dist2;
									point[1].x = l;
									point[1].y = m;
								}
								else if (dist[l][m].dist2 == D2){
									D2 = dist[l][m].dist2;
									if (col2 >= m){
										col2 = m;
										point[1].x = l;
										point[1].y = m;
									}
								}
							}
							//궁수3
							if (dist[l][m].dist3 != 0){
								if (dist[l][m].dist3 < D3){
									D3 = dist[l][m].dist3;
									point[2].x = l;
									point[2].y = m;
								}
								else if (dist[l][m].dist3 == D3){
									D3 = dist[l][m].dist3;
									if (col3 >= m){
										col3 = m;
										point[2].x = l;
										point[2].y = m;
									}
								}	
							}
						}
					}

					for (int l = 0; l < 3; ++l){
						if (map[point[l].x][point[l].y] == 1){
							cnt++;
							isEnemy2--;
							map[point[l].x][point[l].y] = 0;
						}
					}


					//적이 한칸 아래로 움직임
					for (int l = N - 1; l >= 0; --l){
						for (int m = M - 1; m >= 0; --m){
							if (l + 1 == N){
								if (map[l][m] == 1){
									isEnemy2--;
									map[l][m] = 0;
								}
								
							}
							map[l + 1][m] = map[l][m];
							map[l][m] = 0;
						}
					}

				}
				if (cnt > ans)
					ans = cnt;
				//적 찾기 종료
				for (int l = 0; l < N; ++l){
					for (int m = 0; m < M; ++m){
   						map[l][m] = map2[l][m];
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}