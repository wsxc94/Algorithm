#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
vector<pair<int,int>> num;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	
	while (t--)
	{
		cin >> n;
		num.clear();
		num.reserve(n + 1);
		int cnt = 0;

		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			num.push_back({ a,b });
		}

		sort(num.begin(), num.end());

		int tmp = 987654321;
		for (int i = 0; i < num.size(); i++)
		{
			if (tmp > num[i].second) {
				tmp = num[i].second;
				cnt++;
			}
		}

		cout << cnt << "\n";

	}

	
	return 0;
}