#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	queue<int> q;

	int n, tmp;
	cin >> n;

	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() != 1)
	{
		q.pop();
		tmp = q.front();
		q.push(tmp);
		q.pop();

	}
	cout << q.front() << "\n";
	return 0;
}