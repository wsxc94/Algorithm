#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	unordered_map<int, int> m;
	float sum = 0;
	int maxIdx = 0, max = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		m[v[i]]++;
		sum += v[i];
	}

	for (auto it : m) {
		if (maxIdx < it.second) maxIdx = it.second;
	}
	vector<int> tmp;

	int cnt = 0;
	for (auto it : m) {
		if (it.second == maxIdx) {
			cnt++;
			tmp.push_back(it.first);
		}
	}
	sort(tmp.begin(), tmp.end());

	cout << round(sum / n) << "\n";
	if (n % 2 == 0)
		cout << v[(n / 2) - 1] << "\n";
	else
		cout << v[n / 2 + 1] << "\n";
	if (cnt > 1)
		cout << tmp[1] << "\n";
	else
		cout << tmp[0] << "\n";
	cout << v[n - 1] - v[0] << "\n";



	return 0;

}