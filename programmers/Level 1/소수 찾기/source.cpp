#include <string>
#include <vector>
int dp[1000001];
using namespace std;

int solution(int n) {
    int answer = 0;

    for(int i=2; i*i<=n; ++i){
        if(!dp[i]){
            for(int j=i+i; j<=n; j+=i){
                dp[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; ++i){
        if(!dp[i])
            answer++;
    }
    return answer;
}