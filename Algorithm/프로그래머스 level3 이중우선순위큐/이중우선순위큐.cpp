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
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	vector<int> answer(2);
	vector<string> operations = { "I 7" , "I 5" , "I -5" , "D -1" }; // [I 7,I 5,I - 5,D - 1]"
	priority_queue<int> q;
	priority_queue<int, vector<int>, greater<int> > q2;

	string n, m;
	int cnt = 0;

	for (string op : operations) {

		if (!cnt) {
			while (!q.empty()) q.pop();
			while (!q2.empty()) q2.pop();
		}
		stringstream ss(op);
		ss >> m;
		ss >> n;

		if (m == "I") {
			q.push(stoi(n));
			q2.push(stoi(n));
			cnt++;
		}
		else if (m == "D") {

			if (!cnt) continue;

			if (n == "1") {
				q.pop();
				cnt--;

			}
			else {
				q2.pop();
				cnt--;
			}
		}
	}

	if (cnt) {
		answer[0] = q.top();
		answer[1] = q2.top();
	}
	cout << answer[0] << " " <<answer[1] << "\n";

	return 0;
}