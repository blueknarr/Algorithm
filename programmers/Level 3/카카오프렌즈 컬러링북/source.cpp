#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int cnt = 1, num = 1;
	int visited[100][100]={0,};
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

	queue<pair<int, int> > q;
    
	for (int i = 0; i<m; ++i){
		for (int j = 0; j<n; ++j){
			if (picture[i][j] == 0 || visited[i][j] != 0)
				continue;
			
			int tile = picture[i][j];
			q.push(make_pair(i, j));
			visited[i][j] = num;
			number_of_area++;
			while (!q.empty()){
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				for (int d = 0; d < 4; ++d){
					int nx = x + dx[d];
					int ny = y + dy[d];

					if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
						tile == picture[nx][ny] && !visited[nx][ny]){
						cnt++;
						visited[nx][ny] = num;
						q.push(make_pair(nx, ny));
					}
				}
			}
			num++;
			if (cnt > max_size_of_one_area){
				max_size_of_one_area = cnt;
				cnt = 1;
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}