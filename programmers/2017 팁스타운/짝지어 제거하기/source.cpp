#include <iostream>
#include <string>

using namespace std;
char str[500002];
int solution(string s)
{
	int answer = 1;
	int index = 0;
	str[0] = s.at(0);
	
	for (int i = 1; i<s.size(); ++i){
		if (str[index] == s.at(i)){
			str[index--] = '\0';
		}
		else{
			str[++index] = s.at(i);
		}
	}
	if (index != -1)
		answer = 0;
	return answer;
}