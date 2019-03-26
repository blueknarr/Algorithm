#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    dp[0][0] = answer;
    
    for(int i=1; i<triangle.size(); ++i){
        for(int j=0; j<triangle[i].size(); ++j){
            max(answer+trianle[i][j],answer+trangle[i][j+1]);
        }
    }
    
    return answer;
}