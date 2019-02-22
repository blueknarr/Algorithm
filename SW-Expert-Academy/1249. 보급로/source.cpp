#include <iostream>
#include <stdio.h>
#define MAX_N 1000
#define INF 987654321
int Map[MAX_N][MAX_N];
int Dist[MAX_N];
int N, M;

int dijkstra(int start, int end){
	bool visited[MAX_N] = { false };
	for (int i = 0; i < N; ++i)
		Dist[i] = INF;
	Dist[start] = 0;

	for (int i = 0; i < N; ++i){
		int minCost = INF, minVertex;
		for (int j = 0; j < N; ++j){
			if (!visited[j] && Dist[j] < minCost){
				minCost = Dist[j];
				minVertex = j;
			}
		}
		visited[minVertex] = true;
		for (int j = 0; j < N; ++j){
			if (Dist[j] > Map[minVertex][j] + Dist[minVertex])
				Dist[j] = Map[minVertex][j] + Dist[minVertex];
		}
	}
	return Dist[end];
}

int main(){
	
	int start, end;
	
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N,&M);

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			Map[i][j] = INF;
		}
	}

	for (int i = 0; i < M; ++i){
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		Map[a-1][b-1] = cost;
	}
	scanf("%d%d", &start, &end);
	printf("%d\n", dijkstra(start-1, end-1));
}