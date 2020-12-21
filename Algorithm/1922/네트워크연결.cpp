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
	Edge(int a, int b, int c) : v1(a), v2(b), val(c) {};
	bool operator<(Edge &b) { return val < b.val; }
};
int n, m;
int unf[1002];
vector<Edge> mat;

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return unf[v] = Find(unf[v]);
}
void Union(int a,int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (a < b) unf[a] = b;
	else unf[b] = a;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	mat.reserve(n + 2);

	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		mat.push_back(Edge(a, b, c));
	}

	sort(mat.begin(), mat.end());

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int fa = Find(mat[i].v1);
		int fb = Find(mat[i].v2);

		if (fa != fb) {
			ans += mat[i].val;
			Union(mat[i].v1, mat[i].v2);
		}
	}

	cout << ans << "\n";

	return 0;
}