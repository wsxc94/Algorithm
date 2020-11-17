#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	int num;
	cin >> num;
	vector<pair<int, int>> vec(num);

	int currentTime = 0;
	int cnt = 0;

	for (int i = 0; i < num; i++) {
		cin >> vec[i].second >> vec[i].first;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < num; i++) {
		if (currentTime <= vec[i].second) {
			currentTime = vec[i].first;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}