#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[10][10], A[10][10];
int N,M,K;
vector<vector<vector<int> > > tree;

int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	//N×N 크기,  (r, c)
	//모든 칸에 대해서 조사, 가장 처음에 양분은 모든 칸에 5만큼
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			scanf("%d", &A[i][j]);
			map[i][j] = 5;
		}
	}

	//M개의 나무를 구매 -> 같은 1×1칸에 여러 개의 나무가 심어져
	vector<pair<int, pair<int, int> > > tree_point;
	for (int i = 0; i < M; ++i){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		tree_point.push_back(make_pair(x-1, make_pair(y-1, z)));
	}
	
	//사계절 과정 반복
	while (K){
		//년도 감소
		//K년이 지난 후 상도의 땅에 살아있는 나무의 개수
		K--;
		
		//봄, 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다
		//1×1 크기의 칸에 있는 양분만 먹을 수 있다
		// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다
		//땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다
		sort(tree_point.begin(), tree_point.end());
		vector<int> index;
		for (int i = 0; i < tree_point.size(); ++i){
			int x = tree_point[i].first;
			int y = tree_point[i].second.first;
			int age = tree_point[i].second.second;

			//순서 고려 안함
			if (map[x][y] >= age){
				map[x][y] -= age;
				tree_point[i].second.second++;
			}
			else{
				//나무가 죽었다.
				//배열 체크
				index.push_back(i);
			}

		}

		//여름
		int size = index.size() - 1;
		for (int i = size; i >=0; --i){
			int x = tree_point[index[i]].first;
			int y = tree_point[index[i]].second.first;
			int age = tree_point[index[i]].second.second;
			
			//죽은 나무 배열에서 제거
			//죽은 나무 나이를 2로 나눈 값을 양분으로 더한다
			//토양에 더하고
			map[x][y] += age / 2;
			tree_point.erase(tree_point.begin() + index[i]);
			
		}
		//제거


		//가을
		//나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 
		//인접한 8개의 칸에 나이가 1인 나무가 생긴다
		size = tree_point.size();
		for (int i = 0; i < size; ++i){
			int x = tree_point[i].first;
			int y = tree_point[i].second.first;
			int age = tree_point[i].second.second;
			
			if (age % 5 != 0)
				continue;
			//(r-1, c-1)
			if (x-1>=0 && y-1>=0)
				tree_point.push_back(make_pair(x-1, make_pair(y-1, 1)));
			//(r-1, c)
			if (x-1>=0)
				tree_point.push_back(make_pair(x-1, make_pair(y, 1)));
			//(r-1, c+1) 
			if (x-1>=0 && y+1<N)
				tree_point.push_back(make_pair(x-1, make_pair(y+1, 1)));
			//(r, c-1) 
			if (y-1>=0)
				tree_point.push_back(make_pair(x, make_pair(y-1, 1)));
			//(r, c+1)
			if (y+1<N)
				tree_point.push_back(make_pair(x, make_pair(y+1, 1)));
			//(r+1, c-1) 
			if (x+1<N && y-1>=0)
				tree_point.push_back(make_pair(x+1, make_pair(y-1, 1)));
			//(r+1, c)
			if (x+1<N)
				tree_point.push_back(make_pair(x+1, make_pair(y, 1)));
			//(r+1, c+1)
			if (x+1<N && y+1<N)
				tree_point.push_back(make_pair(x+1, make_pair(y+1, 1)));
		}


		//겨울
		//S2D2가 땅을 돌아다니면서 땅에 양분을 추가, 양분의 양은 A[r][c]이고, 입력으로 
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				map[i][j] += A[i][j];
			}
		}
	}
	printf("%d\n", tree_point.size());
	return 0;
}