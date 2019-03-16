#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int count = 500;
    long long number = num;
    while(count){
        if(number==1)
            break;
        
        if(number%2==0){
            number/=2;
        }else{
            number = number*3 +1;
        }
        answer++;
        count--;
    }
    if(!count)
        answer=-1;
    
    return answer;
}