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
   �ڸ��� 4�� ������ ������ �ڸ����� �� ���ڵ��� �ϳ��� �ٲ㼭 ���ϴ� ���ڰ� �� ��
   ���� ��� �ٲ�� �ϴ����� �ּ� Ƚ�� (������ �Ҽ�) �� ���ϴ� ����

   �����佺�׳׽��� ü�� ���� ������ �Ҽ� �Ǻ� ��
   �ʺ�켱Ž���� ���� �ּ� Ƚ���� �����ش�.
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