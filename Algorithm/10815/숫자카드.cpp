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

constexpr int MAX_NUM = 10'000'000;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	/*unordered_map<int, int> maps;

	int n, m, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		maps[num]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (maps[num] > 0) cout << 1;
		else cout << 0;
		cout << " ";
	}*/
	vector<bool> ch;
	ch.reserve((MAX_NUM << 1) + 1);
	int n, m, num;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		ch[num + MAX_NUM] = true;
	}
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << ch[num + MAX_NUM] << " ";
	}

	return 0;
}