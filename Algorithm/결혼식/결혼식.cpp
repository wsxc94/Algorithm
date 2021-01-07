#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
constexpr int MAX_NUM = 501;

vector<int> mat[MAX_NUM];
vector<int> dist(MAX_NUM);
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty())
	{
		
		int cur = q.front();
		q.pop();

		for (auto i : mat[cur])
		{
			if (dist[i]) continue;
			dist[i] = dist[cur] + 1;
			q.push(i);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 2 || dist[i] == 3) {
			cnt++;
		}
	}

	cout << cnt << "\n";


	return 0;
}