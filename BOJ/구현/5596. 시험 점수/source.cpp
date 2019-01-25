#include <iostream>
using namespace std;

int main(){
	int s=0, t=0, score, res;

	for (int i = 0; i<4; ++i){
		cin >> score;
		s += score;
	}
	for (int i = 0; i<4; ++i){
		cin >> score;
		t += score;
	}

	if (s >= t)
		res = s;
	else
		res = t;
	cout << res << endl;

}