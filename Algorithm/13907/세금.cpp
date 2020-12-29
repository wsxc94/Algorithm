#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct Edge
{
	int v1;
	int v2;
	int cost;
	Edge(int a, int b, int c) :v1(a), v2(b), cost(c) {}
};

int n, m, k;
constexpr int INF = 0x7FFFFFFF;
constexpr int MAX_NUM = 1001;

vector<Edge> mat;

long long dist[MAX_NUM][MAX_NUM];

int start, ed;
int money = 0;

//O(NM + NK)
// 도로 사용 횟수 별 최소 비용 계산 + 비용 갱신
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	cin >> start >> ed;

	mat.reserve(30001);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mat.push_back(Edge(a, b, c));
	}

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	dist[0][start] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][mat[j].v1] = min(dist[i][mat[j].v1], dist[i - 1][mat[j].v2] + mat[j].cost);
			dist[i][mat[j].v2] = min(dist[i][mat[j].v2], dist[i - 1][mat[j].v1] + mat[j].cost);
		}
	}

	for (int i = 0; i <= k; i++)
	{
		long long ans = dist[0][ed];

		for (int j = 1; j < n; j++)
		{
			ans = min(ans, dist[j][ed]);
		}

		cout << ans << "\n";

		if (i < k) {
			int money;
			cin >> money;
			for (int j = 1; j < n; j++) dist[j][ed] += j * money;

		}
	}


	return 0;
}