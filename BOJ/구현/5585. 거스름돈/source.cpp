#include <iostream>
using namespace std;

int main(){
	int money = 1000;
	int cnt = 0;
	int remainder;
	cin >> remainder;
	money -= remainder;
	
	while (money != 0){
		if (money >= 500){
			money -= 500;
			cnt++;
		}
		else if (money >= 100){
			money -= 100;
			cnt++;
		}
		else if (money >= 50){
			money -= 50;
			cnt++;
		}
		else if (money >= 10){
			money -= 10;
			cnt++;
		}
		else if (money >= 5){
			money -= 5;
			cnt++;
		}
		else if (money >= 1){
			money -= 1;
			cnt++;
		}
	}
	cout << cnt << endl;
	
}