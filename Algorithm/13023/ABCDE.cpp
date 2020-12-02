#include <iostream>
#include <queue>

using namespace std;

vector<int> mat[2001];
vector<bool> ch(2001, false);
bool comp = false;
int n, m, a, b;

void dfs(int v , int cnt) {
	if (cnt == 4) {
		comp = true;
		return;
	}
	ch[v] = true;

	for (int i = 0; i < mat[v].size(); i++)
	{
		if (ch[mat[v][i]]) continue;
		ch[mat[v][i]] = true;
		dfs(mat[v][i], cnt + 1);
		ch[mat[v][i]] = false;
		if (comp) return;
	}
	ch[v] = false;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		if (comp) break;
		dfs(i, 0);
	}

	if (comp) cout << 1;
	else cout << 0;

	return 0;
}