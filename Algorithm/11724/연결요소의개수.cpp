#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mat[1001];
bool ch[1001] = { false, };
int n, m, cnt = 0;

void dfs(int v) {
	
	ch[v] = true;

	for (int i = 0; i < mat[v].size(); i++)
	{
		if (ch[mat[v][i]]) continue;
		ch[mat[v][i]] = 1;
		dfs(mat[v][i]);
	}

}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!ch[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}