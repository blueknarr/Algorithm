#include <iostream>
#include <cstdio>
using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char week[8][4] = { { "SUN" }, { "MON" }, { "TUE" }, { "WED" }, { "THU" }, { "FRI" }, { "SAT" } };
int x, y, day;

int month(int x){
	if (x == 1)
		return days[0];
	else{
		return days[x - 1] + month(x-1);
	}
}

int main(){
	scanf("%d%d", &x, &y);
	
	day = (month(x) + y) % 7;

	printf("%s\n", week[day]);
	
}