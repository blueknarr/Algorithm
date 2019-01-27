#include <iostream>
using namespace std;

int main(){
	int total = 0;
	int time;

	for (int i = 0; i < 4; ++i){
		cin >> time;
		total += time;
	}

	cout << total / 60 << endl;
	cout << total % 60 << endl;
}