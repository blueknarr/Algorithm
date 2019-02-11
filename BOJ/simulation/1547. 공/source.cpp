#include <iostream>
using namespace std;

int cup[4] = { 0, 1, 2, 3 };
int M;

int main(){
	cin >> M;
	int x, y,tmp, idx_x,idx_y;
	for (int i = 0; i < M; ++i){
		cin >> x >> y;
		
		if (x == y)
			continue;

		for (int j = 1; j < 4; ++j){
			if (cup[j] == x)
				idx_x = j;
			if (cup[j] == y)
				idx_y = j;
		}
		tmp = cup[idx_y];
		cup[idx_y] = cup[idx_x];
		cup[idx_x] = tmp;
	}
	cout << cup[1] << endl;
}