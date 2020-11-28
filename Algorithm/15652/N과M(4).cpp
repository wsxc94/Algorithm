#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<int> num;

void dfs(int idx, int cnt, vector<int>& select) {

	if (cnt == m) {

		for (int i = 0; i < m; i++)
		{
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++)
	{
		select[cnt] = num[i];

		dfs(i, cnt + 1, select);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;

	num.reserve(n + 1);

	vector<int> select(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		num.push_back(i);
	}

	dfs(0, 0, select);
	
	return 0;
}