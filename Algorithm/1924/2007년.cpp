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

	vector<string> day={ "SUN", "MON","TUE","WED","THU","FRI","SAT" };
	vector<int> mon = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int x, y, cnt = 0;
	cin >> x >> y;

	for (int i = 1; i <= x; i++)
	{
		if (i == x) cnt += y;
		else cnt += mon[i-1];
	}
	cout << day[cnt % 7];

	return 0;
}