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
	int val;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
	bool operator<(Edge &b) {
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

	int n, m, a, b, c, ans = 0;
	cin >> n >> m;

	ed.reserve(n + 2);
	for (int i = 0; i <= n; i++)
	{
		unf[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		ed.push_back(Edge(a, b, c));
	}

	sort(ed.begin(), ed.end());

	for (int i = 0; i < m; i++)
	{
		int fa = Find(ed[i].v1);
		int fb = Find(ed[i].v2);
		if (fa != fb) {
			ans += ed[i].val;
			Union(ed[i].v1, ed[i].v2);
		}
	}
	cout << ans << "\n";
	return 0;
}