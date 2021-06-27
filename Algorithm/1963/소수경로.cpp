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
/*
   자리수 4인 정수를 가지고 자리수의 각 숫자들을 하나씩 바꿔서 원하는 숫자가 될 때
   까지 몇번 바꿔야 하는지의 최소 횟수 (무조건 소수) 를 구하는 문제

   에라토스테네스의 체를 통해 빠르게 소수 판별 후
   너비우선탐색을 통해 최소 횟수를 구해준다.
*/
constexpr int MAX = 10000;
bool primeNum[MAX];
bool check[MAX];
int start, ed;

void primeNumberCheck() {
	memset(primeNum, true, sizeof(primeNum));
	memset(check, false, sizeof(check));

	for (int i = 2; i < MAX; i++)
	{
		for (int j = 2; i*j < MAX; j++)
		{
			primeNum[i*j] = false;
		}
	}
}
void BFS() {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	check[start] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == ed) {
			cout << cur.second << "\n";
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int next;
			for (int j = 0; j < 10; j++)
			{
				string s = to_string(cur.first);
				s[i] = j + '0';
				next = stoi(s);
				if (!primeNum[next] || check[next]) continue;
				if (next >= 10000 || next < 1000) continue;

				check[next] = true;
				q.push({ next , cur.second + 1 });
			}
		}
	}
	cout << "Impossible" << "\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		primeNumberCheck();
		cin >> start >> ed;
		BFS();
	}
	

	return 0;
}