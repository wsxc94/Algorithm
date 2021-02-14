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

vector<int> c;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	for (char i : s)
		c.push_back(i - 'a');

	sort(c.begin(), c.end());

	int cnt = 0;

	do {
		bool cmp = true;
		for (int i = 0; i < c.size() - 1; i++) {
			if (c[i] == c[i + 1]) {
				cmp = false;
				break;
			}
		}
		if (cmp) cnt++;
	} while (next_permutation(c.begin(), c.end()));
	cout << cnt;
	return 0;
}