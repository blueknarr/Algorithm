#include <cstdio>
#include <vector>
using namespace std;

struct element{
	int a;
	int index;
};

int main(){
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc){
		int n, m, res,cnt = 0;
		struct element A[1001];
		int B[1001] = { 0, };
		scanf("%d %d", &n, &m);


		for (int i = 0; i < n; ++i){
			A[i].a = A[i].index = 0;
			scanf("%d", &A[i].a);
		}
		for (int i = 0; i < m; ++i)
			scanf("%d", &B[i]);

		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				if (B[i] >= A[j].a){
					A[j].index++;
					break;
				}
			}
		}
		for (int i = 0; i < n; ++i){
			if (cnt < A[i].index){
				cnt = A[i].index;
				res = i+1;
			}
		}
		printf("#%d %d\n", tc, res);
	}
	return 0;
}