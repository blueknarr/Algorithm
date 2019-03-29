#include <vector>

using namespace std;

int binary(int n, int cnt){
	while (n > 0){
		if (n & 1 == 1){
			cnt++;
		}
		n = n >> 1;
	}
	return cnt;
}

int solution(int n) {
	int answer = 0;
	//n의 1개수 찾기
	answer = binary(n, 0);

	while (1){
		int next = ++n;
		int count = 0;
		
		count = binary(next, 0);
		if (answer == count){
			answer = next;
			break;
		}
	}
	return answer;
}