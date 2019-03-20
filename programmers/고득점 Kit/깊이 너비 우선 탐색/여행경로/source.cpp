#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[10000];
vector<string> answer;
int cnt;

void dfs(int start, vector<vector<string>>& tickets, int size){
	string arrived = tickets[start][1];
	answer.push_back(arrived);
	visited[start] = true;
	cnt++;
	if (cnt == size)
		return;
    //여행 도착지 2개 이상이면 알파벳순으로 찾기 추가 전처리 정렬 필요 없음
	for (int i = 0; i<size; ++i){
		if (i == start || visited[i])
			continue;
		if (arrived.compare(tickets[i][0]) == 0){
			dfs(i, tickets, size);
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	int size = tickets.size();
	string departure = "ICN";
	int inc_size = 0;
	int remainder = 0;
	for (int i = 0; i < size; ++i){
		if (!departure.compare(tickets[i][0]))
			inc_size++;
	}
	remainder = size - inc_size;
	vector<pair<string, string>> inc;
	vector<pair<string, string>> city;
	vector<vector<string>> ticket(size);

	for (int i = 0; i < size; ++i){
		if (!departure.compare(tickets[i][0])){
			inc.push_back(make_pair(tickets[i][1], tickets[i][0]));
		}
		else{
			city.push_back(make_pair(tickets[i][0], tickets[i][1]));
		}
	}
	sort(inc.begin(), inc.end());
	sort(city.begin(), city.end());
	
	for (int i = 0; i < inc_size; ++i){
		ticket[i].push_back(inc[i].second);
		ticket[i].push_back(inc[i].first);
	}
	for (int i = inc_size; i < size; ++i){
		ticket[i].push_back(city[i - inc_size].first);
		ticket[i].push_back(city[i - inc_size].second);
	}

	for (int i = 0; i<size; ++i){
		answer.clear();
		cnt = 0;
		if (departure.compare(ticket[i][0]))
			continue;
		answer.push_back(ticket[i][0]);
		dfs(i, ticket, size);
		 if (cnt == size)
			break;
		for (int i = 0; i < size; ++i)
			visited[i] = false;
		
	}
	return answer;
}