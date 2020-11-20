#include <iostream>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;

	while (n--)
	{
		queue<pair<int, int>> q;
		priority_queue<int> p_q;

		int num, find, cnt = 1;
		cin >> num >> find;

		for (int i = 0; i < num; i++)
		{
			int priority;
			cin >> priority;
			q.push({ i,priority });
			p_q.push(priority);
		}

		while (!q.empty())
		{
			int curIdx = q.front().first;
			int curPrior = q.front().second;
			q.pop();

			if (curPrior == p_q.top())
			{
				p_q.pop();

				if (curIdx == find) {
					cout << cnt << "\n";
				    break;
				}
				cnt++;
			}
			else {
				q.push({ curIdx , curPrior });
			}

		}

	}


	return 0;
}