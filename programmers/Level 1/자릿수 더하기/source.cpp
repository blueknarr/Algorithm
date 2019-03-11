#include <string>
using namespace std;
int solution(int n)
{
	int answer = 0;
	int dp[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };
	string str = to_string(n);
	int num = str.length();

	while (num--){
		answer += n / dp[num];
		n %= dp[num];
	}

	return answer;
}