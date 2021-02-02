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
//크루스칼 알고리즘
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
int n;
int mat[1001][1001];
int unf[1001];
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

	cin >> n;

	for (int i = 0; i < n; i++) unf[i] = i;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	//중복된 연결을 없애기 위함.
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			ed.push_back({ i,j,mat[i][j] });
		}
	}

	sort(ed.begin(), ed.end());
	long long ans = 0;

	for (int i = 0; i < ed.size(); i++)
	{
		int a = Find(ed[i].v1);
		int b = Find(ed[i].v2);
		if (a != b)
		{
			ans += ed[i].val;
			Union(ed[i].v1, ed[i].v2);
		}
	}
	cout << ans << "\n";
	return 0;
}