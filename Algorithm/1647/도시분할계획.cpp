#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int n, m;

struct Edge
{
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
	bool operator<(Edge& b) {
		return val < b.val;
	}
};
int unf[100002];
vector<Edge> ed;

int Find(int v) {
	if (unf[v] == v) return unf[v];
	return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) {
		unf[a] = b;
	}
	else if (a > b) {
		unf[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}

	ed.reserve(m+1);

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		ed.push_back(Edge(a, b, c));
	}

	sort(ed.begin(), ed.end());

	int ans = 0, cnt = 0;

	for (int i = 0; i < ed.size(); i++)
	{
		if (cnt == n - 1) break;
		auto cur = ed[i];
		if (Find(cur.v1) != Find(cur.v2)) {
			ans += cur.val;
			Union(cur.v1, cur.v2);
			cnt++;
		}
		
	}

	cout << ans << "\n";

	return 0;
}