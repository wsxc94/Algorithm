#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <set>
using namespace std;
/*
    https://programmers.co.kr/learn/courses/30/lessons/86491?language=cpp

*/
int solution(vector<vector<int>> sizes) {
	int w = 0, h = 0;

	for (int i = 0; i < sizes.size(); i++) {
		int cur_w = sizes[i][0];
		int cur_h = sizes[i][1];

		if (cur_w < cur_h) swap(cur_w, cur_h);

		w = max(cur_w, w);
		h = max(cur_h, h);

	}
	return w * h;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<vector<int>> sizes = { {60,50},{30,70},{60,30},{80,40} };
	cout << solution(sizes) << '\n';
	return 0;
}