#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool check[200];

void dfs(int node, vector<vector<int>> v){
	check[node] = true;
	
	for (int i = 0; i<v[node].size(); ++i){
		if (check[v[node][i]] == false){
			dfs(v[node][i], v);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int row = computers.size();
	int col = computers[0].size();
	vector<vector<int> > v(row);

	for (int i = 0; i<row; ++i){
		for (int j = 0; j<col; ++j){
			if (i == j)
				continue;
			if (computers[i][j])
				v[i].push_back(j);
		}
	}

	for (int i = 0; i<row; ++i){
		if (check[i] == false){
			answer++;
			dfs(i, v);
		}
	}
	return answer;
}