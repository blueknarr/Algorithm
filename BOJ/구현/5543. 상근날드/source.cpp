#include <iostream>
using namespace std;

int main(){
	int price = 0, minBurger = 2001, minDrink = 2001;

	for (int i = 0; i < 5; ++i){
		cin >> price;
		if (i < 3){
			if (minBurger > price)
				minBurger = price;
		}
		else{
			if (minDrink > price)
				minDrink = price;
		}
	}
	cout << minBurger + minDrink - 50 << endl;
}