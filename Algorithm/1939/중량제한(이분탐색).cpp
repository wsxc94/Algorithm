#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
/*
    단순한 bfs와 O(n^2)으로 풀면 시간초과가 난다. O(nlongn)의 이분탐색으로 풀었다.
	중량제한으로 입력된 값 중 가장 큰 값이 답이 된다.

	최대 스패닝 트리를 이용해서도 풀수있음.
*/

constexpr int MAX = 10001;
int n, m, st, des;
vector<pair<int, int>> v[MAX];
bool ch[MAX];

bool bfs(int cost) {

	queue<int> q;
	q.push(st);
	ch[st] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == des) return true;

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nCost = v[cur][i].second;

			if (!ch[next] && cost <= nCost) {
				q.push(next);
				ch[next] = true;
			}
		}
	}
	return false;

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	int low = 0, high = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
		high = max(high, c); // 중량제한 최대값
	}

	cin >> st >> des;

	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		memset(ch, 0, sizeof(ch));

		if (bfs(mid)) low = mid + 1;
		else high = mid - 1;
	}

	cout << high << "\n";

	return 0;
}