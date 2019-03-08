#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int no=0,order=0;
    
    for(int i=1; i<words.size(); ++i){
        string str = words[i];
        bool flag = false;
        
        if(words[i-1].at(words[i-1].length()-1) == str.at(0)){
            //같은 단어인지 한번 더 확인
            for(int j=i-1; j>=0; j--){
                if(!str.compare(words[j])){
                    //같은 문자라면 종료
                    flag=true;
                    break;
                }
            }
        }else{
            //다른 단어라서 종료
            flag = true;
        }
        if(flag){
            no = (i%n) + 1;
            order = (i/n)+1;
            break;
        }
    }
    answer.push_back(no);
    answer.push_back(order);
    return answer;
}