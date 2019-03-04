#include <cstdio>
int dp[5001];

int main(){
	int n;
	scanf("%d", &n);
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 6; i <= n; ++i){
		if (i % 3 == 0 && i % 5 == 0){
			dp[i] = dp[i - 5] + 1;
			continue;
		}
		if (i % 3 == 0){
			dp[i] = dp[i - 3] + 1;
			continue;
		}
		if (i % 5 == 0){
			dp[i] = dp[i - 5] + 1;
			continue;
		}
		if (dp[i - 3] && dp[i - 5]){
			if (dp[i - 3] + 1 < dp[i - 5] + 1)
				dp[i] = dp[i - 3] + 1;
			else
				dp[i] = dp[i - 5] + 1;
		}
	}
	if (dp[n] == 0)
		dp[n] = -1;

	printf("%d\n", dp[n]);
}