#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0,y=0;
    
    for(int i=0; i<s.size(); ++i){
        if(s.at(i) == 'y' || s.at(i) == 'Y'){
            y++;
        }else if(s.at(i)=='p' || s.at(i) == 'P'){
            p++;
        }
    }
    if(p != y)
        answer = false;
    return answer;
}