#include <cstdio>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;

int n, m, ans;
int map[20][20];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct point{
	int x;
	int y;
	int size;
};

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	struct point shark;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9){
				shark.x = i;
				shark.y = j;
				shark.size = 2;
			}
		}
	}

	bool is_update = true;
	int cnt = 0;
	while (is_update){
		is_update = false;
		
		int visited[20][20] = { 0, };
		queue<pair<int, int> >q;
		priority_queue < pair<int, pair<int, int> >, vector<pair<int, pair<int, int > > >, greater<pair<int, pair<int, int> > > > pq;
		q.push(make_pair(shark.x, shark.y));
		
		//물고기 찾기
		
		while (!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			
			q.pop();

			for (int dir = 0; dir < 4; ++dir){
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx<0 || nx>=n || ny<0 || ny>=n)
					continue;

				if (map[nx][ny] <= shark.size && !visited[nx][ny]){
					visited[nx][ny] = visited[x][y]+1;
					q.push(make_pair(nx, ny));
					if (map[nx][ny]!=0 && map[nx][ny] < shark.size){
						if (map[nx][ny])
							pq.push(make_pair(visited[nx][ny], make_pair(nx, ny)));
					}
				}
			}
		}

		//물고기 먹기
		int size = pq.size();
		if (size>0){
			int x = pq.top().second.first;
			int y = pq.top().second.second;

			is_update = true;
			map[shark.x][shark.y] = 0;
			shark.x = x;
			shark.y = y;
			map[x][y] = 0;
			ans += visited[x][y];
			cnt++;
			if (shark.size == cnt){
				shark.size++;
				cnt = 0;
			}
		}

	}
	printf("%d\n", ans);
	return 0;

}