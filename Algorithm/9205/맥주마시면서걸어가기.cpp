#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int mat[103][103];
bool ch[103];
vector<pair<int, int>> dist;
int n;
bool cmp = false;

void dfs(int x, int goal) {
	ch[x] = true;

	if (x == goal) cmp = true;

	for (int i = 0; i < n + 2; i++) {
		if (mat[x][i] == 1 && !ch[i]) dfs(i, goal);
	}
}

int getDistance(pair<int,int> a , pair<int,int> b) {

	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int beer = 20;
	int t;
	cin >> t;

	while (t--)
	{
		cin >> n;
		memset(mat, 0, sizeof(mat));
		memset(ch, false, sizeof(ch));
		dist.clear();
		cmp = false;
		for (int i = 0; i < n + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			dist.push_back({ x,y });
		}
		for (int i = 0; i < dist.size()-1; i++)
		{
			for (int j = 0; j < dist.size(); j++)
			{
				if (getDistance(dist[i], dist[j]) <= beer * 50) {
					mat[i][j] = 1;
				}
			}
		}

		dfs(0, n + 1);

		if (cmp) cout << "happy" << "\n";
		else cout << "sad" << "\n";

	}
	

	return 0;
}