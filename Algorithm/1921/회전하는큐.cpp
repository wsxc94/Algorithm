#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


int main() {
	int n, m, find, idx;
	int cnt = 0;
	deque<int> dq;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		dq.push_back(i);
	}

	while (m--) {

		cin >> find;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == find) {
				idx = i;
				break;
			}
		}

		if (idx < dq.size() - idx) {
			while (true) {
				if (dq.front() == find) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (true) {
				if (dq.front() == find) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << cnt << endl;

	return 0;
}