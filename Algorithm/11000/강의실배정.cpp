#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

pair<int, int> p[200001];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> q;
	
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);
	
	q.push(p[0].second);

	for (int i = 1; i < n; i++)
	{
		if (q.top() <= p[i].first) {
			q.pop();
			q.push(p[i].second);
			cout << q.top() << "\n";
		}
		else {
			q.push(p[i].second);
			cout << q.top() << "\n";
		}
	}

	cout << q.size() << "\n"; 
	return 0;
}