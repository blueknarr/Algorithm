#include<vector>
#include<queue>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int visited[100][100];

int solution(vector<vector<int> > maps)
{
	int answer = -1;
	int n = maps.size() - 1;
	int m = maps[0].size() - 1;
	int bn = n + 1;
	int bm = m + 1;
	queue<pair<int, int> > q;

	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == n && y == m)
			answer = visited[x][y];

		for (int d = 0; d<4; ++d){
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= 0 && nx<bn && ny >= 0 && ny<bm && maps[nx][ny] == 1 && !visited[nx][ny]){
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return answer;
}