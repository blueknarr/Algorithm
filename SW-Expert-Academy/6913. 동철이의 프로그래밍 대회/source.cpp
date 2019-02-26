#include <cstdio>

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		int n, m;
		int q[20][20] = { 0, };
		int people[20] = { 0, };
		int firstNum = 0, topScore = 0,res=0;
		scanf("%d%d", &n, &m);

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				scanf("%d", &q[i][j]);
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (!q[i][j])
					continue;
				topScore++;
			}
			people[i] = topScore;
			if (topScore > res)
				res = topScore;
			topScore = 0;
		}

		for (int i = 0; i < n; ++i){
			if (people[i] == res)
				firstNum++;
		}
		printf("#%d %d %d\n", tc, firstNum, res);
	}
	return 0;
}