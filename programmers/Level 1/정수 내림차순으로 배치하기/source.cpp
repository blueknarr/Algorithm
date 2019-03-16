#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	int num[10] = { 0, };
	int digit[11] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,1000000000 };
	string str = to_string(n);
	int length = str.length();
	for (int i = 0; i<length; ++i){
		num[str.at(i) - '0']++;
	}
	for (long long i = 9; i >= 0; --i){
		while (num[i]){
			answer = answer + i * digit[length--];
			num[i]--;
		}
	}
	return answer;
}