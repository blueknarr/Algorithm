#include <cstdio>

struct Sheep{
	int first;
	int second;
	int third;
};
struct Sheep sheep[100001];

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		int N, Q;
		scanf("%d %d", &N, &Q);
		
		for (int i = 0; i <= N; ++i)
			sheep[i].first = sheep[i].second = sheep[i].third = 0;

		for (int i = 1; i <= N; ++i){
			int num;
			scanf("%d", &num);

			if (num == 1){
				sheep[i].first = 1 + sheep[i - 1].first;
				sheep[i].second += sheep[i - 1].second;
				sheep[i].third += sheep[i - 1].third;
			}
			else if (num == 2){
				sheep[i].first += sheep[i - 1].first;
				sheep[i].second = 1 + sheep[i - 1].second;
				sheep[i].third += sheep[i - 1].third;
			}
			else{
				sheep[i].first += sheep[i - 1].first;
				sheep[i].second += sheep[i - 1].second;
				sheep[i].third = 1 + sheep[i - 1].third;
			}
		}
		printf("#%d\n", tc);
		for (int i = 0; i < Q; ++i){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d %d %d\n", sheep[b].first - sheep[a - 1].first, sheep[b].second - sheep[a - 1].second, sheep[b].third - sheep[a - 1].third);
		}
	}
	return 0;
}