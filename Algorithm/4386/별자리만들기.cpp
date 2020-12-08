#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct Pos
{
	double x;
	double y;
	Pos(int _x , int _y) {
		x = _x;
		y = _y;
	}
};
struct Edge
{
	double cost;
	int v1;
	int v2;
	Edge(double _cost , int a, int b) {
		cost = _cost;
		v1 = a;
		v2 = b;
	}
	bool operator<(Edge &b) {
		return cost < b.cost;
	}
};

vector<int> unf;
vector<Edge> ed;
vector<Pos> st;

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

	int n;
	double a, b, ans = 0;
	cin >> n;
	unf.reserve(n + 1);
	ed.reserve(n + 1);
	st.reserve(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		st.push_back(Pos(a, b));
		unf.push_back(i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double dis = sqrt(pow(st[i].x - st[j].x, 2) + pow(st[i].y - st[j].y, 2));
			ed.push_back({ dis,i,j });
		}
	}

	sort(ed.begin(), ed.end());

	for (Edge e : ed)
	{
		int fa = Find(e.v1);
		int fb = Find(e.v2);
		if (fa != fb) {
			ans += e.cost;
			Union(e.v1, e.v2);
		}
	}

	printf("%.2f\n", ans);
	return 0;
}