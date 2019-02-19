function solution(n) {
    var answer = 0;
    
    for(var i=1; i<=n; ++i){
        var sum=0;
        for(var j=i; j<=n; ++j){
            if(sum>n)
                break;
            sum+=j;
            if(sum===n)
                answer++;
        }
    }
    return answer;
}