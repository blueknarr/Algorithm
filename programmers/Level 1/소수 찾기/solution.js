function solution(n) {
    var answer = 0;
    var dp = new Array();
    
    for(var i=2; i<=n; ++i)
        dp[i] = 0;

    for(var i=2; i*i<=n; ++i){
        if(dp[i]==0){
            for(var j=i+i; j<=n; j+=i)
                dp[j]=1;
        }
    }

    for(var i=2; i<=n; ++i){
        if(dp[i]==0)
            answer++;
    }
    return answer;
}