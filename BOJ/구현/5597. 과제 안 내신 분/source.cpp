#include <iostream>
using namespace std;

bool dp[31];

int main(){
	int n;
	for (int i = 0; i < 28; ++i){
		cin >> n;
		dp[n] = true;
	}
	for (int i = 1; i < 31; ++i){
		if (!dp[i])
			cout << i << endl;
	}

}