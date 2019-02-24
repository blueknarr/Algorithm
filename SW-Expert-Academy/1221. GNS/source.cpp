#include <iostream>
#include <string>
#include <vector>
using namespace std;

char gns[10][4] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

int main(){
	freopen("input.txt", "r", stdin);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc){
		int num[10] = { 0, };
		string order;
		int n;
		string str;
		cin >> order >> n;
		for (int i = 0; i < n; ++i){
			cin >> str;

			for (int j = 0; j < 10; ++j){
				if (!str.compare(gns[j]))
					num[j]++;
			}
		}
		cout << order << endl;

		for (int i = 0; i < 10; ++i){
			while (num[i]){
				cout << gns[i] << ' ';
				num[i]--;
			}
		}	
	}
	return 0;
}