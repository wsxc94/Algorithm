#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int n, m;
void dfs(int cnt , vector<int>& select) {

	if (cnt == m) {

		for (int i = 0; i < m; i++) {
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		select[cnt] = num[i];
		dfs(cnt + 1 , select);
	}
}
int main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);

	cin >> n >> m;

	num.reserve(n + 1);
	vector<int> select(n+1 , 0);

	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	dfs(0 , select);

	return 0;
}