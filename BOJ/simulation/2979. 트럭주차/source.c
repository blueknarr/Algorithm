#include <stdio.h>

int main(){
	int car[101] = { 0, };
	int a, b, c,i,j,total=0;
	int start, end,startMin=101, endMax=0;
	scanf("%d%d%d", &a, &b, &c);
	
	for (i = 0; i < 3; ++i){
		scanf("%d %d", &start, &end);

		if (start < startMin)
			startMin = start;
		if (end > endMax)
			endMax = end;

		for (j = start; j < end; ++j)
			car[j]++;
	}

	for (i = startMin; i <= endMax; ++i){
		if (car[i] == 1){
			total += a;
		}
		else if (car[i] == 2){
			total += b*2;
		}
		else if (car[i] == 3){
			total += c*3;
		}
	}
	printf("%d\n", total);
}