#include <iostream>
#include <vector>
using namespace std;

int firstCode[6] = { 5000000, 3000000, 2000000, 500000, 300000, 100000 };
int secondCode[5] = {5120000, 2560000, 1280000, 640000, 320000};
int N;

int main(){
	int a, b;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; ++i){
		int total = 0;
		cin >> a >> b;

		if (a + b == 0){
			v.push_back(total);
			continue;
		}

		if (a == 1){
			total = firstCode[0];
		}
		else if (a == 2 || a == 3){
			total = firstCode[1];
		}
		else if (a >= 4 && a <= 6){
			total = firstCode[2];
		}
		else if (a >= 7 && a <= 10){
			total = firstCode[3];
		}
		else if (a >= 11 && a <= 15){
			total = firstCode[4];
		}
		else if (a >= 16 && a <= 21){
			total = firstCode[5];
		}
		
		if (b == 1){
			total += secondCode[0];
		}
		else if (b == 2 || b == 3){
			total += secondCode[1];
		}
		else if (b >= 4 && b <= 7){
			total += secondCode[2];
		}
		else if (b >= 8 && b <= 15){
			total += secondCode[3];
		}
		else if (b >= 16 && b <= 31){
			total += secondCode[4];
		}

		v.push_back(total);
	}
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
}
