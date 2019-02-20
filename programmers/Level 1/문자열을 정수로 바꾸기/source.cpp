#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if(s.at(0) == '-'){
        answer -= stoi(s.substr(1,s.size()-1));
    }else{
        answer =  stoi(s);
    }
    
    return answer;
}