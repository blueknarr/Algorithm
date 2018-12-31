#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define MAX_N 100
int magnetic[MAX_N][MAX_N];

int main(){
	//freopen("input.txt", "r", stdin);
	int T=10;
	for (int test_case = 1; test_case <= T; ++test_case){
		int n;
		int count=0;
		queue<pair<int, int> > q;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				scanf("%d", &magnetic[i][j]);
				if (magnetic[i][j] == 1)
					q.push(make_pair(i, j));
			}
		}

		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			while (x < n){
				x++;
				if (magnetic[x][y] == 1)
					break;
				if (magnetic[x][y] == 2){
					count++;
					break;
				}
			}
		}
		printf("#%d %d\n", test_case, count);
	}
}