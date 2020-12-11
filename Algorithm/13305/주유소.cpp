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

	int n;
	cin >> n;
	vector<long long> dist(n - 1);
	priority_queue<long long, vector<long long>, greater<long long>> q;

	for (int i = 0; i < n-1; i++)
	{
		cin >> dist[i];
	}

	long long tmp, ans = 0;

	for (int i = 0; i < n-1; i++)
	{
		cin >> tmp;
		q.push(tmp);
		ans += (q.top() * dist[i]);
		//cout << i << "번사이클 " << q.top() << " * " << dist[i] << " = " << ans << "\n";
	}

	cout << ans;

	return 0;
}