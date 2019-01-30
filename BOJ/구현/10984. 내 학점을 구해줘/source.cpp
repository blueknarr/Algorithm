#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int T, N;
	int C, totalCourses = 0;
	float G, totalGrade = 0,gpa;

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);

	cin >> T;
	for (int tc = 0; tc < T; ++tc){
		cin >> N;
		for (int i = 0; i < N; ++i){
			cin >> C >> G;
			totalCourses += C;
			totalGrade += C*G;
		}
		gpa = totalGrade / totalCourses;
		cout << totalCourses << ' ' << floor(gpa*10 + 0.5) / 10 << endl;
		totalCourses = totalGrade = 0;
	}
}