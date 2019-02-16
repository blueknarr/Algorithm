function solution(s){
    var answer = true;
    var p=0,y=0; 
    
    for(var i in s){
        if(s.charAt(i) == 'y' || s.charAt(i) == 'Y'){
            y++;
        }else if(s.charAt(i) == 'p' || s.charAt(i) == 'P'){
            p++;
        }
    }
    if(y!=p)
        answer = false;
    return answer;
}