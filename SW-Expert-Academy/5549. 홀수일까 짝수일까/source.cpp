#include <iostream>
#include <string>
using namespace std;
int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		string str;
		cin >> str;

		if (str[str.length() - 1] % 2 == 1)
			cout << '#' << tc << ' ' << "Odd" << endl;
		else
			cout << '#' << tc << ' ' << "Even" << endl;
	}
}