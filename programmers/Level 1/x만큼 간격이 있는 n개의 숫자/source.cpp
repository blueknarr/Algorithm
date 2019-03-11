#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long number=0;
    while(n--){
        number+=x;
        answer.push_back(number);
    }
    
    return answer;
}