#include <cstdio>
#include <vector>
using namespace std;
int dp[1001];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> v;
	for (int i = 2; i <= n; ++i){
		if (!dp[i])
			v.push_back(i);
		for (int j = i + i; j <= n; j += i){
			if (!dp[j]){
				dp[j] = 1;
				v.push_back(j);
			}
		}
	}
	printf("%d\n", v[k - 1]);
}