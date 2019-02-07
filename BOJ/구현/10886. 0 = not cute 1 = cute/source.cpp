#include <iostream>
#include <string>
using namespace std;

int main(){
	int vote[2] = { 0, };
	int tc, opinion;
	string s;
	cin >> tc;
	for (int i = 0; i < tc; ++i){
		cin >> opinion;
		vote[opinion]++;
	}

	if (vote[0]>vote[1]){
		s="Junhee is not cute!";
	}
	else{
		s = "Junhee is cute!";
	}

	cout << s << endl;
}