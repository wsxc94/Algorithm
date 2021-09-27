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
#include <set>
using namespace std;
/*
   https://www.acmicpc.net/problem/12761

   8가지의 경우의 수 배열을 만들어서 돌려준다.
*/

constexpr int MAX = 100001;
int a, b, n, m;
bool ch[MAX];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a >> b >> n >> m;

	queue<pair<int, int>> q;

	q.push({ n,0 });
	ch[n] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
	
		if (cur.first == m) {
			cout << cur.second << "\n";
			break;
		}
		int dir[8] = {
			cur.first + 1,
			cur.first - 1,
			cur.first + a,
			cur.first - a,
			cur.first + b,
			cur.first - b,
			cur.first * a,
			cur.first * b
		};

		for (int i = 0; i < 8; i++)
		{
			if (dir[i] >= 0 && dir[i] < MAX) {
				if (!ch[dir[i]]) {
					ch[dir[i]] = true;
					q.push({ dir[i] , cur.second + 1 });
				}
			}
		}
	}

	
	return 0;
}