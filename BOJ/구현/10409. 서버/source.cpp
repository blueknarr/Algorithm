#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, T,work,total=0,cnt=0;
	cin >> n >> T;
	
	for (int i = 0; i < n; ++i){
		cin >> work;
		total += work;
		
		if (total > T)
			break;
		cnt++;
	}
	cout << cnt << endl;
}