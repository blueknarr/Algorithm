#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int point[11][11][4];

int solution(char* dirs)
{
	int answer = 0;
	int dir = 0, op_dir = 0;;
	int x = 5, y = 5;

	for (int i = 0; dirs[i] != '\0'; ++i){
		//좌표
		int nx = x, ny = y;
		if (dirs[i] == 'U'){
			nx = x-1;
			dir = 0;
		}
		else if (dirs[i] == 'D'){
			nx=x+1;
			dir = 2;
		}
		else if (dirs[i] == 'R'){
			ny=y+1;
			dir = 1;
		}
		else if (dirs[i] == 'L'){
			ny=y-1;
			dir = 3;
		}

		//방문 가능 여부 확인
		if (nx < 0 || nx>10 || ny < 0 || ny>10){
			nx = x, ny = y;
			continue;
		}
        op_dir = (dir+2)%4;
		//좌표
		if (point[nx][ny][dir] == 0 && point[x][y][op_dir]==0){
			point[x][y][op_dir] = point[nx][ny][dir] = 1;
			answer++;
		}
		x = nx, y = ny;
	}
	return answer;
}