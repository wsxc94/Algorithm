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
	int x;
	int y;
	int z;
	int idx;

	Pos(int _x , int _y , int _z , int _idx) {
		x = _x;
		y = _y;
		z = _z;
		idx = _idx;
	}
};

struct Edge
{
	int v1;
	int v2;
	int cost;
	Edge(int _cost , int a, int b) {
		cost = _cost;
		v1 = a;
		v2 = b;
	}
	bool operator<(Edge &b) {
		return  cost < b.cost;
	}
};

bool cmpX(Pos &a, Pos &b) {
	return a.x < b.x;
}
bool cmpY(Pos &a, Pos &b) {
	return a.y < b.y;
}
bool cmpZ(Pos &a, Pos &b) {
	return a.z < b.z;
}


vector<int> unf;
vector<Pos> pos;
vector<Edge> ed;

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return unf[v] = Find(unf[v]);
}
bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return false;

	if (a < b) unf[a] = b;
	else if (a > b) unf[b] = a;

	return true;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	int x, y, z;

	cin >> n;

	unf.resize(n);
	pos.reserve(n + 1);
	ed.reserve(n + 1);

	for (int i = 0; i < n; i++)
	{
		unf[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		pos.push_back(Pos(x, y, z, i));
	}

	sort(pos.begin(), pos.end(), cmpX);
	for (int i = 0; i < n-1; i++)
	{
		ed.push_back(Edge(pos[i + 1].x - pos[i].x, pos[i].idx, pos[i + 1].idx));
	}

	sort(pos.begin(), pos.end(), cmpY);
	for (int i = 0; i < n - 1; i++)
	{
		ed.push_back(Edge(pos[i + 1].y - pos[i].y, pos[i].idx, pos[i + 1].idx));
	}

	sort(pos.begin(), pos.end(), cmpZ);
	for (int i = 0; i < n - 1; i++)
	{
		ed.push_back(Edge(pos[i + 1].z - pos[i].z, pos[i].idx, pos[i + 1].idx));
	}

	sort(ed.begin(), ed.end());

	int cnt = 0;
	int ans = 0;
	for (Edge e : ed)
	{
		if (cnt == n - 1) break;
		if (Union(e.v1, e.v2)) {
			cnt++;
			ans += e.cost;
		}
	}
	cout << ans << "\n";
	return 0;
}