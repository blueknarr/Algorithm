#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[100][100], visited[100][100];
int N,index;
struct node{
	int val;
	int x;
	int y;
	node(){}
	node(int _val,int _x, int _y) : val(_val),x(_x), y(_y){}
}res[100];

int main(){
	//freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		vector < pair<int, pair<int, int>> > v;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				visited[i][j] = 0;
			}
		}
		index = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){

				int row = 0, col = 0;
				if (map[i][j] == 0 || visited[i][j] > 0)
					continue;
				if (map[i][j]>0){
					while (map[i][j+col]){
						visited[i][j+col] = 1;
						col += 1;
					}
					while (map[i+row][j]){
						visited[i+row][j] = 1;
						row += 1;
					}
					if (row > 1 && col > 1){
						for (int a = 0; a < row-1; ++a){
							for (int b = 0; b < col - 1; ++b){
								visited[i+ a + 1][j+ b + 1] = 1;
							}
						}
					}
					v.push_back(make_pair(row*col, make_pair(row, col)));
				}
			}
		}
		printf("#%d %d", tc,v.size());
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i){
			printf(" %d %d", v[i].second.first,v[i].second.second);
		}
		printf("\n");
	}
}