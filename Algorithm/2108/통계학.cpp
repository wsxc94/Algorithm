#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	int n;
	cin >> n;

	vector<int> v(n);
	unordered_map<int, int> m;

	double sum = 0;
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

	cout << round(sum / (double)n) << "\n";
	cout << v[round(n/2)] << "\n";
	if (cnt > 1)
		cout << tmp[1] << "\n";
	else
		cout << tmp[0] << "\n";
	cout << v[n - 1] - v[0] << "\n";



	return 0;

}