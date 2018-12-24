#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long int square[] = { 1, 16, 256, 4096, 65536, 1048576, 16777216, 268435456 };
int digit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
char box[28];
int N, K,index,flag;

bool compare(long long int a, long long int b){
	return a > b;
}

int main(){
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		long long int num[28] = { 0, };
		char box[28] = { 0, };

		scanf("%d %d", &N, &K);
		scanf("%s", &box);

		int rotate = N / 4;
		long long int sum = 0;

		for (int i = 0; i < rotate; ++i){
			//회전하기전 생성가능 수
		
			for (int j = 0; j < N; j+=rotate){//배수
				for (int k = 0; k < rotate; ++k){//자리수
					if (box[j+k] == '1'){
						sum += digit[0] * square[rotate - 1 - k];
					}
					else if (box[j + k] == '2'){
						sum += digit[1] * square[rotate - 1 - k];
					}
					else if (box[j + k] == '3'){
						sum += digit[2] * square[rotate - 1 - k];
					}
					else if (box[j + k] == '4'){
						sum += digit[3] * square[rotate - 1 - k];
					}
					else if (box[j + k] == '5'){
						sum += digit[4] * square[rotate - 1 - k];
					}
					else if (box[j + k] == '6'){
						sum += digit[5] * square[rotate - 1 - k];
					}
					else if (box[k + j] == '7'){
						sum += digit[6] * square[rotate - 1 - k];
					}
					else if (box[k + j] == '8'){
						sum += digit[7] * square[rotate - 1 - k];
					}
					else if (box[k + j] == '9'){
						sum += digit[8] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'A'){
						sum += digit[9] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'B'){
						sum += digit[10] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'C'){
						sum += digit[11] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'D'){
						sum += digit[12] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'E'){
						sum += digit[13] * square[rotate - 1 - k];
					}
					else if (box[k + j] == 'F'){
						sum += digit[14] * square[rotate - 1 - k];
					}
				}
				
				for (int l = 0; l < index; ++l){
					if (num[l] == sum){
						flag = 1;
						break;
					}
				}
				if (!flag){
					num[index] = sum;
					sum = 0;
					index++;
				}
				flag = 0;
			}
			//1칸 오른쪽 이동
			char tmp = box[N - 1];
			for (int l = N-1; l >0; --l){
				box[l] = box[l - 1];
			}
			box[0] = tmp;
		}
		sort(num, num + N, compare);

		printf("#%d %d\n", tc, num[K - 1]);
		index = 0;
	}
}