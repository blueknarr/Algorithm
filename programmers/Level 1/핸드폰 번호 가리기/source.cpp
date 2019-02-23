#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
    string answer= "";
    
    int size = phone_number.length();
    
    for(int i=0; i<size-4; ++i)
        answer.append("*");
    answer.append(phone_number,size-4,size);
    return answer;
}