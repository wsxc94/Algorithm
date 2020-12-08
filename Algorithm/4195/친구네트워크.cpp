#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

int unf[200002];
int friendCnt[200002];

int Find(int v) {
	if (v == unf[v]) return unf[v];
	return unf[v] = Find(unf[v]);
}

int Union(int a,int b) {
	a = Find(a);
	b = Find(b);
	if (a < b) {
		unf[b] = a;
		friendCnt[a] += friendCnt[b];
		friendCnt[b] = 1;
		return friendCnt[a];
	}
	else if (a > b)
	{
		unf[a] = b;
		friendCnt[b] += friendCnt[a];
		friendCnt[a] = 1;
		return friendCnt[b];
	}
	return friendCnt[b];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t, n;
	string a, b;
	cin >> t;
	while (t--)
	{
		cin >> n;
		unordered_map<string, int> friends;
		int cnt = 1;

		for (int i = 0; i < 2*n; i++)
		{
			unf[i] = i;
			friendCnt[i] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			if (friends.count(a) == 0) {
				friends[a] = cnt;
				cnt++;
			}
			if (friends.count(b) == 0) {
				friends[b] = cnt;
				cnt++;
			}
			cout << Union(friends[a], friends[b]) << "\n";

		}
	}
	return 0;
}