#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc){
		string number;
		int n;
		int cnt = 0;;
		cin >> number >> n;
		
		vector<string> v;
		//v.clear();
		for (int i = 0; i < n; ++i){
			string str;
			cin >> str;
			v.push_back(str);
		}
			
		
		for (int i = 0; i < v.size(); ++i){
			string check;
			for (int j = 0; j < v[i].size(); ++j){
				if (v[i].at(j) == 'a' || v[i].at(j) == 'b' || v[i].at(j) == 'c'){
					check.append("2");
				}
				else if (v[i].at(j) == 'd' || v[i].at(j) == 'e' || v[i].at(j) == 'f'){
					check.append("3");
				}
				else if (v[i].at(j) == 'g' || v[i].at(j) == 'h' || v[i].at(j) == 'i'){
					check.append("4");
				}
				else if (v[i].at(j) == 'j' || v[i].at(j) == 'k' || v[i].at(j) == 'l'){
					check.append("5");
				}
				else if (v[i].at(j) == 'm' || v[i].at(j) == 'n' || v[i].at(j) == 'o'){
					check.append("6");
				}
				else if (v[i].at(j) == 'p' || v[i].at(j) == 'q' || v[i].at(j) == 'r' || v[i].at(j) == 's'){
					check.append("7");
				}
				else if (v[i].at(j) == 't' || v[i].at(j) == 'u' || v[i].at(j) == 'v'){
					check.append("8");
				}
				else if (v[i].at(j) == 'w' || v[i].at(j) == 'x' || v[i].at(j) == 'y' || v[i].at(j) == 'z'){
					check.append("9");
				}
			}
			
			if (!number.compare(check)){
					cnt++;
			}

		}
		cout << '#' << tc << ' ' << cnt << endl;
	}
	return 0;
}