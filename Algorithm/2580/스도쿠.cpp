#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

constexpr int n = 9;

int mat[n][n] = { 0, };

vector<pair<int, int>> blank;

int cnt = 0;
bool complete = false;

bool check(pair<int,int> b) {
	int div_y = b.first / 3;
	int div_x = b.second / 3;

	for (int i = 0; i < n; i++)
	{
		if (mat[b.first][i] == mat[b.first][b.second] && i != b.second)
		{
			return false;
		}
		if (mat[i][b.second] == mat[b.first][b.second] && i != b.first)
		{
			return false;
		}
	}

	for (int i = 3 * div_y; i < 3 * div_y + 3; i++)
	{
		for (int j = 3 * div_x; j < 3 * div_x + 3; j++)
		{
			if (mat[i][j] == mat[b.first][b.second]) {
				if (i != b.first && j != b.second) return false;
			}
		}
	}
	return true;
}
void dfs(int n) {

	if (n == cnt) { 
		complete = true;
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		mat[blank[n].first][blank[n].second] = i;
		if (check(blank[n])) dfs(n + 1);
		if (complete) return;

	}
	mat[blank[n].first][blank[n].second] = 0;
}

int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++){

			cin >> mat[i][j];
			if (mat[i][j] == 0) {
				cnt++;
				blank.push_back({ i,j });
			}
		}
	}

	dfs(0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {

			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}