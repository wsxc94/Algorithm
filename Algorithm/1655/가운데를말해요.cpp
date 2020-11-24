#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
pqMin : ���� ���� ���� (��������)
pqMax : ū ���� ���� (��������)

���ο� ���� ������ �� pqMax.top���� ũ�� pqMax�� �־��ְ�
pqMin.top���� ������ pqMin�� �־��ݴϴ�.

���� �ְ��� �Ʒ��� ������ �������� ������

1. pqMax == pqMin + 1
2. pqMax == pqMin

���� �ʿ��� ���������� top�� ��ġ�� ���ڸ� �Ű� �ݴϴ�.
*/
int main() {

	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> max_pq;
	priority_queue<int> min_pq;

	int n, x;
	cin >> n;

	while (n--)
	{
		cin >> x;

		if (min_pq.empty() || min_pq.top() >= x) {
			min_pq.push(x);
			if (min_pq.size() > max_pq.size() + 1) {
				max_pq.push(min_pq.top());
				min_pq.pop();
			}
		}
		else if (max_pq.empty() || max_pq.top() <= x)
		{
			max_pq.push(x);
			if (max_pq.size() > min_pq.size())
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
			}
		}
		else if (min_pq.size() <= max_pq.size())
		{
			min_pq.push(x);
		}
		else if (min_pq.size() > max_pq.size())
		{
			max_pq.push(x);
		}

		cout << min_pq.top() << "\n";
	}

	return 0;
}