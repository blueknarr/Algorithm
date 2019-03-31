#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M,res=987654321;
int check[50];
int map[50][50];

int dfs(int pick, int index, vector<pair<int, int> >& house, vector<pair<int, int> >& chicken){
	if (index > chicken.size())
		return 0;

	if (pick == M){
		int sum = 0;
		for (int i = 0; i < house.size(); ++i){
			int dist = 987654321;
			for (int j = 0; j < chicken.size(); ++j){
				if (check[j] == 0)
					continue;
				
				int hx = house[i].first;
				int hy = house[i].second;
				int cx = chicken[j].first;
				int cy = chicken[j].second;

				int d = abs(hx - cx) + abs(hy - cy);
				dist = min(dist,d);
			}
			sum += dist;
		}
		res = min(res, sum);
		return 0;
	}

	check[index] = 1;
	dfs(pick + 1, index + 1, house, chicken);
	check[index] = 0;

	dfs(pick, index + 1, house, chicken);
	return 0;
}

int main(){
	scanf("%d%d", &N, &M);
	vector<pair<int, int> > house;
	vector<pair<int, int> > chicken;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1){
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2){
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	dfs(0, 0,house,chicken);
	printf("%d", res);

}