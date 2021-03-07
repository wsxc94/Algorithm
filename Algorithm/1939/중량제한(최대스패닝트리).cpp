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
	최대 스패닝 트리 풀이법
*/
int n, m;
struct Edge {
	int v1, v2, val;
	bool operator <(Edge& b) {
		return val > b.val;
	}
};

int unf[100001];

int Find(int  v) {
	if (unf[v] == v)return v;
	return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) unf[a] = b;
	else if (a > b) unf[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	vector<Edge> ed(m);

	for (int i = 0; i < m; i++) {
		cin >> ed[i].v1 >> ed[i].v2 >> ed[i].val;
	}

	sort(ed.begin(), ed.end());

	for (int i = 1; i <= n; i++) unf[i] = i;

	int s, e;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		Union(ed[i].v1, ed[i].v2);
		if (Find(s) == Find(e)) {
			cout << ed[i].val << '\n';
			return 0;
		}

	}
}