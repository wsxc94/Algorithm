#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;
constexpr int MAX_NUM = 500001;

struct Edge
{
	int v1;
	int v2;
	int cnt;
};
int n, m;
int unf[MAX_NUM], cycle[MAX_NUM];

int Find(int v) {
	if (unf[v] == v) return unf[v];

	return unf[v] = Find(unf[v]);
}

void Union(int a , int b) {
	a = Find(a);
	b = Find(b);

	if (a < b) {
		unf[a] = b;
	}
	else if (a > b)
	{
		unf[b] = a;
	}

	if (cycle[a] == cycle[b]) cycle[b]++;
}

vector<Edge> ed;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
		cycle[i] = 1;

	}
	int cnt = 0;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (Find(a) == Find(b)) {
			cnt = i;
			break;
		}
		Union(a, b);
	}

	cout << cnt << "\n";
	return 0;
}