#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
/*
   최소 스패닝 트리에서 절약한 비용을 찾는 문제이다.

   처음에 최대 비용을 미리 구해준 후
   최대비용 - 최소비용을 빼주면 답이 된다.

*/
using namespace std;
struct Edge
{
	int v1;
	int v2;
	int val;

	Edge(int a, int b, int c) : v1(a), v2(b), val(c) {}

	bool operator < (Edge& b) {
		return val < b.val;
	}
};
int n, m, a, b, c;
long long max_cost;
vector<int> unf;

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) unf[a] = b;
	else if (a > b) unf[b] = a;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		unf.resize(n + 1);

		for (int i = 0; i < n; i++) unf[i] = i;

		vector<Edge> ed;
		ed.reserve(m + 1);
		max_cost = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			ed.push_back(Edge(a, b, c));
			max_cost += c;
		}

		sort(ed.begin(), ed.end());

		long long ans = 0, cnt = 0;

		for (int i = 0; i < ed.size(); i++)
		{
			int a = Find(ed[i].v1);
			int b = Find(ed[i].v2);

			if (a != b) {
				ans += ed[i].val;
				Union(ed[i].v1, ed[i].v2);
				if (++cnt == n - 1) break;
			}
		}
		
		cout << max_cost - ans << "\n";
	}


	return 0;
}