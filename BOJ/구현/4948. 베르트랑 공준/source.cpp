
#include <cstdio>
#define MAX 123456*2
bool check[MAX+1];

int main(){
	//freopen("input.txt", "r", stdin);
	int n = 1;
	check[1] = true;
	for (int i = 2; i <= MAX; ++i){
		if (check[i] == false){
			for (int j = i + i; j <= MAX; j += i){
				check[j] = true;
			}
		}
	}
	
	while (1){
		scanf("%d", &n);

		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n+1; i <= 2 * n; ++i){
			if (check[i]==false)
				cnt++;
		}
		printf("%d\n", cnt);
	}
}