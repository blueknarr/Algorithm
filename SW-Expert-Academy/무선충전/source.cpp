#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct ap{
	int x, y;
	int c;
	int p;
};

struct user{
	int x, y;
	int sum;
	int p;
	int move[100];
};

int map[11][11];
int M, A;

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		int res = 0;
		//M 종료조건
		scanf("%d%d", &M, &A);

		struct user user[2] = { 0, };
		user[0].x = user[0].y = 1;
		user[1].x = user[1].y = 10;
		for (int i = 0; i < 2; ++i){
			for (int j = 0; j < M; ++j){
				scanf("%d", &user[i].move[j]);
			}
		}

		struct ap ap[8] = { 0, };
		for (int i = 0; i < A; ++i){
			scanf("%d%d%d%d", &ap[i].y, &ap[i].x, &ap[i].c, &ap[i].p);
		}

		for (int i = 0; i <= M; ++i){
			int same = 0;
			int idx = 0;
			//A 현재 위치에서 전체 ap 탐색
			vector<int> BC_A;
			for (int j = 0; j < A; ++j){
				int distance = dist(user[0].x, user[0].y, ap[j].x, ap[j].y);
				if (distance <= ap[j].c)
					BC_A.push_back(j);
			}

			//B 현재 위치에서 전체 ap탐색 후 겹치는 ap 검사
			vector<int> BC_B;
			for (int j = 0; j < A; ++j){
				int distance = dist(user[1].x, user[1].y, ap[j].x, ap[j].y);
				if (distance <= ap[j].c)
					BC_B.push_back(j);
			}

			for (int j = 0; j < BC_A.size(); ++j){
				for (int k = 0; k < BC_B.size(); ++k){
					if (BC_A[j] == BC_B[k])
						same++;
				}
			}

			if (same > 0){
				int max = 0;
				int prevA = 0;
				int prevB = 0;
				for (int j = 0; j < BC_A.size(); ++j){
					int val = 0;
					for (int k = 0; k < BC_B.size(); ++k){
						if (BC_A[j] == BC_B[k]){
							user[0].p = user[1].p = ap[BC_A[j]].p / 2;
							val = user[0].p + user[1].p;
						}
 						else{
							user[0].p = ap[BC_A[j]].p;
							user[1].p = ap[BC_B[k]].p;
							val = user[0].p + user[1].p;
						}
						if (max < val){
							max = val;
							user[0].sum += user[0].p-prevA;
							user[1].sum += user[1].p-prevB;
							prevA = user[0].p;
							prevB = user[1].p;
						}
					}
				}
			}
			else{
				int p = 0;
				
				for (int j = 0; j < BC_A.size(); ++j){
					if (p < ap[BC_A[j]].p)
						p = ap[BC_A[j]].p;
				}
				user[0].p = p;
				user[0].sum += p;
				
				p = 0;
				for (int j = 0; j < BC_B.size(); ++j){
					if (p < ap[BC_B[j]].p){
						p = ap[BC_B[j]].p;
					}
				}
				user[1].p = p;
				user[1].sum += p;
			}

			//A,B 좌표 수정
			if (i < M){
				for (int j = 0; j < 2; ++j){
					if (user[j].move[i] == 1){//up
						user[j].x -= 1;
					}
					else if (user[j].move[i] == 2){//right
						user[j].y += 1;
					}
					else if (user[j].move[i] == 3){//down
						user[j].x += 1;
					}
					else if (user[j].move[i] == 4){//left
						user[j].y -= 1;
					}
				}
			}
		}
		res = user[0].sum + user[1].sum;
		printf("#%d %d\n", tc, res);


	}
}