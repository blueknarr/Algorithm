#include <iostream>
using namespace std;

int main(){
	int totalPrice;
	int total = 0;
	cin >> totalPrice;

	for (int i = 0; i < 9; ++i){
		int bookPrice = 0;
		cin >> bookPrice;
		total += bookPrice;
	}
	cout << totalPrice - total << endl;
}