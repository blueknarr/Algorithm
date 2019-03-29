#include <vector>
using namespace std;
bool check[3001];
int ans;
void isPrime(vector<int>& nums, int picked, int sum,int index){
	if (picked == 3){
		if (check[sum] == false)
			ans++;
		return;
	}

	if (index > nums.size() - 1)
		return;

	isPrime(nums, picked + 1, sum + nums[index],index+1);
	isPrime(nums, picked, sum,index+1);
}

int solution(vector<int> nums) {
	for (int i = 2; i*i<3001; ++i){
		if (check[i] == false){
			for (int j = i + i; j<3001; j +=i){
				check[j] = true;
			}
		}
	}

	isPrime(nums,0,0,0);

	return ans;
}