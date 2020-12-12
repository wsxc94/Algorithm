#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, ans = 987654321;
int mat[51][51];
bool check[51] = { false, };
vector<pair<int, int>> house, bbq, v_find;

int dist() {
	int sum = 0;

	for (int i = 0; i < house.size(); i++)
	{
		int x = house[i].first;
		int y = house[i].second;
		int d = 987654321;
		for (int j = 0; j < v_find.size(); j++)
		{
			int bx = v_find[j].first;
			int by = v_find[j].second;

			int tmp = abs(bx - x) + abs(by - y);
			d = min(d, tmp);
		}
		
		sum += d;
	}
	return sum;
}

void dfs(int v, int cnt) {
	if (cnt == m) {
		ans = min(ans, dist());
		return;
	}

	for (int i = v; i < bbq.size(); i++)
	{
		if (check[i]) continue;
		check[i] = true;
		v_find.push_back(bbq[i]);
		dfs(i, cnt + 1);
		check[i] = false;
		v_find.pop_back();

	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;
			mat[i][j] = tmp;
			if (tmp == 1) house.push_back({ i, j });
			else if (tmp == 2) bbq.push_back({ i,j });

		}
	}

	dfs(0, 0);
	cout << ans << "\n";
	return 0;
}