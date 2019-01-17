#include <iostream>
using namespace std;

int main(){
	int day,number;
	int cnt = 0;
	cin >> day;
	for (int i = 0; i < 5; ++i){
		cin >> number;
		if (day == number)
			cnt++;
	}
	cout << cnt << endl;

}