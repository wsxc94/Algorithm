#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int N, M, K, X, dist[300001];
vector<int> mat[300001];

void bfs() {
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push({ X, 0 });
	dist[X] = 0;

	while (!q.empty()) {

		int idx = q.front().first;
		int	cost = q.front().second;
		q.pop();

		for (auto i : mat[idx])
			if (dist[i] == -1) {
				dist[i] = cost + 1;
				q.push({ i, cost + 1 });
			}
	}
	vector<int> res;

	for (int i = 1; i <= N; ++i)
		if (dist[i] == K) res.push_back(i);

	if (res.empty()) res.push_back(-1);

	for (auto i : res) cout << i << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; ++i) {
		int s, e; 
		cin >> s >> e;
		mat[s].push_back(e);
	}

	bfs();

	return 0;
}