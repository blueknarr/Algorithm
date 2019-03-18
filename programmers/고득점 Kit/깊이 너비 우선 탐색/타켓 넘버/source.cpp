#include <string>
#include <vector>

using namespace std;
int check[20];
int size,cnt,ans;
int dfs(vector<int>& numbers, int target){
	int sum = 0;
	for (int i = 0; i < size; ++i){
		if (check[i] == 0){
			sum -= numbers[i];
		}
		else{
			sum += numbers[i];
		}
	}
	return sum;
}

int solution(vector<int> numbers, int target) {
	size = numbers.size();
	if (cnt == size){
		int n = dfs(numbers, target);
		if (n == target)
			ans++;
		return 0;
	}
	for (int i = 0; i < 2; ++i){
		check[cnt++] = i;
		solution(numbers, target);
		cnt--;
	}
	return ans;
}