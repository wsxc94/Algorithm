#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n , m;
	cin >> n;
	vector<int> v;

	v.push_back(0);

	while (n--)
	{
		cin >> m;
		if (v.back() < m) {
			v.push_back(m);
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), m) - v.begin();
			v[idx] = m;
		}
	}

	cout << v.size() - 1 << "\n";


	return 0;
}