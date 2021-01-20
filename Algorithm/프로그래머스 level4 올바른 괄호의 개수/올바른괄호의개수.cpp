#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n = 3;

	int answer = 0;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		v.push_back(1);
		v.push_back(-1);
	}

	do {
		int sum = 0;
		bool cmp = true;

		for (int i = 0; i < n * 2; i++) {
			sum += v[i];
			if (sum < 0) {
				cmp = false;
				break;
			}
		}
		if (cmp) answer++;

	} while (next_permutation(v.begin(), v.end()));

	cout << answer << "\n";
	return 0;
}