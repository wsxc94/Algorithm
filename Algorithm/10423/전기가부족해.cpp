#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;

constexpr int MAX_NUM = 1001;
int n, m, k;

struct Edge
{
	int v1;
	int v2;
	int val;

	Edge(int a, int b, int c) :v1(a), v2(b), val(c) {}

	bool operator <(Edge& b) {
		return val < b.val;
	}
};

vector<int> powerPlant;
int unf[MAX_NUM];
vector<Edge> ed;

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

	cin >> n >> m >> k;

	ed.reserve(m + 1);
	powerPlant.reserve(k + 1);

	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}

	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		powerPlant.push_back(num);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ed.push_back({ a,b,c });
	}

	// 발전소가 설치된 도시는 이미 이어져 있는 걸로 한다.
	for (int i = 0; i < k-1; i++)
	{
		Union(powerPlant[i], powerPlant[i + 1]);
	}

	sort(ed.begin(), ed.end());

	int ans = 0;
	
	for (int i = 0; i < ed.size(); i++)
	{
		int s = Find(ed[i].v1);
		int e = Find(ed[i].v2);
		int cost = ed[i].val;

		if (s != e) {
			ans += cost;
			Union(ed[i].v1, ed[i].v2);
			k++;
		}
		if (k == n) break;
	}

	cout << ans << "\n";
	return 0;
}