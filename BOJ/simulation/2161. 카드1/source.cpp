#include <stdio.h>

int N;
int card[1000];

int main(){
	scanf("%d", &N);
	int first, second;
	
	for (int i = 1; i <= N; ++i)
		card[i - 1] = i;
        
	if (N == 1){
		printf("%d\n", 1);
	}
	else{
		while (N != 1){
			first = card[0];
			second = card[1];
			for (int i = 2; i < N; ++i){
				card[i - 2] = card[i];
			}
			card[--N - 1] = second;
			printf("%d ", first);
		}
		printf("%d\n", second);
	}
	
}