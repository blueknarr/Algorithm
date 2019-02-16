function solution(a, b) {
    var answer = 0;
    var mid=0;
    
    if(a===b){
        return a;
    }else if(a>b){
        for(var i=b+1; i<a; ++i)
            mid+=i;
    }else if(a<b){
        for(var i=a+1; i<b; ++i)
            mid+=i;
    }
    
    return a+mid+b;
}