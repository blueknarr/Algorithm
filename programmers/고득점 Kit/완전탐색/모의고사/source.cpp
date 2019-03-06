#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    int p1[5] = {1,2,3,4,5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10] ={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int p1_ans=0, p2_ans=0, p3_ans=0;
    vector<int> answer;
    
    for(int i=0; i<answers.size(); ++i){
        if(p1[i%5] == answers[i])
            p1_ans++;
        if(p2[i%8] == answers[i])
            p2_ans++;
        if(p3[i%10] == answers[i])
            p3_ans++;
    }
   
    if(p1_ans == p2_ans && p2_ans == p3_ans){
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }else if(p1_ans == p2_ans && p1_ans != 0){
        answer.push_back(1);
        answer.push_back(2);
    }else if(p1_ans == p3_ans && p1_ans != 0){
        answer.push_back(1);
        answer.push_back(3);
    }else if(p2_ans == p3_ans && p2_ans != 0){
        answer.push_back(2);
        answer.push_back(3);
    }else{
       int index = max(p1_ans,max(p2_ans,p3_ans));
       if(p1_ans == index){
           answer.push_back(1);
       }else if(p2_ans == index){
           answer.push_back(2);
       }else if(p3_ans == index){
           answer.push_back(3);
       }
    }
    return answer;
}