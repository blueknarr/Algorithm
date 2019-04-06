#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[16][15], map2[16][15], visited[15][15];
int col[3];
int W, H, D;

int abs(int x, int y){
	if (x > y)
		return x - y;
	else
		return y - x;
}

void init(){
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			map[i][j] = map2[i][j];
		}
	}
	
}

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; ++tc){
		scanf("%d%d%d", &W, &H, &D);
		int numOfEnemy = 0, numOfEnemy2 = 0;
		int ans = 0;

		for (int i = 0; i < H; ++i){
			for (int j = 0; j < W; ++j){
				scanf("%d", &map[i][j]);
				if (map[i][j]==1){
					numOfEnemy++;
				}
				map2[i][j] = map[i][j];
			}
		}
		numOfEnemy2 = numOfEnemy;
		//궁수 배치
		for (int i = 0; i < W - 2; ++i){
			for (int j = i + 1; j < W - 1; ++j){
				for (int k = j + 1; k < W; ++k){
					int row = H;
					int cnt = 0;
					col[0] = i;
					col[1] = j;
					col[2] = k;
					
					numOfEnemy = numOfEnemy2;
					while (numOfEnemy){
						//D위치에 있는 적
						vector<pair<int, pair<int,int> > > enemy;
						for (int l = 0; l < H; ++l){
							for (int m = 0; m < W; ++m){
								if (map[l][m] == 0)
									continue;

								//D 범위 안에 있는 좌표만 검색
								for (int p = 0; p < 3; ++p){
									int dist = abs(row, l) + abs(col[p], m);
									if (dist<=D)
										enemy.push_back(make_pair(dist, make_pair(l, m)));
								}
							}
						}
						sort(enemy.begin(), enemy.end());
						
						int size = enemy.size();
						
						//궁수 적군 사격
						vector<pair<int, int> > v;
						for (int l = 0; l < size; ++l){
								int dist = abs(row, enemy[l].second.first) + abs(col[0], enemy[l].second.second);
								if (enemy[l].first == dist){
									v.push_back(make_pair(enemy[l].second.first, enemy[l].second.second));
									cnt++;
									if (visited[enemy[l].second.first][enemy[l].second.second] == 0){
										visited[enemy[l].second.first][enemy[l].second.second] = 1;
										numOfEnemy--;
									}
									break;
								}
						}
						for (int l = 0; l < size; ++l){
							int dist = abs(row, enemy[l].second.first) + abs(col[1], enemy[l].second.second);
							if (enemy[l].first == dist){
								v.push_back(make_pair(enemy[l].second.first, enemy[l].second.second));
								cnt++;
								if (visited[enemy[l].second.first][enemy[l].second.second] == 0){
									visited[enemy[l].second.first][enemy[l].second.second] = 1;
									numOfEnemy--;
								}
								break;
							}
						}
						for (int l = 0; l < size; ++l){
							int dist = abs(row, enemy[l].second.first) + abs(col[2], enemy[l].second.second);
							if (enemy[l].first == dist){
								v.push_back(make_pair(enemy[l].second.first, enemy[l].second.second));
								cnt++;
								if (visited[enemy[l].second.first][enemy[l].second.second] == 0){
									visited[enemy[l].second.first][enemy[l].second.second] = 1;
									numOfEnemy--;
								}
								break;
							}
						}

						//저격 적군 없애기
						for (int l = 0; l < v.size(); ++l){
							map[v[l].first][v[l].second] = 0;
						}

						//적군 이동
						for (int l = H-1; l >=0; --l){
							for (int m = W-1; m>=0; --m){
								visited[l][m] = 0;
								if (l + 1 == H){
									if (map[l][m] == 1){
										numOfEnemy--;
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
					
					//초기화
					init();
				}
			}
		}
		printf("#%d %d\n", tc, ans);
	}
}