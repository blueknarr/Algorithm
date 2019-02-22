#include <iostream>
using namespace std;
#define MAX 100
int dp[1000001];

int main(){
	dp[0] = dp[1] = 1;

	for (int i = 2; i*i <= MAX; ++i){
		if (!dp[i]){
			for (int j = i + i; j <= MAX; j += i){
				dp[j] = 1;
			}
		}
	}

	for (int i = 2; i <= MAX; ++i){
		if (!dp[i])
			cout << i << ' ';
	}
	cout << endl;
}