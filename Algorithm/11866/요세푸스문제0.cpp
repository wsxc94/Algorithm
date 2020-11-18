#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	
	int n, k, num;
	cin >> n >> k;
	
	queue<int> q;

	for (int i = 1; i <= n; i++) q.push(i);

	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < k-1; i++)
		{
			num = q.front();
			q.pop();
			q.push(num);
		}
		num = q.front();
		q.pop();
		if (q.size() > 0) cout << num << ", ";
		else cout << num << ">";
	}


	return 0;
}