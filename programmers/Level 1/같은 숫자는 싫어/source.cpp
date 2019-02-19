#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int n = arr.size();
    int check = 10;
    for(int i=0; i<n; ++i){
        if(check != arr[i]){
            answer.push_back(arr[i]);
            check = arr[i];
        }
    }
    return answer;
}