#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	string s;
	stack<char> left;
	stack<char> right;

	cin >> s;
	cin >> n;

	for (int i = 0; i < s.size(); i++)
	{
		left.push(s[i]);
	}

	char tmp;
	while (n--)
	{
	
		cin >> tmp;
		if (tmp == 'P') {
			char c;
			cin >> c;
			left.push(c);
		}
		else if (tmp == 'L')
		{
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (tmp == 'D')
		{
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (tmp == 'B')
		{
			if (!left.empty()) left.pop();
		}
		else if (tmp == 'D')
		{
			if (!right.empty()) right.pop();
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}


	return 0;
}