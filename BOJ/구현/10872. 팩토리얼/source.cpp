#include <iostream>
using namespace std;

long long int dp[13];

long long int factorial(int n){
	dp[0] = 1;
    dp[1] = 1;
	for (int i = 1; i <= n; ++i){
		dp[i] = i*dp[i - 1];
	}
	return dp[n];
}

int main(){
	int N;
	
	cin >> N;
	cout << factorial(N) << endl;
	
}