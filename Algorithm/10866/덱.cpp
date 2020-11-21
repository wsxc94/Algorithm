#include <iostream>
#include <deque>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	int n, num;
	cin >> n;

	string str;
	deque<int> dq;

	while (n--)
	{
		cin >> str;

		if (str == "push_back")
		{		
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else {	
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (str == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << dq.empty() << "\n";
		}
		else if (str == "front")
		{
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.front() << "\n";
		}
		else if (str == "back")
		{
			if (dq.empty()) cout << -1 << "\n";
			else cout << dq.back() << "\n";
		}

	}
	return 0;
}