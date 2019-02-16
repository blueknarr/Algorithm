function solution(arr) {
    var answer = 0;
    var length = arr.length;
    
    for(var i=0; i<length; ++i)
        answer+=arr[i];
    
    return answer/length;
}