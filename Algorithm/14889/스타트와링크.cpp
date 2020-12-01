#include <iostream>
#include <vector>
using namespace std;

int n, min_num = 999999999;
int mat[21][21];
bool ch[21] = { false, };

void dfs(int cnt , int idx) {
	
	if (cnt == n/2) {
		int start_score = 0, link_score = 0;
		vector<int> start, link;
		start.reserve(n + 1);
		link.reserve(n + 1);
		for (int i = 0; i < n; i++)
		{
			if (ch[i]) start.push_back(i);
			else link.push_back(i);
		}
		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < n/2; j++)
			{
				start_score += mat[start[i]][start[j]];
				link_score += mat[link[i]][link[j]];

			}
		}
		if (abs(start_score - link_score) < min_num)
			min_num = abs(start_score - link_score);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (ch[i]) continue;

		ch[i] = true;
		dfs(cnt + 1, i);
		ch[i] = false;
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	dfs(0, 0);

	cout << min_num << "\n";
	return 0;
}