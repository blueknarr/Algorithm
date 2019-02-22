class Solution {
  public int solution(int n) {
      int answer = 0;
      int dp[] = new int [1000001];
      
      for(int i=2; i*i <= n; ++i){
          if(dp[i]==0)
          {
              for(int j=i+i; j<=n; j+=i)
                  dp[j] = 1;
          }
      }
      for(int i=2; i<=n; ++i){
          if(dp[i]==0){
              answer++;
          }
      }
      return answer;
  }
}