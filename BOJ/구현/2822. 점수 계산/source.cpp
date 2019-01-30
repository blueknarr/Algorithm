#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool order[9];

int main(){
	int score,total=0;
	vector<pair<int, int> > v;
	for (int i = 0; i < 8; ++i){
		cin >> score;
		v.push_back(make_pair(score, i + 1));
	}
	
	sort(v.begin(), v.end());

	for (int i = 7; i > 2; --i){
		total += v[i].first;
		order[v[i].second] = true;
	}
	cout << total << endl;
	for (int i = 1; i < 9; ++i){
		if (order[i])
			cout << i << ' ';
	}
	cout << endl;
}
