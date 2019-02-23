#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int low = 987654321;
    int index = 0;
    if(arr.size() == 1){
        answer.push_back(-1);
    }else{
        for(int i=0; i<arr.size(); ++i){
            if(arr[i] < low){
                low = arr[i];
                index = i;
            }
        }
        
        for(int i=0; i<index; ++i)
            answer.push_back(arr[i]);
        for(int i=index+1; i<arr.size(); ++i)
            answer.push_back(arr[i]);
    }
    return answer;
}