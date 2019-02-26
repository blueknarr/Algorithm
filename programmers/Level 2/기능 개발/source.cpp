#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int index = 0;
	int size = progresses.size();
	while (size != index){
		int cnt = 0;
		for (int i = index; i<size; ++i)
			progresses[i] += speeds[i];

		if (progresses[index]<100)
			continue;
		else{
			while (progresses[index] >= 100){
				index++;
				cnt++;
				if (size == index)
					break;
			}
			answer.push_back(cnt);
		}
	}
	return answer;
}