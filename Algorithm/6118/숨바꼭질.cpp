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
   숨어야 하는 헛간 번호 , 헛건까지의 거리 , 헛간과 같은 거리를 갖는 헛간의 개수를
   출력하는 문제이다

   거리를 다익스트라 알고리즘으로 구한후 또 하나의 벡터를 이용해 헛간 번호와 거리를 갖는 개수를 쉽게 구할 수 있다.


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