#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
bool ch[101] = { false, };

int n, m;
void dfs(int idx , int cnt) {

	if (cnt == m) {
		for (int i = 0; i < num.size(); i++)
		{
			if (ch[i]) cout << num[i] << " ";
		}
		cout << "\n";
	}
	for (int i = idx; i < n; i++)
	{
		if (ch[i]) continue;
		
		ch[i] = true;
		dfs(i, cnt + 1);
		ch[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	num.reserve(n + 1);
	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	dfs(0, 0);

	return 0;
}