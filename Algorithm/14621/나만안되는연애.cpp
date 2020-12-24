#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
struct Edge
{
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c) : v1(a), v2(b), val(c) {}
	bool operator<(Edge& b) {
		return val < b.val;
	}
};

pair<int,char> unf[1001];
vector<Edge> ed;

int Find(int v) {
	if (v == unf[v].first) return unf[v].first;
	return unf[v].first = Find(unf[v].first);
}
void Union(int a,int b) {

	 a = Find(a);
	 b = Find(b);

	if (a < b) unf[a].first = b;
	else if (a > b) unf[b].first = a;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		unf[i].first = i;
		cin >> unf[i].second;
	}

	ed.reserve(n + 1);
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		ed.push_back(Edge(a, b, c));
	}

	sort(ed.begin(), ed.end());

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (cnt == n - 1) break;
		int fa = Find(ed[i].v1);
		int fb = Find(ed[i].v2);

		if (fa != fb && unf[ed[i].v1].second != unf[ed[i].v2].second) {
			ans += ed[i].val;
			Union(ed[i].v1, ed[i].v2);
			cnt++;
		}

	}

	if(cnt == n-1)
	cout << ans << "\n";
	else cout << -1 << "\n";

	return 0;
}