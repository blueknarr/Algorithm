#include <iostream>

using namespace std;

int main(){
	int T;
	int r, e, c;
	cin >> T;

	for (int tc = 0; tc < T; ++tc){
		cin >> r >> e >> c;
		if (r < e - c){
			cout << "advertise" << endl;
		}
		else if (r == e - c){
			cout << "does not matter" << endl;
		}
		else{
			cout << "do not advertise" << endl;
		}
	}
}