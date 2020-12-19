#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

vector<int> mat[101];
vector<int> dist(101, 0);

int bfs(int start , int target) {
	queue<int> q;
	q.push(start);

	int cnt = 0;
	while (!q.empty())
	{
		int pos = q.front();
		q.pop();
		if (pos == target) return dist[target];

		for (int i = 0; i < mat[pos].size(); i++)
		{
			if (!dist[mat[pos][i]]) {
				q.push(mat[pos][i]);
				dist[mat[pos][i]] = dist[pos] + 1;
			}
		}
	}

	return -1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m, start, target;
	cin >> n;
	cin >> start >> target;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	cout << bfs(start, target) << "\n";

	return 0;
}