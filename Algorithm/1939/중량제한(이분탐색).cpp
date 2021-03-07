#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
/*
    �ܼ��� bfs�� O(n^2)���� Ǯ�� �ð��ʰ��� ����. O(nlongn)�� �̺�Ž������ Ǯ����.
	�߷��������� �Էµ� �� �� ���� ū ���� ���� �ȴ�.

	�ִ� ���д� Ʈ���� �̿��ؼ��� Ǯ������.
*/

constexpr int MAX = 10001;
int n, m, st, des;
vector<pair<int, int>> v[MAX];
bool ch[MAX];

bool bfs(int cost) {

	queue<int> q;
	q.push(st);
	ch[st] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == des) return true;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;

			if (!ch[next] && cost <= nCost) {
				q.push(next);
				ch[next] = true;
			}
		}
	}
	return false;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	int low = 0, high = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		high = max(high, c); // �߷����� �ִ밪
	}

	cin >> st >> des;

	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		memset(ch, 0, sizeof(ch));

		if (bfs(mid)) low = mid + 1;
		else high = mid - 1;
	}

	cout << high << "\n";

	return 0;
}