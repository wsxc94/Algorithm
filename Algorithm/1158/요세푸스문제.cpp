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
	int n, k, cnt = 1;
	cin >> n >> k;
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
    
	cout << "<";
	while (!q.empty())
	{
		if (cnt % k == 0) {
			if (q.size() != 1) {
				cout << q.front() << ", ";
			}
			else {
				cout << q.front();
			}
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}
	cout << ">";
	return 0;
}