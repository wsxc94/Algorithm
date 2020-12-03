#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, cnt = 0;
		cin >> n;
		vector<int> mat(n+1);
		vector<bool> ch(n+1, false);
		bool comp = false;

		for (int i = 1; i <= n; i++)
		{
			cin >> mat[i];
		}
		int idx = 1;
		while (!ch[idx])
		{
			ch[idx] = true;

			if (idx == n) {
				comp = true;
				break;
			}
			idx = mat[idx];
			cnt++;
		}
		if (comp) cout << cnt << "\n";
		else cout << 0 << "\n";
	}
	
	return 0;
}