#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	queue<int> q;
	string input;

	cin >> n;

	while (n--)
	{
		cin >> input;

		if (input == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (input == "front")
		{
			if(!q.empty())
			cout << q.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (input == "pop")
		{
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (input == "size")
		{
			cout << q.size() << "\n";
		}
		else if (input == "empty")
		{
			cout << q.empty() << "\n";
		}
		else if (input == "back")
		{
			if (!q.empty()) cout << q.back() << "\n";
			else cout << -1 << "\n";
		}
	}


	return 0;
}