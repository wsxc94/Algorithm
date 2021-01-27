#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

struct pos {
	int idx, val;
};
pos tmp;
struct cmp {
	bool operator()(pos &a, pos &b) {
		return a.val > b.val;
	}
};
vector<pos> v[10001];

int dist[10001], node, edge, start, s, e, val, test, cnt, result;
constexpr int INF = 987654321;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> node >> edge >> start;
		for (int i = 1; i <= node; i++) {
			v[i].clear();
			dist[i] = INF;
		}
		for (int i = 0; i < edge; i++) {
			cin >> e >> s >> val;
			tmp.idx = e;
			tmp.val = val;
			v[s].push_back(tmp);
		}
		dist[start] = 0;
		result = -1;
		cnt = 0;
		priority_queue<pos, vector<pos>, cmp> pq;
		tmp.idx = start;
		tmp.val = 0;
		pq.push(tmp);
		while (!pq.empty()) {
			int cidx = pq.top().idx;
			int cv = pq.top().val;
			pq.pop();
			if (dist[cidx] < cv) continue;
			for (int i = 0; i < v[cidx].size(); i++) {
				int next = v[cidx][i].idx;
				int nv = v[cidx][i].val;
				if (dist[next] > cv + nv) {
					dist[next] = cv + nv;
					tmp.idx = next;
					tmp.val = cv + nv;
					pq.push(tmp);
				}
			}
		}
		for (int i = 1; i <= node; i++) {
			if (dist[i] != INF) {
				cnt++;
				result = max(result, dist[i]);
			}
		}
		cout << cnt << " " << result << '\n';
	}
	return 0;
}