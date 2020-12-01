#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int mat[21][21];

vector<int> start, link;

int dfs(int idx , int start_score , int link_score){

	if (idx == n) return abs(start_score - link_score);
	
	int ans = 999999999;
	if (start.size() != n / 2)
	{
		start.push_back(idx);
		int score = start_score;
		for (int i : start) score += mat[i][idx] + mat[idx][i];
		ans = min(ans, dfs(idx + 1, score, link_score));
		start.pop_back();
	}
	if (link.size() != n / 2)
	{
		link.push_back(idx);
		int score = link_score;
		for (int i : link) score += mat[i][idx] + mat[idx][i];
		ans = min(ans, dfs(idx + 1, start_score, score));
		link.pop_back();
	}

	return ans;

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

	cout << dfs(0, 0, 0);

	return 0;
}