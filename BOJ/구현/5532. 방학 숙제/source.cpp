#include <iostream>
using namespace std;

int main(){
	int L, A, B, C, D;
	int math = 0, korean = 0,day=0;
	cin >> L >> A >> B >> C >> D;

	math = A / C;
	if (A%C > 0)
		math += 1;
	korean = B / D;
	if (B%D > 0)
		korean += 1;

	day = (math > korean) ? math : korean;
	cout << L - day << endl;
}