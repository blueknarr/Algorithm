#include <cstdio>
using namespace std;

int sum[100001];

int main(){
	
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i){
		int num;
		scanf("%d", &num);
		sum[i] = num + sum[i - 1];
	}

	for (int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a,&b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}
	return 0;
}