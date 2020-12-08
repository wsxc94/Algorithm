#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int unf[202];

int Find(int v) {

	if (v == unf[v]) return v;
	return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	if (unf[a] < unf[b]) swap(a, b);
	unf[a] = b;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, tmp, ans;
	bool cmp = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		unf[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (tmp == 1) Union(i, j);
		}
	}

	cin >> tmp;
	ans = Find(tmp);

	for (int i = 1; i < m; i++)
	{
		cin >> tmp;	
		if (ans != Find(tmp)) {
			cmp = false;
			break;
		}
		
	}

	if (cmp) cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}