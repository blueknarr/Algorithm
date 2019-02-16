#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long mid=0;
    if(a==b)
        answer = 3;
    else if(a>b){
        for(int i=b+1; i<a; ++i)
            mid+=i;
        answer = a+mid+b;
    }else if(b>a){
        for(int i=a+1; i<b; ++i)
            mid+=i;
        answer = a+mid+b;
    }
    
    return answer;
}