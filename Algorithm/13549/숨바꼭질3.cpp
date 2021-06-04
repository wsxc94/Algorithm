#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

constexpr int MAX = 100001;
deque<pair<int, int>> q;
bool check[MAX] = { false, };

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	q.push_front({ n,0 });
	check[n] = true;

	while (!q.empty())
	{
		int curPos = q.front().first;
		int time = q.front().second;
		q.pop_front();

		if (curPos == m) {
			cout << time << "\n";
			break;
		}

		int right = curPos + 1;
		int left = curPos - 1;
		int teleport = curPos * 2;

		if (teleport < MAX && !check[teleport]) {
			check[teleport] = true;
			q.push_front({ teleport , time });
		}
		if (right < MAX && !check[right]) {
			check[right] = true;
			q.push_back({ right ,time + 1 });
		}
		if (left >= 0 && !check[left]) {
			check[left] = true;
			q.push_back({ left,time + 1 });
		}

	}
	return 0;
}