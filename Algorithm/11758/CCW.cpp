#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
/*
   점 3개의 방향이 시계방향인지 반시계방향인지 일직선인지 판단하는 알고리즘
   세점으로 이루어진 삼각형의 면적을 통해 방향을 구한다
   넓이 > 0 반시계
   넓이 < 0 시계
   넓이 = 0 일직선

   첫번째 점 (x1, y1)으로 두고 벡터의 외적으로 넓이를 구함

*/
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int v = x1 * y2 + x2 * y3 + x3 * y1;
	v = v - y1 * x2 - y2 * x3 - y3 * x1;

	if (v > 0) {
		return 1;
	}
	else if (v < 0) {
		return -1;
	}
	
	return 0;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	cout << ccw(x1, y1, x2, y2, x3, y3) << "\n";

	return 0;
}