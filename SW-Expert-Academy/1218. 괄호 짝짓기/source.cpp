#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("sample_input.txt", "r", stdin);
	int T=10;

	for (int tc = 1; tc <= T; ++tc){
		int total=-1,first = 0, second = 0, third = 0, fourth = 0;
		int n;
		cin >> n;

		string str;
		cin >> str;

		for (int i = 0; i < n; ++i){
			if ( (first < 0 || second < 0  || third < 0  || fourth < 0))
				break;
			
			if (str.at(i) == '('){
				first++;
				continue;
			}
			else if (str.at(i) == ')'){
				first--;
				continue;
			}
			if (str.at(i) == '['){
				second++;
				continue;
			}
			else if (str.at(i) == ']'){
				second--;
				continue;
			}
			if (str.at(i) == '{'){
				third++;
				continue;
			}
			else if (str.at(i) == '}'){
				third--;
				continue;
			}
			if (str.at(i) == '<'){
				fourth++;
				continue;
			}
			else if (str.at(i) == '>'){
				fourth--;
				continue;
			}
		}
		if ((first == 0 && second == 0 && third == 0 && fourth == 0))
			cout << '#' << tc << ' ' << true << endl;
		else
			cout << '#' << tc << ' ' << false << endl;
	}
}