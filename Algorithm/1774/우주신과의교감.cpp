#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M;

vector<pair<int, int>> pos;
vector<int> unf;
vector<pair<double, pair<int, int>>> edge;

inline double getDist(int a, int b) {
	return sqrt(powl(pos[a].first - pos[b].first, 2) + powl(pos[a].second - pos[b].second, 2));
}

int findParent(int a) {
	if (a == unf[a]) return a;
	return unf[a] = findParent(unf[a]);
}

bool unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b) return false;
	else if (a > b) unf[a] = b;
	else unf[b] = a;
	return true;
}

int main() {
	cin >> N >> M;

	int cnt = 0;
	double ans = 0.0;

	pos.assign(N + 1, pair<int, int>());
	unf.assign(N + 1, 0);

	for (int i = 0; i <= N; i++) {
		unf[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		cin >> pos[i].first >> pos[i].second;
	}

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			edge.push_back({ getDist(i, j), {i, j} });
		}
	}

	sort(edge.begin(), edge.end());

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (unionParent(a, b)) {
			cnt++;
		}
	}

	for (int i = 0; i < edge.size() && cnt != N - 1; i++) {
		if (unionParent(edge[i].second.first, edge[i].second.second)) {
			cnt++;
			ans += edge[i].first;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}