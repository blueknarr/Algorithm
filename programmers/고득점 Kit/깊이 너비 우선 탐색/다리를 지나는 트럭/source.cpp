#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	vector<pair<int, int> > truck;

	truck.push_back(make_pair(truck_weights[0], 0));
	truck_weights.erase(truck_weights.begin());

	while (truck.size()){

		//트럭 당 시간 증가
		for (int i = 0; i<truck.size(); ++i)
			truck[i].second += 1;

		//시간이 맞다면 트럭 건너기 완료
		if (truck[0].second == bridge_length)
			truck.erase(truck.begin());

		//무게 확인후 다리에 트럭을 넣는다.
		int sum = 0;
		for (int i = 0; i<truck.size(); ++i)
			sum += truck[i].first;

		if (truck_weights.size() && weight >= sum + truck_weights[0]){
			truck.push_back(make_pair(truck_weights[0], 0));
			truck_weights.erase(truck_weights.begin());
		}
		answer++;
	}

	return answer;
}