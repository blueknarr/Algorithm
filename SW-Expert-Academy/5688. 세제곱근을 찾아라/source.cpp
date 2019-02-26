#include <cstdio>

int main(){
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		unsigned long long num;
		int x = -1;
		scanf("%lld", &num);

		for (long long i = 1; i*i*i <= num; ++i){
			if (i*i*i == num){
				x = i;
			}
		}
		printf("#%d %d\n", tc, x);
	}
}