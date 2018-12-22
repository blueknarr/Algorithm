#include <iostream>
#include <stdio.h>

#define MAX_N 100
int Graph[MAX_N][MAX_N];
int visited[MAX_N];
int Stack[200];
int Top;

int main(){
	int start = 0, end = 99;
	int T;
	int totalPath;
	int isPossible;
	//freopen("sample_input.txt", "r", stdin);

	for (int t = 1; t <= 10; ++t){
		scanf("%d%d", &T,&totalPath);

		for (int i = 0; i < MAX_N; ++i){
			visited[i] = 0;
			for (int j = 0; j < MAX_N; ++j){
				Graph[i][j] = 0;
			}
		}
		Top = -1;
		isPossible = 0;
		for (int i = 0; i < totalPath; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			Graph[a][b] = 1;
		}
		Stack[++Top] = start;
		while (Top != -1){
			int cur = Stack[Top--];

			if (!visited[cur]){
				if (visited[end]==1){
					isPossible = 1;
					break;
				}
				visited[cur] = 1;

				for (int next = 0; next < MAX_N; ++next){
					if (!visited[next] && Graph[cur][next])
						Stack[++Top] = next;
				}
			}
		}
		printf("#%d %d\n", t, isPossible);
	}
}