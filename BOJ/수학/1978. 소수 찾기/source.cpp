#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; ++i){
		if (n%i == 0)
			return false;
	}
	return true;
}

int main(){
	int N,ans=0;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; ++i){
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < N; ++i){
		if (isPrime(v[i])){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}