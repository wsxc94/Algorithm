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

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	queue<int> q;

	int n, m;
	string order;
	cin >> n;

	while (n--)
	{
		cin >> order;

		if (order == "push") {
			cin >> m;
			q.push(m);
		}
		else if (order == "pop")
		{
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (order == "size")
		{
			cout << q.size() << "\n";
		}
		else if (order == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (order == "front")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (order == "back")
		{
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}

	}
	return 0;
}