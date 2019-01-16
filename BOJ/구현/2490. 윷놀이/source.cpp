#include <iostream>
using namespace std;

char result[5] = { 'E', 'A', 'B', 'C', 'D' };

int main(){
	
	int stick = 0;
	for (int tc = 0; tc < 3; ++tc){
		int zero = 0;
		for (int i = 0; i < 4; ++i){
			cin >> stick;
			if (stick == 0)
				zero++;
		}
		cout << result[zero] << endl;
	}
}