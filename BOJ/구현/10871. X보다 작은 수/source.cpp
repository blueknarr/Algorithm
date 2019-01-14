#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, X;

int main(){
	scanf("%d%d", &N, &X);
	int num = 0;
	vector<int> v;
	for (int i = 0; i < N; ++i){
		scanf("%d", &num);
		if (num < X)
			v.push_back(num);
	}
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}
