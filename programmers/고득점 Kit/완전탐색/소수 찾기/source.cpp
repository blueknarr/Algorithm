#include <string>
#include <vector>

using namespace std;

int slice[10];
int slice_cpy[10];
bool check[10000000];
int square[8] = {0,10,100,1000,10000,100000,1000000,10000000};
vector<vector<char>> v;

int solution(string numbers) {
    int size = numbers.length();    
    int answer = 0;

    //소수 찾기
    for(int i=2; i*i< square[size]; ++i){
        if(check[i]==false){
            for(int j=i+i; j<square[size]; j+=i){
                check[j] = true;
            }
        }
    }
    
   for(int i=0; i<numbers.length(); ++i){
       slice[numbers[i]-'0']++;
   }
    
    //문자열로 소수 비교 찾기
    for(int i=2; i<square[size]; ++i){
        if(check[i]==true)
            continue;
        string str = to_string(i);
        bool flag = false;
        
        for(int i=0; i<10; ++i)
            slice_cpy[i] = slice[i];
    
        for(int j=0; j<str.length(); ++j){
            if(slice_cpy[str.at(j)-'0']==0){
                flag = true;
                break;
            }
            slice_cpy[str.at(j)-'0']--;
        }
        if(!flag){
            answer++;
        }
    }
    return answer;
}