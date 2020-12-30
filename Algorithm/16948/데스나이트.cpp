#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

constexpr int MAX_NUM = 201;

int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };

queue<pair<int, int>> q;
int dist[MAX_NUM][MAX_NUM];
int n;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	memset(dist, -1, sizeof(dist));

	int start, ed, r, c;
	cin >> start >> ed >> r >> c;

	q.push({ start,ed });
	dist[start][ed] = 0;

	while (!q.empty())
	{
		auto cur = q.front();		
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int xx = dx[i] + cur.first;
			int yy = dy[i] + cur.second;

			if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;

			if (dist[xx][yy] == -1) {
				dist[xx][yy] = dist[cur.first][cur.second] + 1;
				q.push({ xx,yy });
			}

		}

	}

	cout << dist[r][c] << "\n";

	return 0;
}