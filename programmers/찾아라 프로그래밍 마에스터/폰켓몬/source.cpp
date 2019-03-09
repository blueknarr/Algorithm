#include <vector>
#include <iostream>
using namespace std;
int pokemon[200001];

int solution(vector<int> nums)
{
	int answer = 0;
    int lastPokemon=0;
    int maxValue = nums.size() / 2;
    for(int i=0; i<nums.size(); ++i){
        pokemon[nums[i]]++;
        if(nums[i]>lastPokemon)
            lastPokemon = nums[i];
    }
    
    for(int i=1; i<=lastPokemon; ++i){
        if(answer == maxValue)
            break;
        if(pokemon[i]){
            answer++;
        }
    }
	return answer;
}