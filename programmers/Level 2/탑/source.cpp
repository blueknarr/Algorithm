#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int size = heights.size();
    
    vector<int> answer(size);
    for(int i=size-1; i>0; --i){
        int flag = 1;
        for(int j=i-1; j>=0; --j){
            if(heights[i] < heights[j]){
                answer[i] = j+1;
                flag=0;
                break;
            }
        }
        if(flag==1)
            answer[i]=0;
    }
    answer[0]=0;
    return answer;
}