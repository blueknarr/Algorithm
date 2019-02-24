#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.length();
    if(length == 1)
    {
        answer.append(s);
    }else if(length%2==0){
        answer.append(s,(length-1)/2,2);
    }else {
        answer.append(s,(length-1)/2,1);
    }
    return answer;
}