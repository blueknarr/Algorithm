#include <cstdio>

int main(){
	int A, B, C;
	int number[10] = { 0, };
	int multiple;

	scanf("%d%d%d", &A,&B,&C);

	multiple = A*B*C;

	for (int i = 0; multiple > 0; i++){
		number[multiple % 10]++;
		multiple /= 10;
	}

	for (int i = 0; i < 10; ++i)
		printf("%d\n", number[i]);

}