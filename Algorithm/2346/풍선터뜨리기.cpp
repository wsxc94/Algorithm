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
#include <algorithm>

using namespace std;

deque<pair<int, int>> dq;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dq.push_back({ i + 1, num });
	}

	while (!dq.empty()) {
		auto cur = dq.front();
		cout << cur.first << ' ';
		
		dq.pop_front();

		if (dq.empty()) break;

		if (cur.second > 0) {
			for (int i = 0; i < cur.second - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			for (int i = 0; i < -cur.second; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}