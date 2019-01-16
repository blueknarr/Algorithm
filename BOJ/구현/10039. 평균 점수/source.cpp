#include <iostream>

using namespace std;

int main(){
	int score = 0;
	int totalScore = 0;
	for (int i = 0; i < 5; ++i){
		cin >> score;
		if (score < 40){
			score = 40;
		}
		totalScore += score;
	}
	cout << totalScore / 5 << endl;
}