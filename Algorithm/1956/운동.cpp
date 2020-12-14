#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = INF;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j) ans = min(ans, dist[i][j] + dist[j][i]);
		}
	}		

	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";

	
	return 0;
}