#include <vector>
#include <algorithm>
using namespace std;
int dp[500][500];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int lastRow = triangle.size() - 1;
	dp[0][0] = triangle[0][0];

	for (int i = 0; i<triangle.size() - 1; ++i){
		for (int j = 0; j<triangle[i].size(); ++j){
			if (dp[i + 1][j] < dp[i][j] + triangle[i+1][j])
				dp[i + 1][j] = dp[i][j] + triangle[i+1][j];
			if (dp[i + 1][j + 1] = dp[i][j] + triangle[i+1][j+1])
				dp[i + 1][j + 1] = dp[i][j] + triangle[i+1][j+1];
		}
	}
	for (int i = 0; i<triangle[lastRow].size(); ++i){
		answer = max(answer, dp[lastRow][i]);
	}
	return answer;
}