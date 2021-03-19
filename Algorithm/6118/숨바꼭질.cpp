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
   ����� �ϴ� �갣 ��ȣ , ��Ǳ����� �Ÿ� , �갣�� ���� �Ÿ��� ���� �갣�� ������
   ����ϴ� �����̴�

   �Ÿ��� ���ͽ�Ʈ�� �˰������� ������ �� �ϳ��� ���͸� �̿��� �갣 ��ȣ�� �Ÿ��� ���� ������ ���� ���� �� �ִ�.


*/
constexpr int INF = 987654321;
constexpr int MAX = 20010;
int dist[MAX];
vector<int> mat[MAX];
vector<int> ans_v;
int n, m, ans;

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0,1 });
	dist[1] = 0;

	while (!q.empty())
	{
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();

		for (int i = 0; i < mat[cur].size(); i++)
		{
			int next = mat[cur][i];
			int nCost = cost + 1;

			if (dist[next] > nCost) {
				dist[next] = nCost;
				q.push({ -nCost , next });

				if (dist[next] > ans) {
					ans = dist[next];
					ans_v.clear();
					ans_v.push_back(next);
				}
				else if (dist[next] == ans)
				{
					ans_v.push_back(next);
				}
			}
		}
	}
	sort(ans_v.begin(), ans_v.end());
	cout << ans_v[0] << " " << ans << " " << ans_v.size() << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) dist[i] = INF;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	dijkstra();

	return 0;
}