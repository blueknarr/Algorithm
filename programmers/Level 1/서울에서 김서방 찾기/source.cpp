#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    int loc=10;
    for(int i=0; i<seoul.size(); ++i){
        if(!seoul[i].compare("Kim")){
            loc=i;
            break;
        }
    }
    answer.append(to_string(loc));
    answer.append("에 있다");
    cout << answer << endl;
    return answer;
}