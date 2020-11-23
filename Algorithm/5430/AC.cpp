#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t, n, num = 0;

	string func = "";
	string arr = "";
	deque<int> dq;
	bool reverse;
	bool error;
	cin >> t;

	while (t--)
	{
		cin >> func >> n >> arr;

		reverse = false;
		error = false;

		string tmp = "";
		
		for (int i = 0; i < arr.size(); i++)
		{
			
			if (arr[i] >= '0' && arr[i] <= '9') {
				num *= 10;
				num += int(arr[i] - '0');
				continue;
			}
			if (num != 0) {
				dq.push_back(num);
				num = 0;
			}
		}

		for (int i = 0; i < func.size(); i++)
		{
			if (func[i] == 'R') {
				reverse = !reverse;
			}
			else if(func[i] == 'D'){
				if (dq.empty()) {
					error = true;
					break;
				}
				else {
					if (reverse) dq.pop_back();
					else dq.pop_front();				
				}
			}
		}

		if (error) {
			cout << "error" << "\n";
			continue;
		}

		cout << '[';
		if (reverse) {
			while (dq.size())
			{
				cout << dq.back();
				dq.pop_back();
				if (dq.size()) cout << ',';
			}
		}
		else {
			while (dq.size())
			{
				cout << dq.front();
				dq.pop_front();
				if (dq.size()) cout << ',';
			}
		}
		cout << ']' << "\n";
	}
	return 0;
}