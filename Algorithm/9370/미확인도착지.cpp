#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int t, n, m, k, s, g, h, ans = 0;
constexpr int INF = 987654321;
constexpr int MAX_NUM = 2001;

int Dist_s[MAX_NUM];
int Dist_g[MAX_NUM];
int Dist_h[MAX_NUM];
vector<pair<int, int>> mat[MAX_NUM];
vector<int> endPos;

void Dijkstra(int _start , int arr[MAX_NUM]) {

	priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
	q.push({ _start,0 });
	arr[_start] = 0;

	while (!q.empty())
	{
		int start = q.top().first;
		int cost = q.top().second;
		q.pop();

		for (int i = 0; i < mat[start].size(); i++)
		{
			int nextPos = mat[start][i].first;
			int nCost = mat[start][i].second;

			if (arr[nextPos] > cost + nCost) {
				arr[nextPos] = cost + nCost;
				q.push({ nextPos , arr[nextPos] });
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> t;

	while (t--)
	{
		//교차로 도로 목적지
		cin >> n >> m >> k;
		//출발지 도로사이위치
		cin >> s >> g >> h;

		for (int i = 0; i < MAX_NUM; i++) {
			mat[i].clear();
			Dist_s[i] = INF;
			Dist_g[i] = INF;
			Dist_h[i] = INF;
		}
		endPos.clear();

		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			mat[a].push_back({ b,c });
			mat[b].push_back({ a,c });
		}

		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			endPos.push_back(a);
		}
		Dijkstra(s, Dist_s);
		Dijkstra(g, Dist_g);
		Dijkstra(h, Dist_h);
		sort(endPos.begin(), endPos.end());

		for (int i = 0; i < endPos.size(); i++)
		{
			int des = endPos[i];
			if (Dist_s[des] == Dist_s[g] + Dist_g[h] + Dist_h[des]) cout << des << " ";
			else if (Dist_s[des] == Dist_s[h] + Dist_g[h] + Dist_g[des]) cout << des << " ";
		}
		cout << "\n";


	}

	return 0;
}