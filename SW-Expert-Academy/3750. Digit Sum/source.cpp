#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case){
		long long number;
        int result;
		scanf("%lld", &number);
		
		while (1){
			result = 0;
			for (int i = 0; number>0; ++i){
				 result += number % 10;
				 number /= 10;
			}
			number = result;
			if (result < 10)
				break;
		}
		printf("#%d %d\n", test_case, result);
	}
}