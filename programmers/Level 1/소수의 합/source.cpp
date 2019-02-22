#include <vector>

using namespace std;
int dp[10000001];
long long solution(int N) {
    long long answer = 0;
    
    for(int i=2; i*i<=N; ++i){
        if(!dp[i]){
            for(int j=i+i; j<=N; j+=i)
                dp[j] = 1;
        }
    }
    for(int i=2; i<=N; ++i)
        if(!dp[i])
            answer+=i;
    
    return answer;
}