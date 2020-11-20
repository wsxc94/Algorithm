#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	stack<int> s;
	queue<int> q;
	queue<char> c;

	int cnt = 1;

	int n , m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		q.push(m);
	}

	while (!q.empty())
	{
		if (!s.empty() && s.top() == q.front()) {
			s.pop();
			q.pop();
			c.push('-');
		}
		else if (cnt <= q.front())
		{
			while (cnt <= q.front())
			{
				s.push(cnt++);
				c.push('+');
			}
		}
		else {
			cout << "NO" << "\n";
			return 0;
		}
	}
	while (!c.empty()) {
		cout << c.front() << "\n";
		c.pop();
	}
	return 0;
}