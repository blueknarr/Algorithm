#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    
    for(int i=0; i<size; ++i){
        int cnt = 0;
        for(int j=i; j<size-1; ++j){
            if(prices[i] <= prices[j] ){
                cnt++;
            }else{
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}