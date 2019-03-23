#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[6] = {0,1,10,100,1000,10000};
bool solution(int x) {
    bool answer = true;
    string number = to_string(x);
    int length = number.size();
    int num = x;
    int sum=0;
    while(length){
        if(x>9){
           sum += x/dp[length];
            x = x%dp[length];
        }else{
            sum+=x;
        }
        length--;
    };
    if(num%sum)
        answer=false;
    return answer;
}