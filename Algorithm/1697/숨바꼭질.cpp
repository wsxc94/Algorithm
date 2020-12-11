#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;


queue<pair<int, int>> q;
bool check[100010] = { false, };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	q.push({ n,0 });
	check[n] = true;

	int ans = 0;
	while (!q.empty())
	{
		int curPos = q.front().first;
		int time = q.front().second;
		q.pop();

		if (curPos == m) {
			ans = time;
			break;
		}

		int right = curPos + 1;
		int left = curPos - 1;
		int teleport = curPos * 2;

		if (right <= m && !check[right]) {
			check[right] = true;
			q.push({ right ,time + 1 });
		}
		if (left >= 0 && !check[left]) {
			check[left] = true;
			q.push({ left,time + 1 });
		}
		if (teleport <= m + 1 && !check[teleport]) {
			check[teleport] = true;
			q.push({ teleport , time + 1 });
		}

	}
	cout << ans << "\n";
	return 0;
}