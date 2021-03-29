#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;
/*
   �����ġ���� ������ġ���� ��� �� �� �ִ� �������� �ִ밪�� ���ϴ� ����
   �̺�Ž���� ���� ������ ���� high(�ִ� ������ ����)���� ���Ͽ� Ž���Ѵ�.
*/
constexpr int MAX = 100001;
int n, m, s, e, ans;
bool ch[MAX];
vector<pair<int, int>> ed[MAX];

bool bfs(int Limit)
{
	queue<int> q;
	memset(ch, false, sizeof(ch));
	q.push(s);
	ch[s] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == e) return true;
		for (int i = 0; i < ed[cur].size(); i++)
		{
			int next = ed[cur][i].first;
			int nCost = ed[cur][i].second;

			if (ch[next] == false && nCost >= Limit)
			{
				ch[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ b,c });
		ed[b].push_back({ a,c });
	}

	int low = 0, high = 1000000, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (bfs(mid) == true) low = mid + 1;
		else high = mid - 1;
	}

	if (high == -1) cout << 0 << "\n";
	else cout << high << "\n";

	return 0;
}